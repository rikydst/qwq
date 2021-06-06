#include QMK_KEYBOARD_H
#include "config.h"
#include "replicaJunction.h"

#define BSP_SYM LT(L_SYMBOLS, KC_BSPC)
#define SPC_NAV LT(L_NAVIGATION, KC_SPC)
#define EQL_FUN LT(L_FN, KC_EQL)

#define ESC_SFT LSFT_T(KC_ESC)
#define TAB_SFT RSFT_T(KC_TAB)

#define DF_TYPE DF(L_BASE)
#define DF_GAME DF(L_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[L_BASE] = LAYOUT(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,
    KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,
    KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,                   KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,
    KC_ESC, KC_LGUI,KC_TAB, ESC_SFT,BSP_SYM,CTL_DEL,ALT_ENT,SPC_NAV,TAB_SFT,KC_MINS,KC_QUOT,EQL_FUN
),

[L_GAMING] = LAYOUT(
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
    _______,_______,KC_C,   KC_D,   _______,                _______,_______,_______,_______,_______,
    _______,KC_TAB, KC_LALT,KC_LSFT,KC_SPC, KC_LCTL,KC_LALT,KC_BSPC,KC_BTN1,KC_BTN2,KC_BTN3,_______
),

[L_NUMBERS] = LAYOUT(
    _______,_______,_______,_______,_______,                KC_HASH,KC_7,   KC_8,   KC_9,   KC_SLSH,
    _______,_______,_______,_______,_______,                KC_PLUS,KC_4,   KC_5,   KC_6,   KC_ASTR,
    _______,_______,_______,_______,_______,                KC_MINS,KC_1,   KC_2,   KC_3,   KC_BSLS,
    _______,_______,_______,_______,_______,_______,_______,_______,KC_0,   KC_0,   KC_DOT, KC_ENT
),

[L_SYMBOLS] = LAYOUT(
    KC_AT,  KC_LT,  KC_DLR, KC_GT,  XXXXXXX,                XXXXXXX,KC_LBRC,KC_UNDS,KC_RBRC,XXXXXXX,
    KC_BSLS,KC_LPRN,KC_DQUO,KC_RPRN,KC_HASH,                KC_PERC,KC_LCBR,KC_EQL, KC_RCBR,KC_PIPE,
    KC_EXLM,KC_COLN,KC_ASTR,KC_PLUS,XXXXXXX,                XXXXXXX,KC_AMPR,KC_CIRC,KC_TILD,KC_GRV,
    _______,_______,_______,_______,ooooooo,_______,_______,ooooooo,CAPWORD,_______,_______,_______
),

[L_NAVIGATION] = LAYOUT(
    OS_UNDO,OS_CUT, OS_PAST,OS_COPY,OS_SALL,                KC_PGUP,KC_HOME,KC_UP,  KC_END, KC_DEL,
    KC_LGUI,KC_LALT,KC_LSFT,KC_LCTL,_______,                KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_BSPC,
    WIN_V,  _______,_______,OS_FIND,SEARCH,                 _______,SFT_TAB,KC_TAB, KC_APP, KC_PSCR,
    _______,_______,_______,NUMWORD,ooooooo,_______,_______,ooooooo,_______,_______,_______,_______
),

[L_FN] = LAYOUT(
    RESET,  _______,_______,_______,_______,                KC_VOLU,KC_F9,  KC_F10, KC_F11, KC_F12,
    MS_JIGL,_______,_______,_______,_______,                KC_MUTE,KC_F5,  KC_F6,  KC_F7,  KC_F8,
    _______,K_SECR1,K_SECR2,K_SECR3,K_SECR4,                KC_VOLD,KC_F1,  KC_F2,  KC_F3,  KC_F4,
    DF_TYPE,DF_GAME,_______,_______,_______,KC_LCTL,KC_LALT,_______,_______,_______,_______,ooooooo
),

[L_MACROS] = LAYOUT(
    QK_MAKE,_______,DM_REC2,DM_REC1,DM_RSTP,                _______,SHEBANG,_______,_______,_______,
    QK_FLSH,_______,DM_PLY2,DM_PLY1,_______,                PRG_NE, PRG_EQ, PRG_GEQ,PRG_LEQ,PRG_ARR,
    QK_VERS,_______,_______,_______,_______,                _______,PS_ITEM,FS_PIPE,_______,FS_ARR,
    _______,_______,_______,_______,ooooooo,_______,_______,ooooooo,_______,_______,_______,_______
)


// Template
// [L_FUNC] = LAYOUT(
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
//     _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
// ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, L_SYMBOLS, L_NAVIGATION, L_MACROS);
}

