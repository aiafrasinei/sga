#include <stdlib.h>
#include "sga_impl_sdl3.h"



struct sga_ctx {
    SDL_Renderer *renderer;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_init(struct sga_ctx *ctx, SDL_Renderer *grenderer)
{
    ctx->renderer = grenderer;
}

void sga_point(struct sga_ctx *ctx, float x, float y)
{
    SDL_RenderPoint(ctx->renderer, x, y);
}

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    SDL_RenderLine(ctx->renderer, x0, y0, x1, y1);
}

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderRect(ctx->renderer, &rect);
}

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRect(ctx->renderer, &rect);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    SDL_SetRenderDrawColor(ctx->renderer, r, g, b, 255);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
