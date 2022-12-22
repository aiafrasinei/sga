#include <stdlib.h>
#include "sga_impl_sdl2_cairo.h"



struct sga_ctx {
    SDL_Renderer *renderer;
    SDL_Color current;
    cairo_t *cr;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_init(struct sga_ctx *ctx, SDL_Renderer *grenderer, cairo_t *cr)
{
    ctx->renderer = grenderer;
    ctx->cr = cr;
}

void sga_point(struct sga_ctx *ctx, float x, float y)
{
    cairo_move_to (ctx->cr, x, y);
    cairo_line_to (ctx->cr, x+1, y+1);
	
	cairo_stroke (ctx->cr);
}

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    cairo_move_to(ctx->cr, x0, y0);
    cairo_line_to(ctx->cr, x1, y1);
    
	cairo_stroke (ctx->cr);
}

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    cairo_set_line_width (ctx->cr, 1);
    cairo_set_source_rgb (ctx->cr, ctx->current.r, ctx->current.g, ctx->current.b);
    cairo_rectangle (ctx->cr, x, y, width, height);
    cairo_stroke (ctx->cr);
}

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    cairo_rectangle(ctx->cr, x, y, width, height);
    cairo_fill(ctx->cr);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    cairo_set_source_rgba(ctx->cr, r, g, b, 1.0);
    SDL_Color a = {r, g, b, 1.0};
    ctx->current = a;
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
