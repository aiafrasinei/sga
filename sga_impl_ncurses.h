#ifndef sga_impl_ncurses_h_
#define sga_impl_ncurses_h_

#include <ncurses.h>
#include "sga_version.h"
#include "sga_coord.h"


struct sga_ctx;

/*start*/
struct sga_ctx *sga_start();

/*simple*/
void sga_point(struct sga_ctx *ctx, int x, int y);

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1);

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

/*colors*/
void sga_color(struct sga_ctx *ctx, int color);
void sga_color_fb(struct sga_ctx *ctx, int fgcolor, int bkcolor);

/*specific*/
void sga_set_drawchar(struct sga_ctx *ctx, char drawchar);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif