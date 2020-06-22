#ifndef sga_impl_allegro5_h_
#define sga_impl_allegro5_h_

#include "sga_version.h"
#include "sga_coord.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


struct sga_ctx;

/*start*/
struct sga_ctx * sga_start();

/*simple*/
void sga_point(struct sga_ctx *ctx, float x, float y);

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1);

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height);

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height);

/*colors*/
void sga_color(struct sga_ctx *ctx, int r, int g, int b);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif
