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
    sga_curs_to(sctx, 5, 5);
    sga_curs_point(sctx);

    sga_set_drawchar(sctx,'#');
    sga_point(sctx, 2, 2);
    
    refresh();
    getch();

    sga_end(sctx);

    endwin();

    return 0;
}
