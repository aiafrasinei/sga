#include <stdlib.h>
#include "sga_impl_sdl2.h"
#include <SDL_opengl.h>


struct sga_ctx {
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    glBegin(GL_POINTS);
        glVertex3i(x, y, 0);
    glEnd();
}

void sga_point_f(struct sga_ctx *ctx, float x, float y)
{
    glBegin(GL_POINTS);
        glVertex3f(x, y, 0);
    glEnd();
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    glBegin(GL_LINES);
        glVertex3i(x0, y0, 0);
        glVertex3i(x1, y1, 0);
    glEnd();
}

void sga_line_f(struct sga_ctx *ctx, float x0, float y0, float x1, float y1)
{
    glBegin(GL_LINES);
        glVertex3f(x0, y0, 0);
        glVertex3f(x1, y1, 0);
    glEnd();
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    glBegin(GL_LINES);
        glVertex3i(x, y, 0);
        glVertex3i(x + width, y, 0);
        glVertex3i(x + width, y + height, 0);
        glVertex3i(x, y + height, 0);
        glVertex3i(x, y, 0);
        glVertex3i(x, y + height, 0);
        glVertex3i(x + width, y, 0);
        glVertex3i(y + width , y + height, 0);
    glEnd();
}

void sga_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
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

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    glBegin(GL_QUADS);
        glVertex3i(x, y, 0);
        glVertex3i(x + width, y, 0);
        glVertex3i(x + width, y + height, 0);
        glVertex3i(x, y + height, 0);
    glEnd();
}

void sga_fill_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height)
{
    glBegin(GL_QUADS);
        glVertex3f(x, y, 0);
        glVertex3f(x + width, y, 0);
        glVertex3f(x + width, y + height, 0);
        glVertex3f(x, y + height, 0);
    glEnd();
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b, int a)
{
    glColor3f(r, g, b);
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
