#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <stdio.h>
#include <stdlib.h>

#include "sga_impl_x11.h"


Display *dis;
int screen;
Window win;
GC gc;

struct sga_ctx *sctx = NULL;

void init() {      
	unsigned long black,white;

	dis=XOpenDisplay((char *)0);
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen),
	white=WhitePixel(dis, screen);

	const int WIDTH = 1024;
	const int HEIGHT = 768;

   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	
		WIDTH, HEIGHT, 5, white, black);
	XSetStandardProperties(dis,win,"sga_example_x11","sga_example_x11",None,NULL,0,NULL);
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);
    	gc=XCreateGC(dis, win, 0,0);        
	XSetBackground(dis,gc,black);
	XSetForeground(dis,gc,white);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

void redraw() {
	XClearWindow(dis, win);
};


int main(int argc, char *argv[]) {
	XEvent event;

	init();
	sctx = sga_start();
	sga_init(sctx, dis, win, gc);

	while(1) {
		sga_color(sctx, 255, 255, 255);
		sga_point(sctx, 50, 50);

		sga_line(sctx, 130, 50, 100.332f, 200.0f);

		sga_color(sctx, 240, 0, 0);
		sga_rect(sctx, 60, 60, 20, 20);

		sga_fill_rect(sctx, 160, 60, 30, 30);
		
		XNextEvent(dis, &event);
	
		if (event.type==Expose && event.xexpose.count==0) {
			redraw();
		}
	}

	sga_end(sctx);
	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);
	exit(1);
}
