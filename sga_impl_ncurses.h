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

void sga_point_f(struct sga_ctx *ctx, float x, float y);

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1);

void sga_line_f(struct sga_ctx *ctx, float x0, float y0, float x1, float y1);

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

void sga_rect_f(struct sga_ctx *ctx, float x, float y, float width, float height);

/*cursor*/
void sga_curs_to(struct sga_ctx *ctx, int x, int y);

void sga_curs_point(struct sga_ctx *ctx);

void sga_curs_point_f(struct sga_ctx *ctx);

void sga_curs_line(struct sga_ctx *ctx, int x, int y);

void sga_curs_rect(struct sga_ctx *ctx, int width, int height);

/*specific*/
void sga_set_drawchar(struct sga_ctx *ctx, char drawchar);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif