/* Copyright 2020 Casey Webster <casey@e1337.dev>
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
#include "raw_hid.h"
#define RAW_EPSIZE 8
#include <stdio.h>

char wpm_str[10];
uint16_t wpm_graph_timer = 0;

#ifdef COMBO_ENABLE
enum combos {
    ZX_COPY,
    CV_PASTE
};

const uint16_t PROGMEM copy_combo[]  = { KC_Z, KC_X, COMBO_END };
const uint16_t PROGMEM paste_combo[] = { KC_C, KC_V, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    [ZX_COPY]  = COMBO(copy_combo, LCTL_T(KC_C)),
    [CV_PASTE] = COMBO(paste_combo, LCTL_T(KC_V))
};
#endif

enum custom_keycodes {
    KC_LCCL = SAFE_RANGE
};

enum layers {
    _QWERTY = 0,
    _COLEMAK,
    _GAME,
    _FN,
    _SYMBOLS,
    _NUM,
    _NAV,
    _MOUSE,
    _MEDIA
};

// shortcuts for certain keys to use LAYOUT_kc()
#define KC_TO(a)  TO(a)
#define KC_DF(a)  DF(a)
#define KC_KITTY(a)  C_S_T(KC_##a)
#define KC_I3(a)  SCMD_T(KC_##a)
#define KC_TOG   RGB_TOG
#define KC_SAI   RGB_SAI
#define KC_HUI   RGB_HUI
#define KC_VAI   RGB_VAI
#define KC_MOD   RGB_MOD
#define KC_RST   RESET
#define KC_CTLBS CTL_T(KC_BSPC)
#define KC_TT(m,a)  m##_T(KC_##a)
#define KC_FN(a) LT(_FN, KC_##a)
#define KC_SYM(a) LT(_SYMBOLS, KC_##a)
#define KC_NUM(a) LT(_NUM, KC_##a)
#define KC_NAV(a) LT(_NAV, KC_##a)
#define KC_MED(a) LT(_MEDIA, KC_##a)
#define KC_MSE(a) LT(_MOUSE, KC_##a)
#define KC_ALTCL LALT_T(KC_CAPS)

#define LAYOUT_kyria_base( \
    L01, L02, L03, L04, L05, R05, R04, R03, R02, R01, \
    L11, L12, L13, L14, L15, R15, R14, R13, R12, R11, \
    L21, L22, L23, L24, L25, R25, R24, R23, R22, R21,  \
              L33, L34, L35, R35, R34, R33 \
    ) \
    LAYOUT_kyria_wrapper ( \
    KC_GRV,   L01, L02, L03, L04, L05,                          R05, R04, R03, R02, R01, KC_BSLS, \
    KC_CTLBS, L11, L12, L13, L14, L15,                          R15, R14, R13, R12, R11, KC_QUOT, \
    KC_EQL,   L21, L22, L23, L24, L25, KC_LCCL, KC_LGUI, KC_ALTCL, KC_LSFT, R25, R24, R23, R22, R21, KC_MINS, \
         SCMD_T(KC_LBRC), C_S_T(KC_MINS), L33, L34, L35, R35, R34, R33, TO(_GAME), KC_PSCR \
    )
#define LAYOUT_kyria_base_wrapper(...)       LAYOUT_kyria_base(__VA_ARGS__)

#define _______QWERTY_L1______        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
#define _______QWERTY_L2______ LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),        KC_G
#define _______QWERTY_L3______        KC_Z,         KC_X,         KC_C,         KC_V,         KC_B
#define _______QWERTY_R1______        KC_Y,         KC_U,         KC_I,         KC_O,         KC_P
#define _______QWERTY_R2______        KC_H,  RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN)
#define _______QWERTY_R3______        KC_N,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH

#define _______COLEMAK_L1_____        KC_Q,         KC_W,         KC_F,         KC_P,         KC_B
#define _______COLEMAK_L2_____ LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),        KC_G
#define _______COLEMAK_L3_____        KC_Z,         KC_X,         KC_C,         KC_D,         KC_V
#define _______COLEMAK_R1_____        KC_J,         KC_L,         KC_U,         KC_Y,         KC_QUOT
#define _______COLEMAK_R2_____        KC_M,  RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O)
#define _______COLEMAK_R3_____        KC_K,         KC_H,         KC_COMM,      KC_DOT,       KC_SLSH

#define _______THUMBS_L_______ LT(_MOUSE,KC_TAB), LT(_NAV,KC_SPC),  LT(_MEDIA,  KC_ESC)
#define _______THUMBS_R_______ LT(_FN,   KC_ENT), LT(_NUM,KC_BSPC), LT(_SYMBOLS,KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT_kyria_base_wrapper(
 /* ,-----------------------.                 ,-----------------------. */
      _______QWERTY_L1______,                 _______QWERTY_R1______,
      _______QWERTY_L2______,                 _______QWERTY_R2______,
      _______QWERTY_L3______,                 _______QWERTY_R3______,
              _______THUMBS_L_______,  _______THUMBS_R_______
 /*           `---------------------'  `------------------------------' */
    ),
