/* Copyright 2019 @ninjonas
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
#include "ninjonas.h"     

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  QWERTY
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Play |           |K_LOCK |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |       |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |-------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|  [   |           |   ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |       |   N  |   M  |   ,  |   .  |  /   |   =    |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+------+--------'
 *   |M_SHFT|      | Alt  |     | Ctl  |                                        | BkSP | Del  |LOWER |M_ZOOM|M_PYNV|
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Up  | Down |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Del  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_QWERTY] = LAYOUT_ergodox_wrapper(
        // LEFT HAND
        _____________________NUM_LEFT_______________________, KC_MPLY,
        _____________________QWERTY_L1______________________, KC_NO,
        _____________________QWERTY_L2______________________,
        _____________________QWERTY_L3______________________, T_LBRC,
        M_SHFT, KC_NO, ________MOD_LEFT_________,
                                              // LEFT THUMB
                                              KC_UP, KC_DOWN,
                                                     KC_HOME,
                                              LT_RAI, KC_BSPC,
                                                      KC_END,

        //RIGHT HAND
        K_LOCK, _____________________NUM_RIGHT______________________,
        KC_NO,  _____________________QWERTY_R1______________________,
                _____________________QWERTY_R2______________________,
        T_RBRC, _____________________QWERTY_R3______________________,
                ________MOD_RIGHT________, M_ZOOM, M_PYNV,
                // RIGHT THUMB
                KC_LEFT, KC_RGHT,
                KC_PGUP,
                KC_PGDN,
                KC_DEL,  LT_LOW
    ),

/* DVORAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Play |           |K_LOCK |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |      |           |       |   F  |   G  |   C  |   R  |   L  |   \    |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |-------|   D  |   H  |   T  |   N  |  S   |   /    |
 * |--------+------+------+------+------+------|  [   |           |   ]   |------+------+------+------+------+--------|
 * | LShift |   ;  |   Q  |   J  |   K  |   X  |      |           |       |   B  |   M  |   W  |   V  |  Z   |   =    |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+------+--------'
 *   |M_SHFT|      | Alt  |     | Ctl  |                                        | BkSP | Del  |LOWER |M_ZOOM|M_PYNV|
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Up  | Down |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Del  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_DVORAK] = LAYOUT_ergodox_wrapper(
        // LEFT HAND
        _____________________NUM_LEFT_______________________, KC_MPLY,
        _____________________DVORAK_L1______________________, KC_NO,
        _____________________DVORAK_L2______________________,
        _____________________DVORAK_L3______________________, T_LBRC,
        M_SHFT, KC_NO, ________MOD_LEFT_________,
                                              // LEFT THUMB
                                              KC_UP, KC_DOWN,
                                                     KC_HOME,
                                              LT_RAI, KC_BSPC,
                                                      KC_END,

        //RIGHT HAND
        K_LOCK, _____________________NUM_RIGHT______________________,
        KC_NO,  _____________________DVORAK_R1______________________,
                _____________________DVORAK_R2______________________,
        T_RBRC, _____________________DVORAK_R3______________________,
                ________MOD_RIGHT________, M_ZOOM, M_PYNV,
                // RIGHT THUMB
                KC_LEFT, KC_RGHT,
                KC_PGUP,
                KC_PGDN,
                KC_DEL,  LT_LOW
    ),

/* COLEMAK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | Play |           |K_LOCK |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |      |           |       |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+------+--------|
 * | Esc    |   A  |   R  |   S  |   T  |   D  |------|           |-------|   H  |   N  |   E  |   I  |   O  |   '    |
 * |--------+------+------+------+------+------|  [   |           |   ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |       |   K  |   M  |   ,  |   .  |   /  |   =    |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+------+--------'
 *   |M_SHFT|      | Alt  |     | Ctl  |                                        | BkSP | Del  |LOWER |M_ZOOM|M_PYNV|
 *   `----------------------------------'                                        `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Up  | Down |       | Left | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Del  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_COLEMAK] = LAYOUT_ergodox_wrapper(
        // LEFT HAND
        _____________________NUM_LEFT_______________________, KC_MPLY,
        _____________________COLEMAK_L1_____________________, KC_NO,
        _____________________COLEMAK_L2_____________________,
        _____________________COLEMAK_L3_____________________, T_LBRC,
        M_SHFT, KC_NO, ________MOD_LEFT_________,
                                              // LEFT THUMB
                                              KC_UP, KC_DOWN,
                                                     KC_HOME,
                                              LT_RAI, KC_BSPC,
                                                      KC_END,

        //RIGHT HAND
        K_LOCK, _____________________NUM_RIGHT______________________,
        KC_NO,  _____________________COLEMAK_R1_____________________,
                _____________________COLEMAK_R2_____________________,
        T_RBRC, _____________________COLEMAK_R3_____________________,
                ________MOD_RIGHT________, M_ZOOM, M_PYNV,
                // RIGHT THUMB
                KC_LEFT, KC_RGHT,
                KC_PGUP,
                KC_PGDN,
                KC_DEL,  LT_LOW
    ),

/* LOWER
 *
 * ,--------------------------------------------------.           ,----------------------------------------------------.
 * |  F11   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |       |  F6  |  F7  |  F8  |  F9  |  F10  |  F12   |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+-------+--------|
 * |        |      |      |KC_BRU| Play | Mute |      |           |       | PgUp | Home |  Up  | End  |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      |      |KC_BRD| Next |VolUp |------|           |-------| PgDn | Left | Down |Right |K_LOCK |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      |      |      | Prev |VolDn |      |           |       |      |      |      |      |       |        |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+-------+--------'
 *   |      |      |      |      |      |                                        |      |      |      |M_CODE |      |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_LOWER] = LAYOUT_ergodox_wrapper(
        //LEFT HAND
        _____________________FUNC_LEFT______________________, _______,
        _______, _______, _______, _________MEDIA_1_________, _______,
        _______, _______, _______, _________MEDIA_2_________,
        _______, _______, _______, _________MEDIA_3_________, _______,
        _______, _______, _______, _______, _______,
                                            // LEFT THUMB
                                            _______, _______,
                                                     _______,
                                            _______, _______,
                                                     _______,

        //RIGHT HAND
        _______, _____________________FUNC_RIGHT_____________________,
        _______, _______________NAV_1______________, _______, _______,
                 _______________NAV_2______________, K_LOCK,  _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, M_CODE,  _______,
                 // RIGHT THUMB
                 _______, _______,
                 _______,
                 _______,
                 _______, _______
    ),

/* RAISE
 *
 * ,--------------------------------------------------.           ,----------------------------------------------------.
 * |        |      |      |      |K_CSCN|      |      |           |       |      |      |      |      |       |        |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+-------+--------|
 * |        |      | MS_1 | MS_U | MS_2 | WH_U |      |           |       |      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      | MS_L | MS_D | MS_R | WH_D |------|           |-------|      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+-------+--------'
 *   |      |      |      |      |      |                                        |      |      |      |       |      |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_RAISE] = LAYOUT_ergodox_wrapper(
        //LEFT HAND
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K_CSCN,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, _____________MOUSE_1______________, XXXXXXX,
        XXXXXXX, XXXXXXX, _____________MOUSE_2______________,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                   // LEFT THUMB
                                                   _______, _______,
                                                            _______,
                                                   _______, _______,
                                                            _______,

        //RIGHT HAND
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // RIGHT THUMB
        _______, _______,
        _______,
        _______,
        _______, _______
    ),

/* ADJUST
 *
 * ,--------------------------------------------------.           ,----------------------------------------------------.
 * |        |      |      |      |      |      |      |           |       |      |      |      |COLMAK|DVORAK |QWERTY  |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+-------+--------|
 * | M_MAKE |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * | M_VRSN |      |      |      |      |      |------|           |-------|      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * | M_FLSH |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+-------+--------'
 *   |      |      |      |      |      |                                        |      |      |      |       |      |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
    [_ADJUST] = LAYOUT_ergodox_wrapper(
        //LEFT HAND
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        M_MAKE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        M_VRSN,   M_MALL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        M_FLSH,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                   // LEFT THUMB
                                                   _______, _______,
                                                            _______,
                                                   _______, _______,
                                                            _______,

        //RIGHT HAND
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, DVORAK,  QWERTY,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // RIGHT THUMB
        _______, _______,
        _______,
        _______,
        _______, _______
    ),
/* Keymap XX: TEMPLATE
 *
 * ,--------------------------------------------------.           ,----------------------------------------------------.
 * |        |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * |--------+------+------+------+------+-------------|           |-------+------+------+------+------+-------+--------|
 * |        |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      |      |      |      |      |------|           |-------|      |      |      |      |       |        |
 * |--------+------+------+------+------+------|      |           |       |------+------+------+------+-------+--------|
 * |        |      |      |      |      |      |      |           |       |      |      |      |      |       |        |
 * `--------+------+------+------+------+-------------'           `--------------+------+------+------+-------+--------'
 *   |      |      |      |      |      |                                        |      |      |      |       |      |
 *   `----------------------------------'                                        `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
[_XXLAYER] = LAYOUT_ergodox_wrapper(
        //LEFT HAND
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                                   // LEFT THUMB
                                                   _______, _______,
                                                            _______,
                                                   _______, _______,
                                                            _______,

        //RIGHT HAND
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        // RIGHT THUMB
        _______, _______,
        _______,
        _______,
        _______, _______
    ),

 */
};