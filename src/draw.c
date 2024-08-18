 
void drawMenu (struct AllegroGame *game, int selected_option) {
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
        ALLEGRO_COLOR color = (i == selected_option) ? AL_COLOR_YELLOW : AL_COLOR_WHITE;
        int option_x = WIDTH_SCREEN / 2;
        int option_y = (HEIGHT_SCREEN / 2) + i * 60;

        al_draw_text(game->font_big, color, option_x, option_y, ALLEGRO_ALIGN_CENTER, menu_options[i]);
    }
}