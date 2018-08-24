#include QMK_KEYBOARD_H
#include "wanleg.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[gGK] = LAYOUT_ortho_5x10_wrapper(
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_Row_0_______________,
  _______________Gherkin_Row_1_______________,
  _______________Gherkin_Row_2_______________,
  KC_LGUI, KC_LALT, KC_LALT, gNUMBER, gETCETERA, KC_SPC,gDIRECTION, KC_RGUI, KC_RALT, KC_DEL
),

/*
[gNUM] = LAYOUT_ortho_5x10_wrapper(
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_NUM_1_______________,
  _______________Gherkin_NUM_2_______________
),

[gDIR] = LAYOUT_ortho_5x10_wrapper(
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________
),

[gETC] = LAYOUT_ortho_5x10_wrapper(
  _______________Gherkin_ETC_0_______________,
  _______________Gherkin_ETC_1_______________,
  _______________Gherkin_ETC_2_______________
),
*/
};
