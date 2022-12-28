#include <stdlib.h>
#include <math.h>

#include "sga_impl_sfml.h"


struct Line {
    sf::Vertex arr[2];
};

struct sga_ctx {
    sf::RenderWindow *window;
    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::Vertex> points;
    std::vector<Line> lines;
    sf::Color color;
};


struct sga_ctx *sga_start()
{
    struct sga_ctx *ctx = (struct sga_ctx *)calloc(1, sizeof(struct sga_ctx));

    return ctx;
}

void sga_init(struct sga_ctx *ctx, sf::RenderWindow *window)
{
    ctx->window = window;
}

void sga_point(struct sga_ctx *ctx, int x, int y)
{
    sf::Vertex point(sf::Vector2f(x, y), ctx->color);
    ctx->points.push_back(point);
}

void sga_line(struct sga_ctx *ctx, int x0, int y0, int x1, int y1)
{
    Line line =
    {
        sf::Vertex(sf::Vector2f(x0, y0)),
        sf::Vertex(sf::Vector2f(x1, y1))
    };
    ctx->lines.push_back(line);
}

void sga_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineColor(ctx->color);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(sf::Vector2f(x, y));
    ctx->rectangles.push_back(rectangle);
}

void sga_fill_rect(struct sga_ctx *ctx, int x, int y, int width, int height)
{
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(ctx->color);
    rectangle.setPosition(sf::Vector2f(x, y));
    ctx->rectangles.push_back(rectangle);
}

void sga_color(struct sga_ctx *ctx, int r, int g, int b)
{
    ctx->color = {(sf::Uint8)r, (sf::Uint8)g, (sf::Uint8)b, 255};
}

void sga_draw(struct sga_ctx *ctx)
{
    for(size_t i=0; i<ctx->rectangles.size(); i++) {
        ctx->window->draw(ctx->rectangles[i]);
    }

    for(size_t i=0; i<ctx->rectangles.size(); i++) {
        ctx->window->draw(&ctx->points[i], 1, sf::Points);
    }

    for(size_t i=0; i<ctx->rectangles.size(); i++) {
        ctx->window->draw(ctx->lines[i].arr, 2, sf::Lines);
    }
}

void sga_end(struct sga_ctx *ctx)
{
    free(ctx);
}
