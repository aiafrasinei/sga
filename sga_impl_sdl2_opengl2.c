#include <stdlib.h>
#include "sga_impl_sdl2_opengl2.h"


struct sga_ctx {
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_point(struct sga_ctx *ctx, float x, float y)
{
    glBegin(GL_POINTS);
        glVertex3f(x, y, 0);
    glEnd();
}

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    glBegin(GL_LINES);
        glVertex3f(x0, y0, 0);
        glVertex3f(x1, y1, 0);
    glEnd();
}

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    glBegin(GL_LINES);
        glVertex3f(x, y, 0);
        glVertex3f(x + width, y, 0);
        glVertex3f(x + width, y + height, 0);
        glVertex3f(x, y + height, 0);
        glVertex3f(x, y, 0);
        glVertex3f(x, y + height, 0);
        glVertex3f(x + width, y, 0);
        glVertex3f(y + width , y + height, 0);
    glEnd();
}

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    glBegin(GL_QUADS);
        glVertex3f(x, y, 0);
        glVertex3f(x + width, y, 0);
        glVertex3f(x + width, y + height, 0);
        glVertex3f(x, y + height, 0);
    glEnd();
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    glColor3f(r, g, b);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
