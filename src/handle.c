#include "headers/handle.h"
#include "headers/screens.h"
#include "headers/helper.h"

bool handleScrens (
  struct AllegroGame *game,
  ALLEGRO_MOUSE_STATE *mouse_state,
  GameState *gameState,
  ALLEGRO_EVENT event
) {
  bool redraw = true;

  if (event.type == ALLEGRO_EVENT_TIMER)
    redraw = true;
  else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    return false;

  if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
    if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
      if (*gameState != MENU) {
        *gameState = MENU;
      }
    }
  }

  if(redraw && al_is_event_queue_empty(game->queue)) {
    al_clear_to_color(AL_COLOR_BLACK);

    switch (*gameState) {
      case MENU:
        if (!drawHome(game, mouse_state, gameState)) return false;
        break;
      case CONFIG:
        if (!drawConfig(game, mouse_state)) *gameState = MENU;
        break;
      case GAME:
        if (!drawGame(game, mouse_state)) *gameState = MENU;
        break;
      default:
        break;
    }

    al_flip_display();
  }

  return true;
}