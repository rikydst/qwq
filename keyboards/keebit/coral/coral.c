// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

// ===== LED/RGB INDICATOR =====
enum RGB_LAYERS {
    RGBL_CAPSL = 0,
    RGBL_CAPSW = 1,
};

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_BLUE}
);

const rgblight_segment_t PROGMEM capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
   [RGBL_CAPSL] =  capslock_layer,
   [RGBL_CAPSW] =  capsword_layer
);

bool led_update_kb(led_t led_state) {
    if (!led_update_user(led_state)) {
        return false;
    }
    rgblight_set_layer_state(RGBL_CAPSL, led_state.caps_lock);
    return true;
}

__attribute__((weak)) void caps_word_set_user(bool active) {
    rgblight_set_layer_state(RGBL_CAPSW, active);
}

void keyboard_post_init_kb(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
    keyboard_post_init_user();
}
