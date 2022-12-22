#include <stdio.h>
#include <stdbool.h>

#include "sga_impl_sdl2_cairo.h"


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface *sdl_surface = NULL;
SDL_Texture *texture = NULL;
cairo_t *cr = NULL;
cairo_surface_t *cr_surface = NULL;

struct sga_ctx *sctx = NULL;

int init()
{
    SDL_Init(SDL_INIT_VIDEO);

    const int WIDTH = 1024;
	const int HEIGHT = 768;

    gWindow = SDL_CreateWindow("sga_example_sdl2_cairo",
                                            SDL_WINDOWPOS_UNDEFINED,
                                            SDL_WINDOWPOS_UNDEFINED,
                                            WIDTH,
                                            HEIGHT,
                                            SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);

    gRenderer = SDL_CreateRenderer(gWindow,
                                        -1,
                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int window_width;
    int window_height;
    SDL_GetWindowSize(gWindow, &window_width, &window_height);

    int renderer_width;
    int renderer_height;
    SDL_GetRendererOutputSize(gRenderer, &renderer_width, &renderer_height);

    int cairo_x_multiplier = renderer_width / window_width;
    int cairo_y_multiplier = renderer_height / window_height;

    sdl_surface = SDL_CreateRGBSurface(0,
                                        renderer_width,
                                        renderer_height,
                                        32,
                                        0x00ff0000,
                                        0x0000ff00,
                                        0x000000ff,
                                        0);

    cr_surface = cairo_image_surface_create_for_data((unsigned char *)sdl_surface->pixels,
                                                                        CAIRO_FORMAT_RGB24,
                                                                        sdl_surface->w,
                                                                        sdl_surface->h,
                                                                        sdl_surface->pitch);

    cairo_surface_set_device_scale(cr_surface, cairo_x_multiplier, cairo_y_multiplier);

    cr = cairo_create(cr_surface);

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);
}

int start()
{
	sctx = sga_start();
	sga_init(sctx, gRenderer, cr);

	return 1;
}

void end()
{
	cairo_destroy(cr);
    cairo_surface_destroy(cr_surface);

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    SDL_Quit();
	sga_end(sctx);
}

int main(int argc, char *argv[])
{
    init();
    start();

    sga_color(sctx, 255, 255, 255);
    sga_point(sctx, 50, 50);

    sga_line(sctx, 130, 50, 100.332f, 200.0f);

    sga_color(sctx, 240, 0, 0);
    sga_rect(sctx, 60, 60, 20, 20);

    sga_fill_rect(sctx, 160, 60, 30, 30);

    texture = SDL_CreateTextureFromSurface(gRenderer, sdl_surface);
    SDL_FreeSurface(sdl_surface);

    SDL_RenderCopy(gRenderer, texture, NULL, NULL);
    SDL_RenderPresent(gRenderer);

    bool done = false;
    while (!done) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    done = true;
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(100);
    }

    end();

    return 0;
}