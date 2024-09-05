#ifndef __HANDLE_STATE__
#define __HANDLE_STATE__

#include <allegro5/allegro5.h>

bool handleScrens (
  struct AllegroGame *game,
  ALLEGRO_MOUSE_STATE *mouse_state,
  GameState *gameState,
  ALLEGRO_EVENT event
);

#endif