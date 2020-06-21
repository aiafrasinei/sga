#include <stdlib.h>
#include "sga_impl_sdl2.h"



struct sga_ctx {
    SDL_Renderer *renderer;
    int cursx,cursy;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->cursx = 0;
    ctx->cursy = 0;

    return ctx;
}

void sga_init(struct sga_ctx *context, SDL_Renderer *grenderer)
{
    context->renderer = grenderer;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    SDL_RenderDrawPoint(ctx->renderer, x, y);
}

void sga_point_f(struct sga_ctx *ctx, float x, float y)
{
    SDL_RenderDrawPointF(ctx->renderer, x, y);
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    SDL_RenderDrawLine(ctx->renderer, x0, y0, x1, y1);
}

void sga_line_f(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    SDL_RenderDrawLineF(ctx->renderer, x0, y0, x1, y1);
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderDrawRect(ctx->renderer, &rect);
}

void sga_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderDrawRectF(ctx->renderer, &rect);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(ctx->renderer, &rect);
}

void sga_fill_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderFillRectF(ctx->renderer, &rect);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(ctx->renderer, r, g, b, a);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
