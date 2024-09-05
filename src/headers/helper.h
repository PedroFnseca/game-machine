#ifndef __HELPER_STATE__
#define __HELPER_STATE__

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

extern const int WIDTH_SCREEN;
extern const int HEIGHT_SCREEN;

extern const char* FONT_PATH;
extern const int FONT_SIZE;
extern const int FONT_SIZE_SMALL;
extern const int FONT_SIZE_BIG;

extern ALLEGRO_COLOR AL_COLOR_BLACK;
extern ALLEGRO_COLOR AL_COLOR_WHITE;
extern ALLEGRO_COLOR AL_COLOR_BLUE;
extern ALLEGRO_COLOR AL_COLOR_YELLOW;
extern ALLEGRO_COLOR AL_COLOR_RED;

struct AllegroGame {
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *display;
  ALLEGRO_FONT *font;
  ALLEGRO_FONT *font_small;
  ALLEGRO_FONT *font_big;
};

enum MENU_OPTIONS { START_GAME, SETTINGS, EXIT, NUM_OPTIONS };

typedef enum {
  MENU = 0,
  GAME = 1,
  CONFIG = 2
} GameState;

bool is_mouse_over_text(int mouse_x, int mouse_y, int text_x, int text_y, const char *text, ALLEGRO_FONT *font);

void play_sound(const char *filename);

void initialize_colors(void);

#endif