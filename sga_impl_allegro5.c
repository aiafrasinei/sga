#include <stdlib.h>
#include "sga_impl_allegro5.h"


struct sga_ctx {
    int r, g, b;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->r = 255;
    ctx->g = 255;
    ctx->b = 255;

    return ctx;
}


void sga_point(struct sga_ctx *ctx, float x, float y)
{
    al_draw_pixel(x, y, al_map_rgb(ctx->r,ctx->g,ctx->b));
}

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    al_draw_line(x0, y0, x1, y1, al_map_rgb(ctx->r,ctx->g,ctx->b), 1);
}

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    al_draw_rectangle(x, y, width, height, al_map_rgb(ctx->r,ctx->g,ctx->b), 1);
}

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    al_draw_filled_rectangle(x, y, width, height, al_map_rgb(ctx->r,ctx->g,ctx->b));
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    ctx->r = r;
    ctx->g = g;
    ctx->b = b;
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
