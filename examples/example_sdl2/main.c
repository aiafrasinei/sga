#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>

#include "sga_impl_sdl2.h"


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Rect tex_rect;

struct sga_ctx *dctx = NULL;

int init()
{
    int success = 1;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = 0;
	}
	else
	{
		if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		gWindow = SDL_CreateWindow("sga sdl2 example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
		if( gWindow == NULL )
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = 0;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if(gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = 0;
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
			}
		}
	}

	return success;
}

int start()
{
	dctx = sga_start();
	sga_init(dctx, gRenderer);

	return 1;
}

void stop()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
	sga_end(dctx);
}

int main(int argc, const char *argv[])
{
	int loop = 0;

    init();   
    start();

	SDL_Event e;
	while(!loop)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				return 0;
			}
		}

		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
		SDL_RenderClear(gRenderer);

		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
		sga_point(dctx, 50, 50);

		sga_rect(dctx, 60, 60, 20, 20);

		SDL_RenderPresent(gRenderer);
	}

    stop();

    return 0;
}
