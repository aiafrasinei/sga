#include <stdlib.h>
#include "sga_impl_ncurses.h"



struct sga_ctx {
    char drawc;
    int cursx,cursy;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->drawc = '*';
    ctx->cursx = 0;
    ctx->cursy = 0;

    return ctx;
}

void sga_set_drawchar(struct sga_ctx *ctx, char drawchar)
{
    ctx->drawc = drawchar;
}

void sga_curs_to(struct sga_ctx *ctx, int x, int y)
{
    ctx->cursx = x;
    ctx->cursy = y;
    move(ctx->cursy, ctx->cursx);
}

void sga_curs_point(struct sga_ctx *ctx)
{
    addch(ctx->drawc);
}

void sga_curs_line(struct sga_ctx *ctx, int x, int y)
{
    move(ctx->cursy, ctx->cursx);
    if (ctx->cursy == y) {
        hline(ctx->drawc, abs(x - ctx->cursx));
    } else if(ctx->cursx == x) {
        vline(ctx->drawc, abs(y - ctx->cursy));
    }
}

void sga_curs_rect(struct sga_ctx *ctx, int width, int height)
{
    mvvline(ctx->cursy, ctx->cursx, ctx->drawc, height);
    mvvline(ctx->cursy, ctx->cursx + width * 2 - 2 , ctx->drawc, height);
    mvhline(ctx->cursy, ctx->cursx + 1, ctx->drawc, width * 2 - 2);
    mvhline(ctx->cursy + height - 1, ctx->cursx + 1, ctx->drawc, width * 2 - 2);
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

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}