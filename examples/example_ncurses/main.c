#include <ncurses.h>
#include "sga_impl_ncurses.h"


int main(int argc, char *argv[])
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);

    struct sga_ctx *sctx = sga_start();

    sga_point(sctx, 10, 10);

    sga_set_drawchar(sctx,'#');
    sga_point(sctx, 2, 2);
    
    sga_color_fb(sctx, COLOR_RED, COLOR_BLUE);
    sga_line(sctx, 0, 0, 15, 0);

    sga_color(sctx, COLOR_BLUE);
    sga_rect(sctx,4,10,4,4);

    sga_color(sctx, COLOR_RED);
    sga_fill_rect(sctx, 15, 10, 4, 4);
    
    refresh();
    getch();

    sga_end(sctx);

    endwin();

    return 0;
}
