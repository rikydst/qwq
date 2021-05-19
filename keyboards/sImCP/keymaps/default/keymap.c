/* Copyright 2021 dsanchezseco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
};

enum {
    DOB_PUSH
};
// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    DOB_UP,
    DOB_DOWN,
    DOB_LEFT,
    DOB_RIGHT,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOB_PUSH] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_SPC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        DOB_UP, DOB_LEFT, DOB_DOWN, DOB_RIGHT, TD(DOB_PUSH)
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DOB_UP:
            if (record->event.pressed) {
                SEND_STRING("UP");
            }
            break;
        case DOB_DOWN:
            if (record->event.pressed) {
                SEND_STRING("DOWN");
            }
            break;
        case DOB_LEFT:
            if (record->event.pressed) {
                SEND_STRING("LEFT");
            }
            break;
        case DOB_RIGHT:
            if (record->event.pressed) {
                SEND_STRING("RIGHT");
            }
            break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Encoder on the LEFT */
        if (clockwise) {
            tap_code(KC_U);
        } else {
            tap_code(KC_D);
        }
    } else if (index == 1) { /* Encoder on the RIGHT */
        if (clockwise) {
            tap_code(KC_U);
        } else {
            tap_code(KC_D);
        }
    } else if (index == 3) { /* Encoder on the RIGHT */
        if (clockwise) {
            tap_code(KC_U);
        } else {
            tap_code(KC_D);
        }
    }
}
