#define WIDTH_SCREEN 1024
#define HEIGHT_SCREEN 900

#define FONT_PATH "assets/fonts/Roboto-Regular.ttf"
#define FONT_SIZE 18
#define FONT_SIZE_SMALL 14
#define FONT_SIZE_BIG 24

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
};

enum MENU_OPTIONS { START_GAME, SETTINGS, EXIT, NUM_OPTIONS };

typedef enum {
  MENU = 0,
  GAME = 1,
  CONFIG = 2
} GameState;

bool is_mouse_over_text(int mouse_x, int mouse_y, int text_x, int text_y, const char *text, ALLEGRO_FONT *font) {
  int text_width = al_get_text_width(font, text);
  int text_height = al_get_font_line_height(font);

  int text_left = text_x - text_width / 2;
  int text_right = text_x + text_width / 2;
  int text_top = text_y;
  int text_bottom = text_y + text_height;

  return (mouse_x >= text_left && mouse_x <= text_right && mouse_y >= text_top && mouse_y <= text_bottom);
}

void play_sound(const char *filename) {
  ALLEGRO_SAMPLE *sample = al_load_sample(filename);

  if (!sample) {
    fprintf(stderr, "Failed to load sound: %s\n", filename);
    return;
  }

  if (!al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL)) {
    fprintf(stderr, "Failed to play sound: %s\n", filename);
  }
  
  al_destroy_sample(sample);
}