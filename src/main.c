#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include "helper.h"
#include "draw.c"

struct AllegroGame *game;

void setupAllegro(void) {
  al_init();
  al_install_keyboard();
  al_init_image_addon();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_mouse();

  game = malloc(sizeof(struct AllegroGame));

  game->font = al_load_font(FONT_PATH, FONT_SIZE, 0);
  game->font_small = al_load_font(FONT_PATH, FONT_SIZE_SMALL, 0);
  game->font_big = al_load_font(FONT_PATH, FONT_SIZE_BIG, 0);

  game->timer = al_create_timer(1.0 / 30.0);
  game->queue = al_create_event_queue();
  game->display = al_create_display(WIDTH_SCREEN, HEIGHT_SCREEN);

  if (!game->timer || !game->queue || !game->display) {
    fprintf(stderr, "Falha to load Allegro.\n");
    exit(1);
  }

  al_register_event_source(game->queue, al_get_keyboard_event_source());
  al_register_event_source(game->queue, al_get_display_event_source(game->display));
  al_set_window_title(game->display, "Jackpot Game");
  al_set_display_icon(game->display, al_load_bitmap("assets/icon.png"));
  al_register_event_source(game->queue, al_get_timer_event_source(game->timer));
}

void destroyAllegro() {
  al_destroy_font(game->font);
  al_destroy_font(game->font_small);
  al_destroy_font(game->font_big);
  
  al_destroy_display(game->display);
  al_destroy_timer(game->timer);
  al_destroy_event_queue(game->queue);
  free(game);
}

int main() {
  setupAllegro();

  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(game->timer);
  while(1) {
    al_wait_for_event(game->queue, &event);

    ALLEGRO_MOUSE_STATE mouse_state;
    al_get_mouse_state(&mouse_state);

    if (event.type == ALLEGRO_EVENT_TIMER)
      redraw = true;
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;

    if(redraw && al_is_event_queue_empty(game->queue)) {
      al_clear_to_color(AL_COLOR_BLACK);

      al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, AL_COLOR_WHITE);

      if (!drawMenu(game, 0, &mouse_state)) {
        break;
      }

      al_flip_display();

      redraw = false;
    }
  }

  destroyAllegro();

  return 0;
}