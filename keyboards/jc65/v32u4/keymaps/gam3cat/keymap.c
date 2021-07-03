/*Copyright 2021 @Gam3cat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include "gam3cat.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*#### _BL: Base Layer - Mostly standard 65% QWERTY layout.
    *  .---------------------------------------------------------------.
    *  |GrE|1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backsp |Ins|
    *  |---------------------------------------------------------------|
    *  |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    |Del|
    *  |---------------------------------------------------------------|
    *  |FnCaps|A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |PgU|
    *  |---------------------------------------------------------------|
    *  |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift |Up |PgD|
    *  |---------------------------------------------------------------|
    *  |Ctrl|Gui |Alt |      Space             |RAlt |Ctrl |Lft|Dwn|Rgt|
    *  *---------------------------------------------------------------*
    */
    [_BL] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_INS,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,
        FN_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI,          KC_LALT, KC_SPC,           KC_SPC,           KC_SPC,           KC_RALT, KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*#### _WL: Workman Layer.
    *  .---------------------------------------------------------------.
    *  |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |
    *  |---------------------------------------------------------------|
    *  |     |Q  |D  |R  |W  |B  |J  |F  |U  |P  |;  |[  |]  |\    |   |
    *  |---------------------------------------------------------------|
    *  |      |A  |S  |H  |T  |G  |Y  |N  |E  |O  |I  |'  |        |   |
    *  |---------------------------------------------------------------|
    *  |        |Z  |X  |M  |C  |V  |K  |L  |,  |.  |/  |      |   |   |
    *  |---------------------------------------------------------------|
    *  |    |    |    |                        |     |     |   |   |   |
    *  *---------------------------------------------------------------*
    */
    [_WL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN, _______, _______, _______, _______,
        _______,          KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , _______, _______,          _______,
        _______, _______, KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   , KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH,          _______, _______, _______,
        _______, _______,          _______, _______,          _______,          _______,          _______, _______, _______, _______, _______, _______
    ),
    /*#### _NL: Norman Layer.
    *  .---------------------------------------------------------------.
    *  |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |
    *  |---------------------------------------------------------------|
    *  |     |Q  |W  |D  |F  |K  |J  |U  |R  |L  |;  |[  |]  |\    |   |
    *  |---------------------------------------------------------------|
    *  |      |A  |S  |E  |T  |G  |Y  |N  |I  |O  |H  |'  |        |   |
    *  |---------------------------------------------------------------|
    *  |        |Z  |X  |C  |V  |B  |P  |M  |,  |.  |/  |      |   |   |
    *  |---------------------------------------------------------------|
    *  |    |    |    |                        |     |     |   |   |   |
    *  *---------------------------------------------------------------*
    */
    [_NL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          KC_Q   , KC_W   , KC_D   , KC_F   , KC_K   , KC_J   , KC_U   , KC_R   , KC_L   , KC_SCLN, _______, _______, _______, _______,
        _______,          KC_A   , KC_S   , KC_E   , KC_T   , KC_G   , KC_Y   , KC_N   , KC_I   , KC_O   , KC_H   , _______, _______,          _______,
        _______, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_P   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          _______, _______, _______,
        _______, _______,          _______, _______,          _______,          _______,          _______, _______, _______, _______, _______, _______
    ),
    /*#### _DL: Dvorak Layer.
    *  .---------------------------------------------------------------.
    *  |   |   |   |   |   |   |   |   |   |   |   |[  |]  |       |   |
    *  |---------------------------------------------------------------|
    *  |     |'  |,  |.  |P  |Y  |F  |G  |C  |R  |L  |/  |=  |\    |   |
    *  |---------------------------------------------------------------|
    *  |      |A  |O  |E  |U  |I  |D  |H  |T  |N  |S  |-  |        |   |
    *  |---------------------------------------------------------------|
    *  |        |;  |Q  |J  |K  |X  |B  |M  |W  |V  |Z  |      |   |   |
    *  |---------------------------------------------------------------|
    *  |    |    |    |                        |     |     |   |   |   |
    *  *---------------------------------------------------------------*
    */
    [_DL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______,
        _______,          KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   , KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_EQL , _______, _______,
        _______,          KC_A   , KC_O   , KC_E   , KC_U   , KC_I   , KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS, _______,          _______,
        _______, _______, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   ,          _______, _______, _______,
        _______, _______,          _______, _______,          _______,          _______,          _______, _______, _______, _______, _______, _______
    ),
    /*#### _CL: Colmak Layer.
    *  .---------------------------------------------------------------.
    *  |   |   |   |   |   |   |   |   |   |   |   |-  |=  |       |   |
    *  |---------------------------------------------------------------|
    *  |     |Q  |W  |F  |P  |G  |J  |L  |U  |Y  |;  |[  |]  |\    |   |
    *  |---------------------------------------------------------------|
    *  |      |A  |R  |S  |T  |D  |H  |N  |E  |I  |O  |'  |        |   |
    *  |---------------------------------------------------------------|
    *  |        |Z  |X  |C  |V  |B  |K  |M  |,  |.  |/  |      |   |   |
    *  |---------------------------------------------------------------|
    *  |    |    |    |                        |     |     |   |   |   |
    *  *---------------------------------------------------------------*
    */
    [_CL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______, _______, _______, _______,
        _______,          KC_A   , KC_R   , KC_S   , KC_T   , KC_D   , KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , _______, _______,          _______,
        _______, _______, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,          _______, _______, _______,
        _______, _______,          _______, _______,          _______,          _______,          _______, _______, _______, _______, _______, _______
    ),
    /*#### _FL: Function Layer.
    *  .---------------------------------------------------------------.
    *  |Web|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|SLock  |PSc|
    *  |---------------------------------------------------------------|
    *  |Fn_AL|   |   |   |   |   |   |   |   |   |   |   |   |     |Pau|
    *  |---------------------------------------------------------------|
    *  |FnCaps|   |   |   |   |   |Lft|Dwn|Up |Rgt|   |   |        |Hme|
    *  |---------------------------------------------------------------|
    *  |        |   |   |   |   |   |   |   |   |   |   |VlMute|VlU|End|
    *  |---------------------------------------------------------------|
    *  |    |    |Menu|      SP4               |     |     |WBk|VlD|WFw|
    *  *---------------------------------------------------------------*
    */
    [_FL] = LAYOUT(
        KC_WEB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_SLCK, KC_PSCR,
        MO(_AL),          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS,
        _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,          KC_HOME,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_MUTE, KC_VOLU, KC_END,
        XXXXXXX, XXXXXXX,          KC_MENU, KC_SP4,           KC_SP4,           KC_SP4,           XXXXXXX, XXXXXXX, XXXXXXX, KC_WBAK, KC_VOLD, KC_WFWD
    ),
    /*#### _AL: Adjust Layer - Keymap select, RGB Underglow, LED backlight, and Dynamic Macro settings.
    *  .---------------------------------------------------------------.
    *  |Rev|Tog|Mod|H- |H+ |S- |S+ |V- |V+ |   |BLT|BL-|BL+|       |MP1|
    *  |---------------------------------------------------------------|
    *  |Fn_AL|_BL|_WL|   |   |   |   |   |   |   |   |   |   |     |MR1|
    *  |---------------------------------------------------------------|
    *  |FnCaps|   |   |_DL|   |   |   |   |   |   |   |   |        |MS |
    *  |---------------------------------------------------------------|
    *  |        |   |   |_CL|   |_BL|_NL|   |   |   |   |      |   |MR2|
    *  |---------------------------------------------------------------|
    *  |Rst |    |    |                        |     |     |   |   |MP2|
    *  *---------------------------------------------------------------*
    */
    [_AL] = LAYOUT(
        QMK_REV, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, DM_PLY1,
        _______,          DF(_BL), DF(_WL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_REC1,
        _______,          XXXXXXX, XXXXXXX, DF(_DL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DM_RSTP,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_CL), XXXXXXX, DF(_BL), DF(_NL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, DM_REC2,
        RESET,   XXXXXXX,          XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DM_PLY2
    ),
};
