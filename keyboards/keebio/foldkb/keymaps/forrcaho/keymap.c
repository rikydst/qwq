/* Copyright 2021 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer {
    _QWERTY,
    _PG, // for "programming"
};

enum custom_keycodes {
    PG_BANG = SAFE_RANGE,
    PG_ENDC,
    PG_EQEQ,
    PG_EQL,
    PG_LBRK,
    PG_LPAR,
    PG_MINS,
    PG_NEEQ,
    PG_RBRK,
    PG_RPAR,
    PG_SLAS,
    PG_VBAR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_MUTE, KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_HOME,     KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
    KC_END,      KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴────┬────────┬───┘
    KC_PGUP, KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      MO(1),
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┼────────┤        ├────────┴─┬──────┴──────┬─┴────────┼────────┴─┬─────────┬─┴────────┤
    KC_PGDN,     KC_LGUI,   KC_LCTL,  KC_LALT,   MO(1),   KC_SPC,  KC_SPC,           KC_SPC,    KC_SPC,       TG(1),     KC_RALT,   KC_RCTL,  KC_RGUI
// └────────┴───┴──────────┴─────────┴──────────┴────────┴────────┴────────┘        └──────────┴─────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
  [_PG] = LAYOUT(
// ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
    KC_MUTE, RESET,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
// ├────────┼───┬────┴────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    BL_STEP,     _______,      _______, PG_SLAS, PG_LPAR, PG_RPAR, PG_NEEQ,          _______, KC_HOME, KC_UP,   KC_PGUP, _______, _______, _______, _______,
// ├────────┼───┼─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
    RGB_MOD,     _______,      PG_ENDC, PG_VBAR, PG_LBRK, PG_RBRK, PG_EQEQ,          _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_BSPC,
// ├────────┼───┴─────────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┴────┬────────┬───┘
    KC_VOLU, _______,          _______, PG_MINS, PG_EQL,  PG_BANG, _______,          _______, KC_END,  KC_INS,  KC_PGDN, _______, _______,      _______,
// ├────────┼───┬──────────┬──┴──────┬─┴────────┼────────┼────────┼────────┤        ├────────┴─┬──────┴──────┬─┴────────┼────────┴─┬─────────┬─┴────────┤
    KC_VOLD,     _______,   _______,  _______,   _______, _______, _______,          _______,   _______,      _______,   _______,   _______,  _______
// └────────┴───┴──────────┴─────────┴──────────┴────────┴────────┴────────┘        └──────────┴─────────────┴──────────┴──────────┴─────────┴──────────┘
  ),
};

const key_override_t pg_bang_none = ko_make_with_layers_and_negmods(0, PG_BANG, KC_EXCLAIM, ~0, ~0);
// Shifted PG_BANG is macro

const key_override_t pg_lbrk_none = ko_make_with_layers_and_negmods(0, PG_LBRK, KC_LEFT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_lbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LBRK, KC_LEFT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_lpar_none = ko_make_with_layers_and_negmods(0, PG_LPAR, KC_LEFT_PAREN, ~0, ~0);
const key_override_t pg_lpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LPAR, KC_LEFT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

// Unshifted PG_MINS is macro
const key_override_t pg_mins_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_MINS, KC_UNDERSCORE, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rbrk_none = ko_make_with_layers_and_negmods(0, PG_RBRK, KC_RIGHT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_rbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RBRK, KC_RIGHT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rpar_none = ko_make_with_layers_and_negmods(0, PG_RPAR, KC_RIGHT_PAREN, ~0, ~0);
const key_override_t pg_rpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RPAR, KC_RIGHT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_slas_none = ko_make_with_layers_and_negmods(0, PG_SLAS, KC_SLASH, ~0, ~0);
const key_override_t pg_slas_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_SLAS, KC_BACKSLASH, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_vbar_none = ko_make_with_layers_and_negmods(0, PG_VBAR, KC_PIPE, ~0, ~0);
const key_override_t pg_vbar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_VBAR, KC_AMPERSAND, ~0, ~MOD_MASK_SHIFT);


const key_override_t **key_overrides = (const key_override_t *[]){
    &pg_bang_none,
    &pg_lbrk_none,
    &pg_lbrk_shift,
    &pg_lpar_none,
    &pg_lpar_shift,
    &pg_mins_shift,
    &pg_rbrk_none,
    &pg_rbrk_shift,
    &pg_rpar_none,
    &pg_rpar_shift,
    &pg_slas_none,
    &pg_slas_shift,
    &pg_vbar_none,
    &pg_vbar_shift,
    NULL
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t std_mods = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t all_mods = std_mods | oneshot_mods;
    bool shift_on = all_mods & MOD_MASK_SHIFT;
    bool alt_on = all_mods & MOD_MASK_ALT;

    // None of our special keycodes use CTRL or GUI mods (so far), so we
    // check once here at the top and let other code handle it if any of
    // these are set.
    if (all_mods & (MOD_MASK_CTRL | MOD_MASK_GUI)) return true;

    switch (keycode) {
        case PG_BANG:
        if (!shift_on) return true; // key override handles it
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            if (!alt_on) SEND_STRING(" ");
            SEND_STRING("*");
            if (!alt_on) SEND_STRING(" ");
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
        case PG_ENDC:
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            SEND_STRING(SS_TAP(X_END));
            if (!shift_on) SEND_STRING(";");
            if (!alt_on) SEND_STRING(SS_TAP(X_ENTER));
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
        case PG_EQEQ:
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            if (!alt_on) SEND_STRING(" ");
            shift_on ? SEND_STRING("==") : SEND_STRING("===");
            if (!alt_on) SEND_STRING(" ");
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
        case PG_EQL:
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            if (!alt_on) SEND_STRING(" ");
            shift_on ? SEND_STRING("+") : SEND_STRING("=");
            if (!alt_on) SEND_STRING(" ");
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
        case PG_MINS:
        if (!shift_on) return true; // key override handles it
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            if (!alt_on) SEND_STRING(" ");
            SEND_STRING("-");
            if (!alt_on) SEND_STRING(" ");
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
        case PG_NEEQ:
        if (record->event.pressed) {
            clear_mods();
            clear_oneshot_mods();
            if (!alt_on) SEND_STRING(" ");
            shift_on ? SEND_STRING("!=") : SEND_STRING("!==");
            if (!alt_on) SEND_STRING(" ");
            set_mods(std_mods);
            set_oneshot_mods(oneshot_mods);
        }
        break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _PG:
            backlight_level(3);
            break;
        default:
            backlight_level(1);
            break;
    }
    return state;
}

void keyboard_post_init(void) {
    backlight_level(1);
}
