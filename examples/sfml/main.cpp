#include <SFML/Graphics.hpp>

#include "sga_impl_sfml.h"


struct sga_ctx *sctx = NULL;
sf::RenderWindow *window;

int init()
{
    const int WIDTH = 1024;
	const int HEIGHT = 768;

    window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "sga_example_sfml");
}

int start()
{
	sctx = sga_start();
	sga_init(sctx, window);

	return 1;
}

void end()
{
	sga_end(sctx);
}

int main()
{
    init();
    start();

    sga_color(sctx, 255, 255, 255);
    sga_point(sctx, 50, 50);

    sga_line(sctx, 130, 50, 100.332f, 200.0f);

    sga_color(sctx, 240, 0, 0);
    sga_rect(sctx, 60, 60, 20, 20);

    sga_fill_rect(sctx, 160, 60, 30, 30);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();
        
        sga_draw(sctx);
        
        window->display();
    }

    end();
    
    return 0;
}