#include "sga_impl_sdl1.h"

struct sga_ctx *sctx = NULL;
SDL_Surface *screen;

int init()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	const int WIDTH = 1024;
	const int HEIGHT = 768;

    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_SWSURFACE);
	if(screen == 0)
	{
		printf("Failed to set video mode\n");
		return 1;
	}
	SDL_WM_SetCaption("sga sdl1 example", NULL);

	return 0;
}

int start()
{
	sctx = sga_start();
	sga_init(sctx, screen);

	return 1;
}

void end()
{
	SDL_Quit();
	sga_end(sctx);
}

int main(int argc, char * argv[])
{
	init();
	start();

	SDL_Event event;
	int running = 1;
	
	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			running = event.type != SDL_QUIT;
		}
		
		sga_color(sctx, 255, 255, 255);
		sga_point(sctx, 50, 50);

		sga_line(sctx, 130, 50, 100.332f, 200.0f);

		sga_color(sctx, 240, 0, 0);
		sga_rect(sctx, 60, 60, 20, 20);

        sga_fill_rect(sctx, 160, 60, 30, 30);

        if( SDL_Flip(screen) == -1 )
        {
            return 1;    
        }
	}
	
	end();
	
    return 0;
}