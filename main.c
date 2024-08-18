#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

#include "screen.h"
#include "structs.c"

struct AllegroGame *game;

void setupAllegro() {
  al_init();
  al_install_keyboard();
  al_init_image_addon();

  game = malloc(sizeof(struct AllegroGame));

  game->timer = al_create_timer(1.0 / 30.0);
  game->queue = al_create_event_queue();
  game->display = al_create_display(WIDTH_SCREEN, HEIGHT_SCREEN);
  game->font = al_create_builtin_font();

  al_register_event_source(game->queue, al_get_keyboard_event_source());
  al_register_event_source(game->queue, al_get_display_event_source(game->display));
  al_set_window_title(game->display, "Jackpot Game");
  al_set_display_icon(game->display, al_load_bitmap("assets/icon.png"));
  al_register_event_source(game->queue, al_get_timer_event_source(game->timer));
}

void destroyAllegro() {
  al_destroy_font(game->font);
  al_destroy_display(game->display);
  al_destroy_timer(game->timer);
  al_destroy_event_queue(game->queue);
  free(game);
}

int main() {
  setupAllegro();

  ALLEGRO_BITMAP *background = al_load_bitmap("assets/background.jpeg");

  if (!background) {
    fprintf(stderr, "Failed to load image.\n");
    return 1;
  }

  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(game->timer);
  while(1) {
    al_wait_for_event(game->queue, &event);

    if (event.type == ALLEGRO_EVENT_TIMER)
      redraw = true;
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;

    if(redraw && al_is_event_queue_empty(game->queue)) {
      al_clear_to_color(al_map_rgb(100, 0, 0));
      al_draw_bitmap(background, 0, 0, 0);
      al_flip_display();

      redraw = false;
    }
  }

  al_destroy_bitmap(background);
  destroyAllegro();

  return 0;
}