#ifndef _DRAW_STATE_
#define _DRAW_STATE_

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "helper.h"

bool drawHome(struct AllegroGame *game, GameState *gameState);

bool drawConfig(struct AllegroGame *game);

bool drawGame(struct AllegroGame *game);

#endif