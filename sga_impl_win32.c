#include <stdlib.h>
#include "sga_impl_win32.h"


struct sga_ctx {
    HDC hdc;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_init(struct sga_ctx *ctx, HDC hdc)
{
    ctx->hdc = hdc;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    SetPixel(ctx->hdc, x, y, RGB(255, 255, 255));
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    SelectObject(ctx->hdc, GetStockObject(DC_PEN));
    SetDCPenColor(ctx->hdc, RGB(255, 255, 255));
    MoveToEx(ctx->hdc, x0, y0, NULL);
    LineTo(ctx->hdc, x1, y1);
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SelectObject(ctx->hdc, GetStockObject(NULL_BRUSH));
    Rectangle(ctx->hdc, x, y, x + width, y + height);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    Rectangle(ctx->hdc, x, y, x+width, y+height);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b, int a)
{

}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
