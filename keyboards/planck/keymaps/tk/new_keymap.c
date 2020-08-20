/* OLKB Planck keymap - tk
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
#include "muse.h"


enum planck_layers {
    _QWERTY,
    _COLEMAK,
    _SYMBOLS,
    _NAV,
    _MOUSE,
    _ADJUST,
    _CLI,
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,

    BSPC_DEL,       // normal - backspace, ctrl - delete
    SPC_CAPS,       // normal - space, ctrl - caps lock
    ROTARY,
};

enum td_keycodes {
    RAISE, LOWER,   // change layers
    BKO, BKC,       // brackets
    MACRO,          // dynamic macros
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*

IN DEVELOPMENT

*/

/* Base layer

    LATCHED:

    |-----------------------------------------------------------------------------------------------|
    | Rotary|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Panic |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    | Shift |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Enter |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    | HYPER | Super |  Meta |  Ctrl | LOWER |     Space     | RAISE |   Lt  |   Dn  |   Up  |   Rt  |
    |-----------------------------------------------------------------------------------------------|

    UNLATCHED:

    |-----------------------------------------------------------------------------------------------|
    | Rotary|   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Panic |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  Esc  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  Tab  |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Enter |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  < >  |  { }  |  [ ]  |  ( )  | LOWER |     Space     | RAISE |   Lt  |   Dn  |   Up  |   Rt  |
    |-----------------------------------------------------------------------------------------------|

    *
    * Can be in one of 2 modes
    * Each mode has it's own LOWER and RAISE layers
    * Mode 1 - code mode (default)
    * Mode 2 - navigation
    *
    *

*/
[_BASE] = LAYOUT_planck_grid(
    ROTARY,    KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    PANIC,
    CTL_ESC,   KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_SHIFT,
    KC_LSHIFT, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_HYPR,   KC_LGUI  , KC_LALT, KC_LCTL, LOWER,     KC_SPACE, KC_SPACE, RAISE,     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

/* Hyper layer

    |-----------------------------------------------------------------------------------------------|
    |  Vol  |       |       |       |       |       |       |       |       |       |       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    | Reset | latch | LOWER2| LOWER1| MODE1 |      BASE     | MODE2 | RAISE1| RAISE2|       |       |
    |-----------------------------------------------------------------------------------------------|

    *
    * Only layer with inactive left-side modifiers
    * Right above base layer
    *
    * Latch key: toggles modifiers latch
    *
    * Vol key: change hardware audio volume and toggle mute
    * Empty keys: left for software implementation
    *

*/
[_HYPER] = LAYOUT_planck_grid(
    ROTARY,    KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    PANIC,
    CTL_ESC,   KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_SHIFT,
    KC_LSHIFT, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_HYPR,   KC_LGUI  , KC_LALT, KC_LCTL, LOWER,     KC_SPACE, KC_SPACE, RAISE,     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

/* Lower I - symbols

    |-----------------------------------------------------------------------------------------------|
    | Rotary|   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   | Panic |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  Esc  |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |   '   |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  Tab  |   \   |   |   |   `   |   ~   |   '   |   "   |   _   |   -   |   +   |   =   | Enter |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |  < >  |  { }  |  [ ]  |  ( )  | LOWER |      BASE     | RAISE |   Lt  |   Dn  |   Up  |   Rt  |
    |-----------------------------------------------------------------------------------------------|

    *
    * Each non-layer keypress moves to BASE (exception: rotary, arrow keys, enter, panic, numbers?)
    *

*/
[_LOWER1] = LAYOUT_planck_grid(
    ROTARY,  KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    BSPC_DEL,
    CTL_TAB, KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSPO, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    ALT_ESC, _______, _______, _______,   TD(RAISE), SPC_CAPS, SPC_CAPS, TD(LOWER), _______, _______, _______, KC_RGUI
),

/* Raise I - command snippets

    |-----------------------------------------------------------------------------------------------|
    | Rotary|       |       |       |       |       |       |       |       |       | g push|       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       | g add | g stat| dfiles|       |       |       |       |       | g pull|       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       | g cmt |       |       |       |       |       |       |       |       | Enter |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       | LOWER |      BASE     | RAISE |   Lt  |   Dn  |   Up  |   Rt  |
    |-----------------------------------------------------------------------------------------------|

    *
    * DO NOT INCLUDE DESTRUCTIVE COMMANDS
    * Each non-layer keypress moves to BASE (exception: rotary, arrow keys, enter)
    * Stand-alone non-destructive commands are executed instantly (e.g. git status)
    *

*/
[_RAISE1] = LAYOUT_planck_grid(
    ROTARY,  KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    BSPC_DEL,
    CTL_TAB, KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSPO, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    ALT_ESC, _______, _______, _______,   TD(RAISE), SPC_CAPS, SPC_CAPS, TD(LOWER), _______, _______, _______, KC_RGUI
),

/* Lower II - navigation

    |-----------------------------------------------------------------------------------------------|
    | Rotary| L Ck  |  M up |  R ck |       |       |       |       | Ctrl- | S up  | Ctrl+ |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |  M lt |  M dn |  M rt |       |       |       |       | S lt  | S dn  | S rt  |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       | LOWER |      BASE     | RAISE |   Lt  |   Dn  |   Up  |   Rt  |
    |-----------------------------------------------------------------------------------------------|

    *
    *
    *

*/
[_LOWER2] = LAYOUT_planck_grid(
    ROTARY,  KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    BSPC_DEL,
    CTL_TAB, KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSPO, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    ALT_ESC, _______, _______, _______,   TD(RAISE), SPC_CAPS, SPC_CAPS, TD(LOWER), _______, _______, _______, KC_RGUI
),

/* Raise II - functions and dynamic macros

    |-----------------------------------------------------------------------------------------------|
    | Rotary|  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |  F11  |  F12  |  F13  |  F14  |  F15  |  F16  |  F17  |  F18  |  F19  |  F20  |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
    |       |       |       |       | LOWER |      BASE     | RAISE |       |       |       |       |
    |-----------------------------------------------------------------------------------------------|

    *
    * Each non-layer keypress moves to BASE (exception: rotary)
    *
    * TODO: Add dynamic macro to this layer
    *

*/
[_RAISE2] = LAYOUT_planck_grid(
    ROTARY,  KC_Q,      KC_W,    KC_E,    KC_R,      KC_T,     KC_Y,     KC_U,      KC_I,    KC_O,    KC_P,    BSPC_DEL,
    CTL_TAB, KC_A,      KC_S,    KC_D,    KC_F,      KC_G,     KC_H,     KC_J,      KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSPO, KC_Z,      KC_X,    KC_C,    KC_V,      KC_B,     KC_N,     KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    ALT_ESC, _______, _______, _______,   TD(RAISE), SPC_CAPS, SPC_CAPS, TD(LOWER), _______, _______, _______, KC_RGUI
),

};

// custom sounds - move to config.h
#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)

    #define ONEUP_SOUND         QD_NOTE(_E5), QD_NOTE(_G5), QD_NOTE(_E6), QD_NOTE(_C5), QD_NOTE(_D5), HD_NOTE(_G6)

    // layer sounds
    //#define QWERTY_LAYER_SOUND  H__NOTE(_D5), W__NOTE(_G5), H__NOTE(_D5), W__NOTE(_F5)
    #define SYMBOL_LAYER_SOUND  H__NOTE(_A5), H__NOTE(_E5), H__NOTE(_F5)
    #define NAV_LAYER_SOUND     H__NOTE(_D5), H__NOTE(_F5), H__NOTE(_C5)
    #define MOUSE_LAYER_SOUND   H__NOTE(_D5), H__NOTE(_F5), H__NOTE(_C5)

    #define CLI_LAYER_SOUND     W__NOTE(_G4), H__NOTE(_A4), H__NOTE(_C4)
    #define ADJUST_LAYER_SOUND  W__NOTE(_G4), H__NOTE(_A4), H__NOTE(_C4)

    // button sounds
    #define CAPS_ON_SOUND       H__NOTE(_A4), H__NOTE(_E5)
    #define CAPS_OFF_SOUND      H__NOTE(_E5), H__NOTE(_A4)
    #define SAVE_SOUND          ONEUP_SOUND
    #define COPY_SOUND          H__NOTE(_C4), H__NOTE(_G4)
    #define PASTE_SOUND         H__NOTE(_G4), H__NOTE(_C4)
    #define CUT_SOUND           W__NOTE(_G4), H__NOTE(_A4), H__NOTE(_C4)
    #define UNDO_SOUND          W__NOTE(_G4), H__NOTE(_A4), H__NOTE(_C4)
    #define REDO_SOUND          W__NOTE(_G4), H__NOTE(_A4), H__NOTE(_C4)
#endif

#ifdef AUDIO_ENABLE
    float qwerty_song[][2]      = SONG(QWERTY_SOUND);
    float colemak_song[][2]     = SONG(COLEMAK_SOUND);
    float symbol_song[][2]      = SONG(SYMBOL_LAYER_SOUND);
    float nav_song[][2]         = SONG(NAV_LAYER_SOUND);
    float mouse_song[][2]       = SONG(MOUSE_LAYER_SOUND);
    float cli_song[][2]         = SONG(CLI_LAYER_SOUND);
    float adjust_song[][2]      = SONG(ADJUST_LAYER_SOUND);

    float caps_on_song[][2]     = SONG(CAPS_ON_SOUND);
    float caps_off_song[][2]    = SONG(CAPS_OFF_SOUND);
    float save_song[][2]        = SONG(SAVE_SOUND);
    float copy_song[][2]        = SONG(COPY_SOUND);
    float paste_song[][2]       = SONG(PASTE_SOUND);
    float cut_song[][2]         = SONG(CUT_SOUND);
    float undo_song[][2]        = SONG(UNDO_SOUND);
    float redo_song[][2]        = SONG(REDO_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);

    // play layer activation audio
    #ifdef AUDIO_ENABLE
        switch (get_highest_layer(state)) {
            case _QWERTY:
                //PLAY_SONG(qwerty_song);
                break;
            case _COLEMAK:
                PLAY_SONG(colemak_song);
                break;
            case _SYMBOLS:
                PLAY_SONG(symbol_song);
                break;
            case _NAV:
                PLAY_SONG(nav_song);
                break;
            case _MOUSE:
                PLAY_SONG(mouse_song);
                break;
            case _CLI:
                PLAY_SONG(cli_song);
                break;
            case _ADJUST:
                PLAY_SONG(adjust_song);
                break;
            default:
                break;
        }
    #endif

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // state variables
    static bool caps_active = false;
    static bool caps_pressed = false;
    static bool del_pressed = false;

    // custom keycode logic
    switch (keycode) {
        // send DELETE if BACKSPACE pressed with LCTRL
        case BSPC_DEL:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    unregister_code(KC_LCTL);
                    register_code(KC_DELETE);
                    del_pressed = true;
                }
                else {
                    register_code(KC_BSPACE);
                }
            }
            else {
                if (del_pressed) {
                    unregister_code(KC_DELETE);
                    register_code(KC_LCTL);
                    del_pressed = false;
                }
                else {
                    unregister_code(KC_BSPACE);
                }
            }
            return false;
        // send CAPS LOCK if SPACE pressed with LCTRL
        case SPC_CAPS:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LCTL)) {
                    tap_code(KC_CAPSLOCK);
                    caps_pressed = true;

                    #ifdef AUDIO_ENABLE
                        caps_active = !caps_active;
                        if (caps_active) {
                            PLAY_SONG(caps_on_song);
                        }
                        else {
                            PLAY_SONG(caps_off_song);
                        }
                    #endif
                }
                else {
                    register_code(KC_SPACE);
                }
            }
            else {
                if (caps_pressed) {
                    caps_pressed = false;
                }
                else {
                    unregister_code(KC_SPACE);
                }
            }
            return false;

        // play sound on CTRL+S
        case KC_S:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(save_song);
                #endif
            }
            return true;
        // play sound on CTRL+C
        case KC_C:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(copy_song);
                #endif
            }
            return true;
        // play sound on CTRL+V
        case KC_V:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(paste_song);
                #endif
            }
            return true;
        // play sound on CTRL+X
        case KC_X:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(cut_song);
                #endif
            }
            return true;
        // play sound on CTRL+Z
        case KC_Z:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(undo_song);
                #endif
            }
            return true;
        // play sound on CTRL+Y
        case KC_Y:
            if (record->event.pressed && (get_mods() & (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)))) {
                #ifdef AUDIO_ENABLE
                    PLAY_SONG(redo_song);
                #endif
            }
            return true;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            }
            else {
                layer_off(_RAISE);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            }
            else {
                layer_off(_LOWER);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        }
    return true;
}

