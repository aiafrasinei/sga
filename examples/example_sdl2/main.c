#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>

#include "sga_impl_sdl2_opengl2.h"


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Rect tex_rect;

struct sga_ctx *sctx = NULL;

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
	sctx = sga_start();
	sga_init(sctx, gRenderer);

	return 1;
}

void stop()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
	sga_end(sctx);
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
		sga_point(sctx, 50, 50);

		sga_line_f(sctx, 50, 50, 100.332f, 200.0f);

		sga_color(sctx, 240, 0, 0, 255);
		sga_rect(sctx, 60, 60, 20, 20);

		sga_fill_rect(sctx, 160, 60, 30, 30);

		SDL_RenderPresent(gRenderer);
	}

    stop();

    return 0;
}
