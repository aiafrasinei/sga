#include <stdlib.h>
#include "sga_impl_x11.h"


struct sga_ctx {
    Display *dis;
    Window win;
    GC gc;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    
    return ctx;
}

void sga_init(struct sga_ctx *ctx, Display *dis, Window win, GC gc)
{
    ctx->dis = dis;
    ctx->win = win;
    ctx->gc = gc;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    XDrawPoint(ctx->dis, ctx->win, ctx->gc, x, y);
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    XDrawLine(ctx->dis, ctx->win, ctx->gc, x0, y0, x1, y1); 
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    XDrawRectangle(ctx->dis, ctx->win, ctx->gc, x, y, width, height); 
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    XFillRectangle(ctx->dis, ctx->win, ctx->gc, x, y, width, height); 
}


void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}