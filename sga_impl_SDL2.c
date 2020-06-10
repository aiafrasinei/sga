#include <stdlib.h>
#include "sga_impl_SDL2.h"



struct sga_ctx {
    SDL_Renderer *renderer;
    int cursx,cursy;
};


struct sga_ctx *sga_start()
{
    ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->cursx = 0;
    ctx->cursy = 0;

    return ctx;
}

void sga_init(struct sga_ctx *context, SDL_Renderer *grenderer)
{
    context->renderer = grenderer;
}

void sga_curs_to(struct sga_ctx *ctx, int x, int y)
{
    ctx->cursx = x;
    ctx->cursy = y;
}

void sga_curs_point(struct sga_ctx *ctx)
{
    SDL_RenderDrawPoint(ctx->renderer, ctx->cursx, ctx->cursy);
}

void sga_curs_line(struct sga_ctx *ctx, int x, int y)
{
    SDL_RenderDrawLine(ctx->renderer, ctx->cursx, ctx->cursy, x, y);
}

void sga_curs_rect(struct sga_ctx *ctx, int width, int height)
{
    SDL_Rect rect = {ctx->cursx, ctx->cursy, width, height};
    SDL_RenderDrawRect(ctx->renderer, &rect);
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

void sga_draw_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    SDL_FRect rect = {x, y, width, height};
    SDL_RenderDrawRectF(ctx->renderer, &rect);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}