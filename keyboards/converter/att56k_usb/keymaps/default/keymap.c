
#include QMK_KEYBOARD_H

/* This converter defines a new custom keycode CLCK_CYC to cycle through
 * the modes for the built in clicker as follows:
 *  - Off
 *  - On key press
 *  - On key press and release
 * Note: Use NEW_SAFE_RANGE to define new custom keycodes and macros as
 * SAFE_RANGE was used to define CLCK_CYC */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
                               KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, CLCK_CYC,
                               KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
  KC_F1  , KC_F2  ,   KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL , KC_BSPC,   KC_INS , KC_HOME, KC_PGUP,    KC_ESC , KC_PSLS, KC_PCMM, KC_SPC,
  KC_F3  , KC_F4  ,    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P  , KC_LBRC, KC_RBRC, KC_ENT ,   KC_DEL , KC_END , KC_PGDN,    KC_P7  , KC_P8  , KC_P9  , KC_TAB,
  KC_F5  , KC_F6  ,     KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J  , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_SLSH,                    KC_UP  ,             KC_P4  , KC_P5  , KC_P6  , KC_PMNS,
  KC_F7  , KC_F8  ,   KC_LSFT, KC_NUBS, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N  , KC_M  , KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,          	  KC_LEFT, KC_HOME  , KC_RGHT,  KC_P1  , KC_P2  , KC_P3  , KC_PENT,
  KC_F9  , KC_F10 ,   KC_LCTL,          KC_LALT,                            KC_SPC ,                                     KC_RALT,         KC_RCTL,             KC_DOWN,                 KC_P0  ,      KC_PDOT
	),

};

