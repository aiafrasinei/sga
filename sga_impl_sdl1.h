#ifndef sga_impl_sdl1_h_
#define sga_impl_sdl1_h_

#ifdef __APPLE__
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include "sga_version.h"
#include "sga_coord.h"


struct sga_ctx;

/*start*/
struct sga_ctx * sga_start();
void sga_init(struct sga_ctx *ctx, SDL_Surface *screen);

/*simple*/
void sga_point(struct sga_ctx *ctx, int x, int y);

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1);

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

/*colors*/
void sga_color(struct sga_ctx *ctx, int r, int g, int b);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif
