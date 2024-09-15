#include "headers/handle.h"
#include "headers/screens.h"
#include "headers/helper.h"

bool handleScrens (struct AllegroGame *game, GameState *gameState) {
  bool redraw = true;

  if (game->event.type == ALLEGRO_EVENT_TIMER)
    redraw = true;
  else if(game->event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    return false;

  if(game->event.type == ALLEGRO_EVENT_KEY_DOWN) {
    if(game->event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      if (*gameState != MENU) {
        *gameState = MENU;
      }
    }
  }

  if(redraw && al_is_event_queue_empty(game->queue)) {
    al_clear_to_color(AL_COLOR_BLACK);

    switch (*gameState) {
      case MENU:
        if (!drawHome(game, gameState)) return false;
        break;
      case CONFIG:
        if (!drawConfig(game)) *gameState = MENU;
        break;
      case GAME:
        if (!drawGame(game)) *gameState = MENU;
        break;
      default:
        break;
    }

    al_flip_display();
  }

  return true;
}