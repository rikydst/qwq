/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    NUMB,  // number/navigation
    MOUS,  // mouse navigation
};

#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

// Blank template at the bottom

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  ESC   |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |      |           | VolUp|   H  |   J  |   K  |   L  | ;  : |RSft/' "|
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           | VolDn|   N  |   M  | ,  < | . >  | /  ? |RCtl/- _|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .----------.                          .-----------.   .------.
 *                    |   LAlt   |   |SYMB/Space|                          | NUMB/Bksp |   | MOUS |
 *                    '----------'   '----------'                          `-----------'   '------'
 *                                        ,-------.                   ,-------.
 *                                        |       |                   |VolMute|
 *                                 ,------|-------|                   |-------|------.
 *                                 | NUMB |       |                   |       | SYMB |
 *                                 | Tab  |  LGui |                   |   =   | Enter|
 *                                 |      |       |                   |       |      |
 *                                 `--------------'                   `--------------'
 */
[BASE] = LAYOUT_gergo(
    KC_ESC,  KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_BSLS,
    KC_LSFT, KC_A,  KC_S,   KC_D,   KC_F, KC_G, XXXXXXX,                       KC_VOLU,  KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, MT(MOD_RSFT, KC_QUOT),
    KC_LCTL, KC_Z,  KC_X,   KC_C,   KC_V, KC_B, XXXXXXX,  XXXXXXX,    KC_MUTE, KC_VOLD,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RCTL, KC_MINS),
             KC_LALT, LT(SYMB, KC_SPC), LT(NUMB, KC_TAB), KC_LGUI,    KC_EQL, LT(SYMB, KC_ENT), LT(NUMB, KC_BSPC), MO(MOUS)
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  #   |  $   |  {   |  }   |      |                         |      |  <   |  >   |      |      |   |    |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  !   |  @   |  (   |  )   |  `   |      |           |      |   -  |  &   |  +   |  *   |  ;   |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   _  |  |   |  ,   |  .   |  / ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .----------.                               .-----.   .------.
 *                    |   LAlt   |   |SYMB/Space|                               | Del |   | MOUS |
 *                    '----------'   '----------'                               `-----'   '------'
 *                                        ,-------.                   ,-------.
 *                                        |       |                   |       |
 *                                 ,------|-------|                   |-------|------.
 *                                 | NUMB |       |                   |       | SYMB |
 *                                 | Tab  |  LGui |                   |   =   | Enter|
 *                                 |      |       |                   |       |      |
 *                                 `--------------'                   `--------------'
 */
[SYMB] = LAYOUT_gergo(
    _______, KC_HASH, KC_DLR,  KC_LCBR, KC_RCBR, XXXXXXX,                                            XXXXXXX, KC_ANGL, KC_ANGR, XXXXXXX, XXXXXXX, KC_PIPE,
    _______, KC_EXLM, KC_AT,   KC_LPRN, KC_RPRN, KC_GRV,  XXXXXXX,                          XXXXXXX, KC_MINS, KC_AMPR, KC_PLUS, KC_ASTR, KC_SCLN, KC_QUOT,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, KC_UNDS, KC_PIPE, KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                        _______, _______, _______, _______,        _______, _______, KC_DEL,  _______
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   | F6   |           |      | PgUp | LEFT |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F7  |  F8  | F9   | F10  | F11  | F12  |           |      |PgDown| HOME | DOWN | END  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .----------.                          .-----------.   .------.
 *                    |   LAlt   |   |SYMB/Space|                          | NUMB/Bksp |   | MOUS |
 *                    '----------'   '----------'                          `-----------'   '------'
 *                                        ,-------.                   ,-------.
 *                                        |       |                   |       |
 *                                 ,------|-------|                   |-------|------.
 *                                 | NUMB |       |                   |       | SYMB |
 *                                 | Tab  |  LGui |                   |   =   | Enter|
 *                                 |      |       |                   |       |      |
 *                                 `--------------'                   `--------------'
 */
[NUMB] = LAYOUT_gergo(
    _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    XXXXXXX,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         XXXXXXX, KC_PGUP, KC_LEFT, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,     XXXXXXX, XXXXXXX, KC_PGDN, KC_HOME, KC_DOWN, KC_END,   XXXXXXX, XXXXXXX,
                                        _______, _______, _______, _______,     _______, _______, _______, _______
    ),
/* Keymap 3: Mouse layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  F1  |  F2  | F3   | F4   | F5   | F6   |           |      |      |  M_L |  M_U |  M_R | M_Clk|        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  F7  |  F8  | F9   | F10  | F11  | F12  |           |      |      | L_Clk|  M_D | R_Clk|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .----------.                          .-----------.   .------.
 *                    |   LAlt   |   |SYMB/Space|                          | NUMB/Bksp |   | MOUS |
 *                    '----------'   '----------'                          `-----------'   '------'
 *                                        ,-------.                   ,-------.
 *                                        |       |                   |       |
 *                                 ,------|-------|                   |-------|------.
 *                                 | NUMB |       |                   |       | SYMB |
 *                                 | Tab  |  LGui |                   |   =   | Enter|
 *                                 |      |       |                   |       |      |
 *                                 `--------------'                   `--------------'
 */
[MOUS] = LAYOUT_gergo(
    _______, _______, _______, _______, _______, _______,                                         _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                       _______, XXXXXXX, KC_MS_L, KC_MS_U,  KC_MS_R, KC_BTN3, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, XXXXXXX, KC_BTN1, KC_MS_D,  KC_BTN2, _______, _______,
                                        _______, _______, _______, _______,     _______, _______, _______, _______
    ),
};

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
 */
// clang-format off
