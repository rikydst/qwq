/*
Copyright 2021 MechMaster48 admin@mechbox.net

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
/*

-This is just a diagram that makes it easier for me to see what keys I have bound and where.
-The README has a better image to see the exact keymap.

--Layer 0--
  _________________________________________________________________________________________________
 |[esc]            [1!]-[2@]-[3#]-[4$]-[5%]-[6^]-[7&]-[8*]-[9(]-[0)]-[-_]-[+=]      [  BackSpace  ]|
 |[ Tab ]               [Q]-[W]-[E]-[R]-[T]-[Y]-[U]-[I]-[O]-[P]-[[{]-[]}]                    [ |\ ]|
 |[CapsLock]             [A]-[S]-[D]-[F]-[G]-[H]-[J]-[K]-[L]-[;/:]-['/"]                    [Enter]|
 |[ Shift ]               [Z]-[X]-[C]-[V]-[B]-[N]-[M]-[</,]-[>/.]-[?//]                    [↑][del]|
 |[ctrl][win][alt]        [____________________SPACE__________________][fn/OSL(1)][ctrl][←][↓][→]  |
 |_________________________________________________________________________________________________|




--Layer 1--
  _____________________________________________________________________________________
 |[TO(2)]    [F1]-[F2]-[F3]-[F4]-[F5]-[F6]-[F7]-[F8]-[F9]-[F10]-[F11]-[F12]   [   ▼   ]|
 |[ ▼ ]        [~]-[▼]-[▼]-[▼]-[▼]-[▼]-[PS]-[▼]-[▼]-[▼]-[play/pause]-[▼]      [ QK_BOOT ]|
 |[    ▼    ]        [▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[PU]-[▼]-[▼]               [  ▼  ]|
 |[ Shift ]            [▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[PD]-[▼]           [vol↑]  [ ▼ ]|
 |[ctrl][ ▼ ][alt]    [_________________▼________________] [▼][ ▼ ][←prvs][vol↓][next→]|
 |_____________________________________________________________________________________|



--Layer 2--
  _________________________________________________________________________________________________
 |[ ▼ ]                   [▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]             [     ▼     ]| 
 |[ ▼ ]     [RGBTgg]-[▼]-[Hue+]-[Hue-]-[Sat+]-[Sat-]-[Brt+]-[Brt-]-[RGBmd]-[▼]-[▼]-[▼]    [ QK_BOOT ]| 
 |[    ▼    ]              [▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]                      [  ▼  ]| 
 |[   ▼   ]                  [▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]-[▼]                 [  ▼  ][  ▼  ]| 
 |[  ▼  ][ ▼ ][▼]             [_______________TO(0)________________] [▼][ ▼ ] [  ▼  ][  ▼  ][  ▼  ]| 
 |_________________________________________________________________________________________________|

*/

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GESC,        KC_1,    KC_2,            KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,         KC_EQL,  KC_BSPC,
        KC_TAB,         KC_Q,    KC_W,            KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_RBRC, KC_BSLS,
        CTL_T(KC_CAPS), KC_A,    KC_S,            KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                  KC_ENT,
        KC_LSFT,                 KC_Z,            KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP,   LT(2, KC_DEL),
        KC_LCTL,        KC_LGUI, KC_LALT,                           KC_SPC,                    OSL(1), KC_RCTL,           KC_LEFT,         KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        TO(2),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        _______, KC_GRV, _______, _______, _______, _______, _______, KC_PSCR, _______,  _______, _______, KC_MPLY, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______,          EEP_RST,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, KC_VOLU, KC_MUTE,
        KC_LCTL, _______, KC_LALT,                            TO(0),                     _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [2] = LAYOUT(
        _______, _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______,
        _______, RGB_TOG, _______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_MOD, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, _______, _______,          EEP_RST,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            TO(0),                   _______, _______, _______, _______, _______
    )
};