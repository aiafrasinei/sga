#ifndef sga_impl_sdl2_h_
#define sga_impl_sdl2_h_

#include <SDL2/SDL.h>
#include "sga_version.h"
#include "sga_coord.h"


struct sga_ctx;

/*start*/
struct sga_ctx * sga_start();
void sga_init(struct sga_ctx *ctx, SDL_Renderer *grenderer);

/*simple*/
void sga_point(struct sga_ctx *ctx, float x, float y);

void sga_line(struct sga_ctx *ctx, float x0, float y0, float x1, float y1);

void sga_rect(struct sga_ctx *ctx, float x, float y, float width, float height);

void sga_fill_rect(struct sga_ctx *ctx, float x, float y, float width, float height);

/*colors*/
void sga_color(struct sga_ctx *ctx, int r, int g, int b, int a);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif
