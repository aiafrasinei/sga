#define SDL_MAIN_HANDLED
#define GL_GLEXT_PROTOTYPES

#include "sga_impl_sdl2_opengl2.h"
#include <stdio.h>

const int width = 1024;
const int height = 768;

struct sga_ctx *sctx = NULL;

void init_gl()
{
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0f);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
}

int start()
{
	sctx = sga_start();
    init_gl();

	return 1;
}

int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window * window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    start();

    for(;;)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_KEYUP:
                    if(event.key.keysym.sym == SDLK_ESCAPE)
                        return 0;
                    break;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
    
        sga_point(sctx, 100, 100);
        
        sga_color(sctx, 255, 0, 0);
        sga_line(sctx, 150, 100, 300, 300);

        sga_color(sctx, 255, 255, 255);
        sga_fill_rect(sctx, 200, 200, 20, 20);

        sga_rect(sctx, 50, 50, 30, 30);

        SDL_GL_SwapWindow(window);
        SDL_Delay(1);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    sga_end(sctx);

    return 0;
}