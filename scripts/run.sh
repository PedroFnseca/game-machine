gcc main.c -o bin/main $(pkg-config allegro-5 allegro_font-5 --libs --cflags)

bin/main