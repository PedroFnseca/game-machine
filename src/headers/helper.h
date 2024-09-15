#ifndef __HELPER_STATE__
#define __HELPER_STATE__

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

extern const int WIDTH_SCREEN;
extern const int HEIGHT_SCREEN;

extern const char* FONT_PATH;
extern const int FONT_SIZE;
extern const int FONT_SIZE_SMALL;
extern const int FONT_SIZE_BIG;

#define AL_COLOR_BLACK al_map_rgb(0, 0, 0)
#define AL_COLOR_WHITE al_map_rgb(255, 255, 255)
#define AL_COLOR_BLUE al_map_rgb(0, 0, 128)
#define AL_COLOR_YELLOW al_map_rgb(255, 255, 0)
#define AL_COLOR_RED al_map_rgb(128, 0, 0)

struct AllegroGame {
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_FONT *font;
  ALLEGRO_FONT *font_small;
  ALLEGRO_FONT *font_big;
  ALLEGRO_MOUSE_STATE *mouse_state;
};

enum MENU_OPTIONS { START_GAME, SETTINGS, EXIT, NUM_OPTIONS };

typedef enum {
  MENU = 0,
  GAME = 1,
  CONFIG = 2
} GameState;

bool isMouseOverText(int mouse_x, int mouse_y, int text_x, int text_y, const char *text, ALLEGRO_FONT *font);

bool isMouseOverBox(int mouse_x, int mouse_y, int box_x, int box_y, int box_width, int box_height);

#endif