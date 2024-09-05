#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "helper.h"

bool drawHome(struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state, GameState *gameState);

bool drawConfig(struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state);

bool drawGame(struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state);

#endif