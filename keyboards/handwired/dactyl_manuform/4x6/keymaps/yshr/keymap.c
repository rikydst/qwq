#include QMK_KEYBOARD_H

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define SFT_SPC  SFT_T(KC_SPC)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define SFT_MHEN SFT_T(KC_MHEN)
#define SFT_HENK SFT_T(KC_HENK)

#define RAISE LT(_RAISE,KC_SPC)
#define LOWER LT(_LOWER,KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  | BSPC |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | CTL  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |   '  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  | SHFT |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               | LEFT |  UP  |                                                         | DOWN |RIGHT |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             | SPC  |RAISE |                             |LOWER | ENT  |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           | OPT  | CMD  | | CMD  | OPT  |
     *                                           |------+------| |------+------|
     *                                           | MHEN | CTL  | | CTL  | HENK |
     *                                           +-------------+ +-------------+
     */
    [_BASE] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        SFT_MHEN,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_HENK,
                          KC_LEFT, KC_UP,                                                  KC_DOWN, KC_RIGHT,
                                            KC_SPC,  RAISE,              LOWER,   KC_ENT,
                                            KC_LOPT, KC_LCMD,            KC_RCMD, KC_ROPT,
                                            SFT_MHEN,KC_LCPO,            KC_RCPC, SFT_HENK
    ),

    /* LOWER
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   !  |   @  |   #  |   $  |   %  |                             |   /  |   7  |   8  |   9  |   -  | DEL  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | CAPS |   ^  |   &  |   *  |   (  |   )  |                             |   *  |   4  |   5  |   6  |   +  | ENT  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   _  |   |  |   -  |   _  |   \  |                             | NLCK |   1  |   2  |   3  |   =  | SHFT |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               | LEFT |  UP  |                                                         |   0  |   .  |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             | ENT  |RAISE |                             |LOWER | SPC  |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           | OPT  | CMD  | | CMD  | OPT  |
     *                                           |------+------| |------+------|
     *                                           | MHEN | CTL  | | CTL  | HENK |
     *                                           +-------------+ +-------------+
     */
/*
    [_LOWER] = LAYOUT(
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_MINS, KC_DEL,
        KC_CAPS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,             KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PENT,
        _______, KC_UNDS, KC_PIPE, KC_MINS, KC_UNDS, KC_BSLS,             KC_NLCK, KC_P1,   KC_P2,   KC_P3,   KC_EQL,  _______,
                          _______, _______,                                                 KC_P0,   KC_PDOT,
                                            KC_ENT,  _______,             _______, KC_SPC,
                                            _______, _______,             _______, _______,
                                            _______, _______,             RESET,   _______
    ),
*/

    [_LOWER] = LAYOUT(
        KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_BTN1, KC_BTN1, KC_BTN2, KC_BTN2, KC_MINS, KC_DEL,
        KC_CAPS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,             KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_PLUS, KC_PENT,
        _______, KC_UNDS, KC_PIPE, KC_MINS, KC_UNDS, KC_BSLS,             KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_EQL,  _______,
                          KC_BTN1, KC_BTN2,                                                 KC_BTN1, KC_BTN2,
                                            KC_ENT,  _______,             _______, KC_SPC,
                                            _______, KC__VOLUP,           _______, _______,
                                            KC_MPLY, KC__VOLDOWN,         RESET,   _______
    ),
    /* RAISE
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ECS  |   1  |   2  |   3  |   4  |   5  |                             |   6  |   7  |   8  |   9  |   0  | BSPC |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | CTL  |   `  |   @  |   #  |   $  |   %  |                             | LEFT | DOWN |  UP  |RIGHT |   ;  |   '  |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   !  |   ?  |   ~  |   (  |   [  |                             |   ]  |   )  |   -  |   +  |   =  | SHFT |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               | LEFT |  UP  |                                                         | DOWN |RIGHT |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             | ENT  |RAISE |                             |LOWER | SPC  |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           | OPT  | CMD  | | CMD  | OPT  |
     *                                           |------+------| |------+------|
     *                                           | MHEN | CTL  | | CTL  | HENK |
     *                                           +-------------+ +-------------+
     */
    [_RAISE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_GRV,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_EXLM, KC_QUES, KC_TILD, KC_LPRN, KC_LBRC,             KC_RBRC, KC_RPRN, _______, _______, KC_EQL,  _______,
                          _______, _______,                                                 _______, _______,
                                            KC_ENT,  _______,             _______, KC_SPC,
                                            KC_BTN1, _______,             KC_BRMU, _______,
                                            _______, _______,             KC_BRMD, _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
