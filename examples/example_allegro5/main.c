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

	display = al_create_display(640, 480);
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
        sga_line(sctx, 100, 100, 400, 400);
        sga_fill_rect(sctx, 50, 50, 30, 30);
        sga_point(sctx, 200, 10);

	    al_flip_display();

	} 

	// Clean up
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
    sga_end(sctx);

	return 0;
}