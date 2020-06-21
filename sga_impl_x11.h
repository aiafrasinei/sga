#ifndef sga_impl_x11_h_
#define sga_impl_x11_h_

#include "sga_version.h"
#include "sga_coord.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>


struct sga_ctx;

/*start*/
struct sga_ctx *sga_start();
void sga_init(struct sga_ctx *ctx, Display *dis, Window win, GC gc);

/*simple*/
void sga_point(struct sga_ctx *ctx, int x, int y);

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1);

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height);

/*colors*/
void sga_color(struct sga_ctx *ctx, int r, int g, int b, int a);

/*end*/
void sga_end(struct sga_ctx *ctx);

#endif