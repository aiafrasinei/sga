#include <stdio.h>
#include "sga_impl_allegro5.h"


const float FPS = 60;

int main(int argc, char *argv[])
{
    struct sga_ctx *sctx = NULL;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	bool running = true;
	bool redraw = true;

    sctx = sga_start();

	if (!al_init()) {
		fprintf(stderr, "Failed to initialize allegro.\n");
		return 1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "Failed to create timer.\n");
		return 1;
	}

	const int WIDTH = 1024;
	const int HEIGHT = 768;

	display = al_create_display(WIDTH, HEIGHT);
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		return 1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "Failed to create event queue.");
		return 1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();

	al_start_timer(timer);

	while (running) {
		ALLEGRO_EVENT event;
		ALLEGRO_TIMEOUT timeout;

		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

		if (get_event) {
			switch (event.type) {
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				default:
					fprintf(stderr, "Unsupported event received: %d\n", event.type);
					break;
			}
		}

        al_clear_to_color(al_map_rgb(0, 0, 0));

        sga_color(sctx, 255, 255, 255);
		sga_point(sctx, 50, 50);

		sga_line(sctx, 130, 50, 100.332f, 200.0f);

		sga_color(sctx, 240, 0, 0);
		sga_rect(sctx, 60, 60, 20, 20);

		sga_fill_rect(sctx, 160, 60, 30, 30);
		
	    al_flip_display();

	} 

	// Clean up
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
    sga_end(sctx);

	return 0;
}