/*
 * Base Layer: QWERTY
 */
    [_COLEMAK] = LAYOUT_kyria_base_wrapper(
 /* ,-----------------------.                 ,-----------------------. */
      _______COLEMAK_L1_____,                 _______COLEMAK_R1_____,
      _______COLEMAK_L2_____,                 _______COLEMAK_R2_____,
      _______COLEMAK_L3_____,                 _______COLEMAK_R3_____,
              _______THUMBS_L_______,  _______THUMBS_R_______
 /*           `---------------------'  `------------------------------' */
    ),
    // symbols and mouse
    [_SYMBOLS] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    RCBR,  AMPR,  ASTR,  LPRN,  LCBR,                                 TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   COLN,   DLR,  PERC,  CIRC,  PLUS,                                 TRNS,  LSFT,  LCTL,  LALT,  LGUI,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   TILD,  EXLM,  AT,    HASH,  PIPE,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,   TRNS, RALT,  TRNS,  TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  LPRN,  RPRN,  UNDS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------' */
    ),
    [_NUM] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    RBRC,   7,     8,     9,    LBRC,                                 TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   SCLN,   4,     5,     6,    EQL,                                  TRNS,  LSFT,  LCTL,  LALT,  LGUI,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   GRV,    1,     2,     3,    SLSH,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RALT,  TRNS,  TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  DOT,    0,    MINS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------' */
      ),
    // media and fn
    [_FN] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    F12,    F7,    F8,    F9,  SYSREQ,                                TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   F11,    F4,    F5,    F6,   TRNS,                                 TRNS,  LSFT,  LCTL,  LALT,  LGUI,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   F10,    F1,    F2,    F3,   BSLS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RALT,  TRNS,  TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  MENU,  SLSH,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------' */
      ),
    [_NAV] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 UNDO,  CUT,   COPY,  PSTE,  AGIN,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   LGUI,  LALT,  LCTL,  LSFT,  TRNS,                                 LEFT,  DOWN,   UP,   RGHT,  CAPS,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   TRNS,  RALT,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  HOME,  PGDN,  PGUP,  END,   INS,   TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------' */
      ),
    [_MOUSE] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 MS_L,  MS_D,  MS_U,  MS_R,  TRNS,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  WH_L,  WH_D,  WH_U,  WH_R,  TRNS,  TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     BTN1,  BTN3,  BTN2,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------'                        */
      ),
    [_MEDIA] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
       RST,    TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                  TOG,   MOD,   HUI,   SAI,   VAI,  RST,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
       TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 MPRV,  VOLD,  VOLU,  MNXT,  TRNS,  TRNS,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
       TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
                             TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     MSTP,  MPLY,  MUTE,  TRNS,  TRNS
 /*                        `----------------------------------'  `----------------------------------'                        */
     ),
 // GAME layout -- qwerty without homerow mods
    [_GAME] = LAYOUT_kc(
 /* ,-------------------------------------------.                              ,-------------------------------------------. */
      GRV,      Q,     W,     E,     R,    T,                                     Y,     U,     I,     O,     P,    BSLS,
 /* |--------+------+------+------+------+------|                              |------+------+------+------+------+--------| */
      CTLBS,    A,     S,     D,     F,    G,                                     H,     J,     K,     L,    SCLN,  QUOT,
 /* |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------| */
      LSPO,     Z,     X,     C,     V,    B,     LCTL,  LGUI,     RALT,  RSFT,   N,     M,    COMM,  DOT,   SLSH,  RSPC,
 /* `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------' */
           I3(LBRC),  KITTY(MINS), MSE(TAB), NAV(SPC), MED(ESC), FN(ENT), NUM(BSPC), SYM(DEL), TO(_QWERTY),     PSCR
 /*                        `----------------------------------'  `----------------------------------' */
    ),
 //  * Layer template
 //
 //    [_LAYERINDEX] = LAYOUT_kc(
 // ,-------------------------------------------.                              ,-------------------------------------------.
 //    TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,
 // |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 //    TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,                                 TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,
 // |--------+------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------+--------|
 //    TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,  TRNS,
 // `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 //                          TRNS,  TRNS,  TRNS,  TRNS,  TRNS,     TRNS,  TRNS,  TRNS,  TRNS,  TRNS
 //                        `----------------------------------'  `----------------------------------'
 //    ),
};

