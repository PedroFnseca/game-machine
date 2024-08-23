bool drawHome (struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state, GameState *gameState) {
  al_draw_filled_rectangle(0, 0, WIDTH_SCREEN, HEIGHT_SCREEN, AL_COLOR_BLACK);

  const char *title = "Caça-Níquel";
  int title_x = WIDTH_SCREEN / 2;
  int title_y = HEIGHT_SCREEN / 6;

  al_draw_text(game->font_big, AL_COLOR_YELLOW, title_x, title_y, ALLEGRO_ALIGN_CENTER, title);

  const char *menu_options[NUM_OPTIONS] = {
    "Iniciar Jogo",
    "Configurações",
    "Sair"
  };

  for (int i = 0; i < NUM_OPTIONS; i++) {
    int option_x = WIDTH_SCREEN / 2;
    int option_y = (HEIGHT_SCREEN / 2) + i * 60;

    bool mouseIsHover = is_mouse_over_text(mouse_state->x, mouse_state->y, option_x, option_y, menu_options[i], game->font_big);

    ALLEGRO_COLOR color = AL_COLOR_WHITE;

    if (mouseIsHover) {
      color = AL_COLOR_YELLOW;

      if (mouse_state->buttons & 1) {
        play_sound("assets/audio/menu-hover.wav");

        switch (i) {
          case START_GAME:
            printf("Iniciar Jogo\n");
            *gameState = GAME;
            break;
          case SETTINGS:
            printf("Configurações\n");
            *gameState = CONFIG;
            break;
          case EXIT:
            return false;
            break;
        }
      }
    }

    al_draw_text(game->font_big, color, option_x, option_y, ALLEGRO_ALIGN_CENTER, menu_options[i]);
  }

  return true;
}

bool drawConfig (struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state) {
  return true;
}

bool drawGame (struct AllegroGame *game, ALLEGRO_MOUSE_STATE *mouse_state) {
  return true;
}