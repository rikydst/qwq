// qmk compile -kb <keyboard> -km <keymap>
// qmk compile -kb preonic -km keymap_w_subarrays.c

// keyboard agnostic keymap
#include QMK_KEYBOARD_H

// #include "keycodes.h"

enum combos { _topl, _btml, _thml, _midl, _topr, _btmr, _thmr, COMBO_LENGTH };
uint16_t COMBO_LEN = COMBO_LENGTH;

const cmbo_topl[] = {KC_W, KC_E, COMBO_END};
const cmbo_btml[] = {KC_X, KC_C, COMBO_END};
const cmbo_thml[] = {SYM, KC_SPC, COMBO_END};
const cmbo_midl[] = {KC_G, KC_H, COMBO_END};
const cmbo_topr[] = {KC_I, KC_O, COMBO_END};
const cmbo_btmr[] = {KC_COMM, KC_DOT, COMBO_END};
const cmbo_thmr[] = {KC_RSFT, NUM, COMBO_END};

combo_t key_combos[] = {[_topl] = COMBO(cmbo_topl, KC_TAB), [_btml] = COMBO(cmbo_btml, KC_LCTL), [_thml] = COMBO(cmbo_thml, KC_LGUI), [_midl] = COMBO(cmbo_midl, KC_NO), [_topr] = COMBO(cmbo_topr, KC_NO), [_btmr] = COMBO(cmbo_btmr, KC_ENT), [_thmr] = COMBO(cmbo_thmr, KC_LALT)};

#include "layout.c";
