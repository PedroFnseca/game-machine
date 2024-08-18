#!/bin/bash

gcc main.c -o bin/out $(pkg-config --libs --cflags allegro-5 allegro_font-5 allegro_image-5)

./bin/out