// Return an int corresponding to the tap dance that should be executed
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) {
            return SINGLE_TAP;
        }
        else {
            return SINGLE_HOLD;
        }
    }
    else if (state->count == 2) {
        return DOUBLE_TAP;
    }
    else if (state->count == 3) {
        return TRIPLE_TAP;
    } else return 8; // this method may expand to work for more presses
}

void raise_finished(qk_tap_dance_state_t *state, void *user_data) {
    raise_state = cur_dance(state);
    switch (raise_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            layer_on(_RAISE1);
            break;
        case DOUBLE_TAP:
            layer_on(_RAISE2);
            break;
        case TRIPLE_TAP:
            layer_on(_RAISE3);
            break;
    }
}

void raise_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (raise_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            layer_off(_RAISE1);
            break;
        case DOUBLE_TAP:
            layer_off(_RAISE2);
            break;
        case TRIPLE_TAP:
            layer_off(_RAISE3);
            break;
    }
    raise_state = 0;
}

void lower_finished(qk_tap_dance_state_t *state, void *user_data) {
    lower_state = cur_dance(state);
    switch (lower_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            layer_on(_LOWER1);
            break;
        case DOUBLE_TAP:
            layer_on(_LOWER2);
            break;
        case TRIPLE_TAP:
            layer_on(_LOWER3);
            break;
    }
}

