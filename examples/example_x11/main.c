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

struct sga_ctx *dctx = NULL;

void init_x();
void close_x();
void redraw();

int main () {
	XEvent event;

	init_x();
	dctx = sga_start();
	sga_init(dctx, dis, win, gc);

	while(1) {
        sga_line(dctx, 50, 100, 200,200);
		sga_point(dctx, 120, 120);
		sga_rect(dctx, 70, 70, 30, 30);
		
		XNextEvent(dis, &event);
	
		if (event.type==Expose && event.xexpose.count==0) {
			redraw();
		}
	}
}

void init_x() {      
	unsigned long black,white;

	dis=XOpenDisplay((char *)0);
   	screen=DefaultScreen(dis);
	black=BlackPixel(dis,screen),
	white=WhitePixel(dis, screen);
   	win=XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,	
		1024, 768, 5, white, black);
	XSetStandardProperties(dis,win,"sga_example_x11","sga_example_x11",None,NULL,0,NULL);
	XSelectInput(dis, win, ExposureMask|ButtonPressMask|KeyPressMask);
    gc=XCreateGC(dis, win, 0,0);        
	XSetBackground(dis,gc,black);
	XSetForeground(dis,gc,white);
	XClearWindow(dis, win);
	XMapRaised(dis, win);
};

void close_x() {
	sga_end(dctx);

	XFreeGC(dis, gc);
	XDestroyWindow(dis,win);
	XCloseDisplay(dis);	
	exit(1);				
};

void redraw() {
	XClearWindow(dis, win);
};

