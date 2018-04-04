#include "dz60.h"
#include "action_layer.h"

#define ______ KC_TRNS
#define XXXXXX KC_TRNS // dead key, TODO: fix this

#define _DEF 0 // default (qwerty)
#define _SYM 1 // symbols
#define _NUM 2 // numbers & F*
#define _MED 3 // media

#define SP_NOPE LALT(KC_F4) // alt + f4
#define SP_LESS LSFT(KC_COMMA)
#define SP_MORE LSFT(KC_DOT)
#define SP_SPC  MT(MOD_LSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* default qwerty
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  /  │ del │ bsp │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │  tab   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
     * │   tab   │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │    enter    │
     * ├─────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬─────┬─────┤
     * │   shift   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │     │XXXXX│ up  │ fn3 │
     * ├──────┬────┴─┬───┴──┬──┴─────┴─┬───┴──┬──┴─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │ ctrl │  os  │ alt  │   fn1    │ fn2  │       space        │ alt │ctrl │left │down │right│
     * └──────┴──────┴──────┴──────────┴──────┴────────────────────┴─────┴─────┴─────┴─────┴─────┘
    */
    KEYMAP_DIRECTIONAL(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_SLSH, KC_DEL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, XXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SPC, KC_UP, MO(_MED),
        KC_LCTL, KC_LGUI, KC_LALT, MO(_SYM), MO(_NUM), KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* symbols (fn1)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │   ^    │  @  │  #  │  $  │  %  │  &  │  *  │  _  │  -  │  +  │  =  │     │     │        │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
     * │    `    │  '  │  {  │  [  │  (  │  !  │  ?  │  )  │  ]  │  }  │  "  │     │             │
     * ├─────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬─────┬─────┤
     * │           │     │     │  |  │  /  │  <  │  >  │  \  │  |  │     │     │XXXXX│pgup │     │
     * ├──────┬────┴─┬───┴──┬──┴─────┴─┬───┴──┬──┴─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │      │      │      │▒▒▒▒▒▒▒▒▒▒│      │     backspace      │     │     │home │pgdwn│ end │
     * └──────┴──────┴──────┴──────────┴──────┴────────────────────┴─────┴─────┴─────┴─────┴─────┘
    */
    KEYMAP_DIRECTIONAL(
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
        KC_CIRC, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_AMPR, KC_ASTR, KC_UNDS, KC_MINS, KC_PLUS, KC_EQUAL, ______, ______, ______,
        KC_GRV, KC_QUOT, KC_LCBR, KC_LBRC, KC_LPRN, KC_EXLM, KC_QUES, KC_RPRN, KC_RBRC, KC_RCBR, KC_DQT, ______, ______,
        ______, XXXXXX, ______, ______, KC_PIPE, KC_SLSH, SP_LESS, SP_MORE, KC_BSLS, KC_PIPE, ______, ______, KC_PGUP, ______,
        ______, ______, ______, ______, ______, KC_BSPC, ______, ______, KC_HOME, KC_PGDN, KC_END
    ),

    /* F* and capitalized keys (fn2)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │altF4│ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │     │     │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │        │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  {  │  }  │   |    │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
     * │         │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  :  │  "  │             │
     * ├─────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬─────┬─────┤
     * │           │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  <  │  >  │     │XXXXX│     │     │
     * ├──────┬────┴─┬───┴──┬──┴─────┴─┬───┴──┬──┴─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │      │      │      │          │▒▒▒▒▒▒│                    │     │     │     │     │     │
     * └──────┴──────┴──────┴──────────┴──────┴────────────────────┴─────┴─────┴─────┴─────┴─────┘
    */
    KEYMAP_DIRECTIONAL(
        SP_NOPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ______, ______,
        ______, LSFT(KC_Q), LSFT(KC_W), LSFT(KC_E), LSFT(KC_R), LSFT(KC_T), LSFT(KC_Y), LSFT(KC_U), LSFT(KC_I), LSFT(KC_O), LSFT(KC_P), LSFT(KC_LBRC), LSFT(KC_RBRC), LSFT(KC_BSLS),
        ______, LSFT(KC_A), LSFT(KC_S), LSFT(KC_D), LSFT(KC_F), LSFT(KC_G), LSFT(KC_H), LSFT(KC_J), LSFT(KC_K), LSFT(KC_L), LSFT(KC_SCLN), LSFT(KC_QUOT), ______,
        ______, XXXXXX, LSFT(KC_Z), LSFT(KC_X), LSFT(KC_C), LSFT(KC_V), LSFT(KC_B), LSFT(KC_N), LSFT(KC_M), LSFT(KC_COMM), LSFT(KC_DOT), ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
    ),

    /* media (fn3)
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │        │     │     │     │     │     │     │     │     │     │ptscr│     │     │        │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┤
     * │         │     │     │     │     │     │     │     │     │     │     │     │             │
     * ├─────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬─────┬─────┤
     * │           │     │     │     │     │     │     │     │     │     │     │XXXXX│vol+ │▒▒▒▒▒│
     * ├──────┬────┴─┬───┴──┬──┴─────┴─┬───┴──┬──┴─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┤
     * │      │      │      │          │      │                    │     │     │prev │vol- │next │
     * └──────┴──────┴──────┴──────────┴──────┴────────────────────┴─────┴─────┴─────┴─────┴─────┘
    */
    KEYMAP_DIRECTIONAL(
        RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, ______, ______, ______, ______, ______, ______, ______, RGB_MOD,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_PSCREEN, ______, ______, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,
        ______, XXXXXX, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_VOLU, ______,
        ______, ______, ______, ______, ______, ______, ______, ______, KC_MPRV, KC_VOLD, KC_MNXT
    ),
};
