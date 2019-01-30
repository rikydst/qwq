#include QMK_KEYBOARD_H

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
/* 
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |  -   |           |  =   |   6  |   7  |   8  |   9  |   0  |  Bsp   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L2  |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   |  Up    |
 * `--------+------+------+---------------------------'           `---------------------------+------+------+--------'
 *   | Ctrl | Super|  Alt |                                                                   | Left |  Down| Right |
 *   `--------------------'                                                                   `--------------------'
 *                                        ,------|------.       ,---------------.
 *                                        |      | PgUp |       | Home |        |  
 *                                        | Space|------|       |------|  Enter | 
 *                                        |      | PgDn |       | End  |        | 
 *                                        `-------------'       `---------------'
 */
    [0] = LAYOUT(
	KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_MINS,       KC_EQL,  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_BSPC,
	KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   TG(1),         KC_LBRC, KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_BSLS,
	KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                           KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT, 
	KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   TG(2),         KC_RBRC, KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH, KC_UP  ,
	KC_LCTL, KC_LGUI,KC_LALT,                                                                        KC_LEFT,KC_DOWN, KC_RGHT,
                                           KC_SPC, KC_PGUP,       KC_HOME, KC_ENT,
                                           KC_SPC, KC_PGDN,       KC_END,  KC_ENT
    ),
    [1] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,                                                                                    _______,  _______,  _______,
                                                    _______,  _______,    _______,  _______,  
                                                    _______,  _______,    _______,  _______
    ),
    [2] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______, 
	_______,  _______,  _______,                                                                                    _______,  _______,  _______,
                                                    _______,  _______,    _______,  _______,  
                                                    _______,  _______,    _______,  _______
    ),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
