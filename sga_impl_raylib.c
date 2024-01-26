#include <stdlib.h>
#include "sga_impl_raylib.h"


struct sga_ctx {
    Color color;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    ctx->color = (Color){ 255, 255, 255, 255 };
    
    return ctx;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    DrawPixel(x, y, ctx->color);
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    DrawLine(x0, y0, x1, y1, ctx->color);
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    DrawRectangle(x, y, width, height, ctx->color);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    DrawRectangleLines(x, y, width, height, ctx->color);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    ctx->color = (Color){ r, g, b, 255 };
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
