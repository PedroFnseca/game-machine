#!/bin/bash

gcc src/main.c -o bin/main $(pkg-config --libs --cflags allegro-5 allegro_font-5 allegro_image-5)

./bin/main