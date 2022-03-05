#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_1x5(
     KC_1 , KC_2  ,  KC_3  , KC_4  , KC_5  ,         KC_6     , KC_7  , KC_8  , KC_9 , KC_0
  ),
};
