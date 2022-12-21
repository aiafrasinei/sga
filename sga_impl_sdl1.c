#include <stdlib.h>
#include <math.h>

#include "sga_impl_sdl1.h"



struct sga_ctx {
    SDL_Surface *screen;
    Uint32 color;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_init(struct sga_ctx *ctx, SDL_Surface *screen)
{
    ctx->screen = screen;
}

static void put_point(struct sga_ctx *ctx, int x, int y) {
    int bpp = ctx->screen->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)ctx->screen->pixels + y * ctx->screen->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = ctx->color;
        break;

    case 2:
        *(Uint16 *)p = ctx->color;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (ctx->color >> 16) & 0xff;
            p[1] = (ctx->color >> 8) & 0xff;
            p[2] = ctx->color & 0xff;
        } else {
            p[0] = ctx->color & 0xff;
            p[1] = (ctx->color >> 8) & 0xff;
            p[2] = (ctx->color >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = ctx->color;
        break;
    }
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
	if (SDL_MUSTLOCK(ctx->screen)) {
		SDL_LockSurface(ctx->screen);
	}

    put_point(ctx, x, y);

	if (SDL_MUSTLOCK(ctx->screen)) {
		SDL_UnlockSurface(ctx->screen);
	}
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    if (SDL_MUSTLOCK(ctx->screen)) {
		SDL_LockSurface(ctx->screen);
	}

    int i;
    double x = x1 - x0; 
	double y = y1 - y0; 
	double length = sqrt( x*x + y*y ); 
	double addx = x / length; 
	double addy = y / length; 
	x = x0; 
	y = y0; 
	
	for ( i = 0; i < length; i += 1) { 
		put_point(ctx, x, y); 
		x += addx; 
		y += addy; 
		
	} 

    if (SDL_MUSTLOCK(ctx->screen)) {
		SDL_UnlockSurface(ctx->screen);
	}
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SDL_Rect rect = {x, y, width, height};
    SDL_FillRect(ctx->screen, &rect, ctx->color);

    SDL_Rect clear_rect = {x+1, y+1, width-2, height-2};
    SDL_FillRect(ctx->screen, &clear_rect, SDL_MapRGB(ctx->screen->format, 0, 0, 0));
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SDL_Rect rect = { x, y, width, height };
    SDL_FillRect(ctx->screen, &rect, ctx->color);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    ctx->color = SDL_MapRGB(ctx->screen->format, r, g, b);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
