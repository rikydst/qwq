#include QMK_KEYBOARD_H
#include "mechmerlin.h"

// #define _BL   0 // Base Layer
// #define _FN   1 // Function Layer
// #define _AR   2 // Arrow Layer

// // Custom #defined keycodes
// #define KC_CTCP MT(KC_LCTL, KC_CAPS)

// // Enum of custom keycodes defined in process_record_user
// enum keycodes {
//     KC_FNX, // Hold for FN layer, tap to toggle ARROWS layer. 
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_60_ansi(
    KC_GESC, KC_1,    KC_2, KC_3, KC_4, KC_5, KC_6, KC_7,  KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC, \
	KC_TAB,  KC_Q,    KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U,  KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLASH, \
    KC_CTCP, KC_A,    KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_LCTL, KC_LGUI, KC_LALT,       KC_SPACE,             KC_FNX,   KC_RALT, KC_RGUI, KC_RCTL),

[_FL] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
	RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, \
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_AL] = LAYOUT_60_ansi(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, \
    KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS,                               KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT)

 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t fnx_layer_timer;

    switch (keycode){
        case KC_FNX:                                    
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                layer_on(_FL);
            } else {
                layer_off(_FL);
                if (timer_elapsed(fnx_layer_timer) < 150) {  
                    layer_invert(_AL);
                }
            }
        return false;
    }
    return true;
}