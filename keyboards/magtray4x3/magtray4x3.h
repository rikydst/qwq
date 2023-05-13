#pragma once

#include QMK_KEYBOARD_H

//for changing layers
extern uint8_t current_layer;

//for oled key press
extern bool key_pressed;

// for changing oled display mode
extern uint8_t current_display_mode;

//for determining when the layer is changed and having a timer for how long we flash the layer
extern uint32_t flash_timer;
extern bool layer_changed;
