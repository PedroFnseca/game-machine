#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include "headers/helper.h"
#include "headers/handle.h"
#include "headers/sound.h"

struct AllegroGame *game;
GameState gameState = MENU;

void setupAllegro(void) {
  al_init();
  al_install_keyboard();
  al_init_image_addon();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_install_mouse();
  al_install_audio();
  al_init_acodec_addon();

  initialize_colors();

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
  al_set_window_title(game->display, "Came-Machine");
  al_set_display_icon(game->display, al_load_bitmap("assets/images/icon.png"));
  al_register_event_source(game->queue, al_get_timer_event_source(game->timer));
}

void destroyAllegro() {
  al_destroy_font(game->font);
  al_destroy_font(game->font_small);
  al_destroy_font(game->font_big);
  
  al_destroy_display(game->display);
  al_destroy_timer(game->timer);
  al_destroy_event_queue(game->queue);

  al_uninstall_audio();
  al_uninstall_keyboard();
  al_uninstall_mouse();
  al_shutdown_ttf_addon();
  al_shutdown_font_addon();
  al_shutdown_primitives_addon();
  al_shutdown_image_addon();

  free(game);
}

int main() {
  setupAllegro();
  setupSamples();

  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(game->timer);
  bool done = false;

  while(!done) {
    al_wait_for_event(game->queue, &event);

    ALLEGRO_MOUSE_STATE mouse_state;
    al_get_mouse_state(&mouse_state);

    if (!handleScrens(game, &mouse_state, &gameState, event)) {
      done = true;
    }
  }

  destroyAllegro();

  return 0;
}