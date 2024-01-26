#include <stdio.h>
#include "sga_impl_raylib.h"


struct sga_ctx *sctx = NULL;

int init()
{
    int success = 1;

    const int WIDTH = 1024;
	const int HEIGHT = 768;

    InitWindow(WIDTH, HEIGHT, "sga raylib example");

	return success;
}

int start()
{
	sctx = sga_start();

	return 1;
}

void end()
{

	sga_end(sctx);
}

int main(int argc, const char *argv[])
{
    init();   
    start();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        sga_color(sctx, 255, 255, 255);
        sga_point(sctx, 50, 50);

        sga_line(sctx, 130, 50, 100.332f, 200.0f);

        sga_color(sctx, 240, 0, 0);
        sga_rect(sctx, 60, 60, 20, 20);

        sga_fill_rect(sctx, 160, 60, 30, 30);

        EndDrawing();
    }

    end();

    return 0;
}
