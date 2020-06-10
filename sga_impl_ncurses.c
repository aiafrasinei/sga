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
    
}

void sga_curs_rect(struct sga_ctx *ctx, int width, int height)
{
    
    
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    mvaddch(y, x, ctx->drawc);
}

void sga_point_f(struct sga_ctx *ctx, float x, float y)
{
    
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    
}

void sga_line_f(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    
}

void sga_draw_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
{

}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}