static void send_layer_via_hid(int layer) {
    uint8_t data[RAW_EPSIZE];
    data[0] = 1;
    data[1] = layer;
    raw_hid_send((uint8_t*)data, sizeof(data));
    return;
}

/* RGB LIGHT LAYERS
const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_AZURE}
);

const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_RED}
);

const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_TURQUOISE}
);

const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 10, HSV_PURPLE}
);
*/

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_BLUE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    send_layer_via_hid(state);
    switch (get_highest_layer(state)) {
        case _QWERTY:
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case _SYMBOLS:
            rgblight_sethsv_noeeprom(HSV_GREEN);
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(HSV_CORAL);
            break;
        case _NAV:
            rgblight_sethsv_noeeprom(HSV_GOLDENROD);
            break;
        case _FN:
            rgblight_sethsv_noeeprom(HSV_PINK);
            break;
        case _MEDIA:
            rgblight_sethsv_noeeprom(HSV_MAGENTA);
            break;
        case _MOUSE:
            rgblight_sethsv_noeeprom(HSV_TURQUOISE);
            break;
        case _GAME:
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
    }
    return state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        // canvas is 128x64.  need 16 padding
        // 80x32
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x60, 0xe0, 0xf0, 0xfe, 0xfe, 0xf0, 0x60, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x0c, 0x1c, 0x3c, 0x7c, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x7c, 0xf8, 0xe0, 0x60, 0x20, 0x10, 0x10, 0x0c, 0x0f, 0x09, 0x08, 0x00, 0x09, 0x9b, 0x5c, 0x50, 0x10, 0x20, 0x40, 0xe0, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x78, 0x38, 0x38, 0x10, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x17, 0x15, 0x3d, 0xef, 0xaf, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x10, 0x00, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x40, 0xa0, 0xbf, 0xff, 0x3f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(logo, sizeof(logo));

    oled_advance_page(false);
    oled_advance_page(false);
    oled_advance_page(false);
    oled_advance_page(false);

#ifdef COMBO_ENABLE
    oled_write_P(PSTR("Combos enabled: "), false);
    if (is_combo_enabled()) {
        oled_write_P(PSTR("Yes\n"), false);
    } else {
        oled_write_P(PSTR("No\n"), false);
    }
#endif

    uint8_t mods = get_mods() | get_weak_mods();
    oled_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR("     "), false);
    oled_write_P(PSTR("\n"), false);

#ifdef WPM_ENABLE
    // Write WPM
    sprintf(wpm_str, "WPM: %03d", get_current_wpm());
    //oled_write_P(PSTR("\n"), false);
    oled_write(wpm_str, false);
#endif
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.3\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Shifted Sym\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Fn\n"), false);
            break;
        case _GAME:
            oled_write_P(PSTR("Game\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media keys\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse keys\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    uint8_t mods = get_mods() | get_weak_mods();
    oled_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHFT ") : PSTR("     "), false);
    oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_logo();
    }
}
#endif


#ifdef RAW_ENABLE
void raw_hid_receive(uint8_t *data, uint8_t length) {
    // messages from host
    // add ability to set color
    raw_hid_send(data, length);
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_colon_timer;

    switch (keycode) {
        case KC_LCCL:
            if (record->event.pressed) {
                my_colon_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LCTL);
                if (timer_elapsed(my_colon_timer) < TAPPING_TERM) {
                    SEND_STRING(":");
                }
            }
            return false;
    }
    return true;
}
