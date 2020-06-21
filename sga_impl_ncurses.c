#include <stdlib.h>
#include "sga_impl_ncurses.h"



struct sga_ctx {
    char drawc;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->drawc = '*';
    
    return ctx;
}

void sga_set_drawchar(struct sga_ctx *ctx, char drawchar)
{
    ctx->drawc = drawchar;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    mvaddch(y, x, ctx->drawc);
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    move(y0, x0);
    if (y0 == y1) {
        hline(ctx->drawc, abs(x0-x1));
    } else if(x0 == y0) {
        vline(ctx->drawc, abs(y0-y1));
    }
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    mvvline(y, x, ctx->drawc, height);
    mvvline(y, x + width * 2 - 2 , ctx->drawc, height);
    mvhline(y, x + 1, ctx->drawc, width * 2 - 2);
    mvhline(y + height - 1, x + 1, ctx->drawc, width * 2 - 2);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    for (int i=0; i <= width*2-2; i++) {
        mvvline(y, x+i, ctx->drawc, height);
    }
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}