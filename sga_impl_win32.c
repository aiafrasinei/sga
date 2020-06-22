#include <stdlib.h>
#include "sga_impl_win32.h"


struct sga_ctx {
    HDC hdc;
    int r,g,b;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));
    
    return ctx;
}

void sga_init(struct sga_ctx *ctx, HDC hdc)
{
    ctx->hdc = hdc;
    ctx->r = 255;
    ctx->g = 255;
    ctx->b = 255;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    SetPixel(ctx->hdc, x, y, RGB(ctx->r, ctx->g, ctx->b));
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    SelectObject(ctx->hdc, GetStockObject(DC_PEN));
    SetDCPenColor(ctx->hdc, RGB(ctx->r, ctx->g, ctx->b));
    MoveToEx(ctx->hdc, x0, y0, NULL);
    LineTo(ctx->hdc, x1, y1);
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SelectObject(ctx->hdc, GetStockObject(NULL_BRUSH));
    SelectObject(ctx->hdc, GetStockObject(DC_PEN));
    SetDCPenColor(ctx->hdc, RGB(ctx->r, ctx->g, ctx->b));
    
    Rectangle(ctx->hdc, x, y, x + width, y + height);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    SelectObject(ctx->hdc, GetStockObject(DC_PEN));
    SetDCPenColor(ctx->hdc, RGB(ctx->r,ctx->g, ctx->b));

    RECT rc;
    rc.left = x;
    rc.right = x +width;
    rc.top = y;
    rc.bottom = y + height;

    HBRUSH hBsh = CreateSolidBrush(RGB(ctx->r, ctx->g, ctx->b));
    FillRect(ctx->hdc, &rc, hBsh);
    DeleteObject(hBsh);

    SelectObject(ctx->hdc, GetStockObject(NULL_BRUSH));
    Rectangle(ctx->hdc, x, y, x+width, y+height);
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
