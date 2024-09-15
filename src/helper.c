#include "headers/helper.h"
#include <stdio.h>
#include <allegro5/allegro5.h>

const int WIDTH_SCREEN = 1024;
const int HEIGHT_SCREEN = 900;

const char* FONT_PATH = "assets/fonts/Roboto-Regular.ttf";
const int FONT_SIZE = 18;
const int FONT_SIZE_SMALL = 14;
const int FONT_SIZE_BIG = 24;

bool isMouseOverText(int mouse_x, int mouse_y, int text_x, int text_y, const char *text, ALLEGRO_FONT *font) {
  int text_width = al_get_text_width(font, text);
  int text_height = al_get_font_line_height(font);

  int text_left = text_x - text_width / 2;
  int text_right = text_x + text_width / 2;
  int text_top = text_y;
  int text_bottom = text_y + text_height;

  return (mouse_x >= text_left && mouse_x <= text_right && mouse_y >= text_top && mouse_y <= text_bottom);
}

bool isMouseOverBox(int mouse_x, int mouse_y, int box_x, int box_y, int box_width, int box_height) {
  int box_right = box_x + box_width;
  int box_bottom = box_y + box_height;

  return (mouse_x >= box_x && mouse_x <= box_right && mouse_y >= box_y && mouse_y <= box_bottom);
}