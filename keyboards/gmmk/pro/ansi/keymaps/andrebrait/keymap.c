/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 Andre Brait <andrebrait@gmail.com>

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del          Rotary(Play/Pause)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_INS,           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PSCR,
        _______, _______, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, RGB_HUI, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    /*
    Custom handling of RGB_TOG means it is impossible to toggle the RGB Matrix on and off and we
    need it to be enabled for the CAPS LOCK indicator to work, so enable it and then make sure it
    gets persisted to the EEPROM.
     */
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_enable_noeeprom();
        eeconfig_update_rgb_matrix();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_MOD:
        case RGB_RMOD:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            if (record->event.pressed) {
                if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
                    /* Ignore changes to RGB settings while only using it for CAPS LOCK */
                    return false;
                }
            }
            break;
        case RGB_TOG:
            if (record->event.pressed) {
                if (rgb_matrix_get_flags() == LED_FLAG_ALL) {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                } else {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                }
                eeconfig_update_rgb_matrix();
                return false;
            }
            break;
    }
    return true;
}

void rgb_matrix_indicators_user(void) {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
        rgb_matrix_set_color_all(0x0, 0x0, 0x0);
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(67, 0xFF, 0x0, 0x0); // Left side LED 1
        rgb_matrix_set_color(68, 0xFF, 0x0, 0x0); // Right side LED 1
        rgb_matrix_set_color(70, 0xFF, 0x0, 0x0); // Left side LED 2
        rgb_matrix_set_color(71, 0xFF, 0x0, 0x0); // Right side LED 2
        rgb_matrix_set_color(73, 0xFF, 0x0, 0x0); // Left side LED 3
        rgb_matrix_set_color(74, 0xFF, 0x0, 0x0); // Right side LED 3
        rgb_matrix_set_color(76, 0xFF, 0x0, 0x0); // Left side LED 4
        rgb_matrix_set_color(77, 0xFF, 0x0, 0x0); // Right side LED 4
        rgb_matrix_set_color(80, 0xFF, 0x0, 0x0); // Left side LED 5
        rgb_matrix_set_color(81, 0xFF, 0x0, 0x0); // Right side LED 5
        rgb_matrix_set_color(83, 0xFF, 0x0, 0x0); // Left side LED 6
        rgb_matrix_set_color(84, 0xFF, 0x0, 0x0); // Right side LED 6
        rgb_matrix_set_color(87, 0xFF, 0x0, 0x0); // Left side LED 7
        rgb_matrix_set_color(88, 0xFF, 0x0, 0x0); // Right side LED 7
        rgb_matrix_set_color(91, 0xFF, 0x0, 0x0); // Left side LED 8
        rgb_matrix_set_color(92, 0xFF, 0x0, 0x0); // Right side LED 8
        rgb_matrix_set_color(3, 0xFF, 0x0, 0x0); // CAPS LED
    }
}
#endif