void lower_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lower_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            layer_off(_LOWER1);
            break;
        case DOUBLE_TAP:
            layer_off(_LOWER2);
            break;
        case TRIPLE_TAP:
            layer_off(_LOWER3);
            break;
    }
    lower_state = 0;
}

void bko_finished(qk_tap_dance_state_t *state, void *user_data) {
    bko_state = cur_dance(state);
    switch (bko_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            register_code16(KC_LBRACKET);
            break;
        case DOUBLE_TAP:
            register_code16(KC_LEFT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            register_code16(KC_LEFT_ANGLE_BRACKET);
            break;
    }
}

void bko_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (bko_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            unregister_code16(KC_LBRACKET);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LEFT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            unregister_code16(KC_LEFT_ANGLE_BRACKET);
            break;
    }
    bko_state = 0;
}

void bkc_finished(qk_tap_dance_state_t *state, void *user_data) {
    bkc_state = cur_dance(state);
    switch (bkc_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            register_code16(KC_RBRACKET);
            break;
        case DOUBLE_TAP:
            register_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            register_code16(KC_RIGHT_ANGLE_BRACKET);
            break;
    }
}

void bkc_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (bkc_state) {
        case SINGLE_HOLD:
        case SINGLE_TAP:
            unregister_code16(KC_RBRACKET);
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RIGHT_CURLY_BRACE);
            break;
        case TRIPLE_TAP:
            unregister_code16(KC_RIGHT_ANGLE_BRACKET);
            break;
    }
    bkc_state = 0;
}

void macro_fn(qk_tap_dance_state_t *state, void *user_data) {
    static bool macro_recording = false;
    if (macro_recording) {
        tap_code16(DYN_REC_STOP);
        macro_recording = false;
    }
    else {
        switch (cur_dance(state)) {
            case SINGLE_TAP:
            case SINGLE_HOLD:
                tap_code16(DYN_MACRO_PLAY1);
                break;
            case DOUBLE_TAP:
                tap_code16(DYN_REC_START1);
                macro_recording = true;
                break;
        }
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_finished, raise_reset),
    [LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lower_finished, lower_reset),
    [BKO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bko_finished, bko_reset),
    [BKC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bkc_finished, bkc_reset),
    [MACRO] = ACTION_TAP_DANCE_FN(macro_fn),
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_ADJUST)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
            #ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_DOWN);
            #else
                tap_code(KC_PGDN);
            #endif
        } else {
            #ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_UP);
            #else
                tap_code(KC_PGUP);
            #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

// Returns false for keycodes that should still be processed in music mode
bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
