#include "headers/sound.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

Sample samples[MAX_SAMPLES];

void play_sound(int sample_index) {
  if (sample_index < 0 || sample_index >= MAX_SAMPLES) {
    fprintf(stderr, "Invalid sample ID: %d\n", sample_index);
    return;
  }

  al_reserve_samples(samples[sample_index].id);

  Sample sample = samples[sample_index];

  ALLEGRO_SAMPLE *sound = al_load_sample(sample.path);

  if (!sound) {
    fprintf(stderr, "Failed to load sample: %s\n", sample.path);
    return;
  }

  al_play_sample(sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void setupSamples(void) {
  Sample menu_hover = {
    .id = 1,
    .path = "assets/audio/menu-hover.wav",
    .name = "menu-hover"
  };

  samples[0] = menu_hover;
}