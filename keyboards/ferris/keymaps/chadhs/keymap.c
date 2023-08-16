/*
Custom keymap created by: Chad Stovern <hello@chadstovern.com>
*/

#include QMK_KEYBOARD_H

enum ferris_layers {
    _COLEMAK_DH,
    _NUM_SYM,
    _FUN_NAV,
    _GAME,
    _GAME_FUN,
};

enum custom_keycodes {
    KVM_1 = SAFE_RANGE,
    KVM_2,
    KVM_3,
    KVM_4,
    VIM_CTLU,
    VIM_CTLD,
};

/* thumb mods */
#define NUM_BSPC LT(_NUM_SYM,KC_BSPC)
#define FUN_SPC LT(_FUN_NAV,KC_SPC)
#define CMD_TAB CMD_T(KC_TAB)
#define CMD_ENT CMD_T(KC_ENT)
#define GFUN_SPC LT(_GAME_FUN,KC_SPC)
#define GOPT_ENT OPT_T(KC_ENT)

/* home row mods */
#define HOME_A SFT_T(KC_A)
#define HOME_R CTL_T(KC_R)
#define HOME_S OPT_T(KC_S)
#define HOME_T CMD_T(KC_T)
#define HOME_BT SFT_T(KC_GRV)
#define HOME_N RCMD_T(KC_N)
#define HOME_E OPT_T(KC_E)
#define HOME_I CTL_T(KC_I)
#define HOME_O SFT_T(KC_O)
#define HOME_QT SFT_T(KC_QUOT)

/* misc mods */
#define GAME_TOG TG(_GAME)
#define SFT_Z SFT_T(KC_Z)
#define SFT_SLSH SFT_T(KC_SLSH)
#define SFT_BSLS SFT_T(KC_BSLS)

/* enables combos.def support: imported after defines so they can be referenced */
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK_DH] = LAYOUT(
/*
    .------.------.------.------.------.            .------.------.------.------.------.
    | Q    | W    | F    | P    | B    |            | J    | L    | U    | Y    | ; :  |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    | A    | R    | S    | T    | G    |            | M    | N    | E    | I    | O    |
    | SFT  | CTL  | OPT  | CMD  |      |            |      | RCMD | OPT  | CTL  | SFT  |
    |------+------+------+------+------|            |------+------+------+------+------|
    | Z    | X    | C    | D    | V    |            | K    | H    | , <  | . >  | / ?  |
    | SFT  |      |      |      |      |            |      |      |      |      | SFT  |
    '------'------'------'------'------'            '------'------'------'------'------'
                            .------.------.      .------.------.
                            | TAB  | BSPC |      | SPC  | ENT  |
                            | CMD  | LNUM |      | LFUN | CMD  |
                            '------'------'      '------'------'
*/
    KC_Q,   KC_W,   KC_F,   KC_P,    KC_B,         KC_J,    KC_L,   KC_U,    KC_Y,   KC_SCLN,
    HOME_A, HOME_R, HOME_S, HOME_T,  KC_G,         KC_M,    HOME_N, HOME_E,  HOME_I, HOME_O,
    SFT_Z,  KC_X,   KC_C,   KC_D,    KC_V,         KC_K,    KC_H,   KC_COMM, KC_DOT, SFT_SLSH,
                            CMD_TAB, NUM_BSPC,     FUN_SPC, CMD_ENT
  ),

    [_NUM_SYM] = LAYOUT(
/*
    commonly used symbols:
    - javascript: ( ) { } ; = > / [ ] + _ |
    - clojure:    ( ) [ ] : ; / { } - > = _ +
    - misc/nav:   $ % ~ | ^

    .------.------.------.------.------.            .------.------.------.------.------.
    | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  |            | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    | `    | {    | }    | $    | %    |            | +    | -    | (    | )    | ' "  |
    | SFT  |      |      |      |      |            |      |      |      |      | SFT  |
    |------+------+------+------+------|            |------+------+------+------+------|
    |      | <    | >    | ~    | |    |            | &    | =    | [    | ]    | \ |  |
    | SFT  |      |      |      |      |            |      |      |      |      | SFT  |
    '------'------'------'------'------'            '------'------'------'------'------'
                            .------.------.      .------.------.
                            | ↓↓↓  | ↓↓↓  |      | ↓↓↓  | ↓↓↓  |
                            |      |      |      |      |      |
                            '------'------'      '------'------'
*/
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    HOME_BT, KC_LCBR, KC_RCBR, KC_DLR,  KC_PERC,      KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, HOME_QT,
    KC_LSFT, KC_LABK, KC_RABK, KC_TILD, KC_PIPE,      KC_AMPR, KC_EQL,  KC_LBRC, KC_RBRC,  SFT_BSLS,
                               _______, _______,      _______, _______
  ),

    [_FUN_NAV] = LAYOUT(
/*
    .------.------.------.------.------.            .------.------.------.------.------.
    | F1   | F2   | F3   | F4   | F5   |            | F6   | F7   | F8   | F9   | F10  |
    |      |      |      |      |      |            |      | Prev | Play | Next | Mute |
    |------+------+------+------+------|            |------+------+------+------+------|
    |      |      | VIUP | VIDN |      |            | ←    | ↓    | ↑    | →    |      |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    | KVM1 | KVM2 | KVM3 | KVM4 |      |            | F11  | F12  | ^    | RBG  | GAME |
    |      |      |      |      |      |            | VolD | VolU |      | TOG  | TOG  |
    '------'------'------'------'------'            '------'------'------'------'------'
                            .------.------.      .------.------.
                            | ↓↓↓  | ESC  |      | ↓↓↓  | ↓↓↓  |
                            |      |      |      |      |      |
                            '------'------'      '------'------'
*/
    KC_F1,   KC_F2,   KC_F3,    KC_F4,    KC_F5,        KC_F6,   KC_MPRV,  KC_MPLY, KC_MNXT,  KC_MUTE,
    XXXXXXX, XXXXXXX, VIM_CTLU, VIM_CTLD, XXXXXXX,      KC_LEFT, KC_DOWN,  KC_UP,   KC_RIGHT, XXXXXXX,
    KVM_1,   KVM_2,   KVM_3,    KVM_4,    XXXXXXX,      KC_VOLD, KC_VOLU,  KC_CIRC, RGB_TOG,  GAME_TOG,
                                _______,  KC_ESC,       _______, _______
  ),
    [_GAME] = LAYOUT(
/*
    .------.------.------.------.------.            .------.------.------.------.------.
    | TAB  | Q    | W    | E    | R    |            | Y    | U    | I    | O    | P    |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    | ESC  | A    | S    | D    | F    |            | H    | J    | K    | L    | ; :  |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    |      | Z    | X    | C    | V    |            | N    | M    | , <  | . >  | GAME |
    | SFT  |      |      |      |      |            |      |      |      |      | TOG  |
    '------'------'------'------'------'            '------'------'------'------'------'
                            .------.------.      .------.------.
                            |      | SPC  |      | SPC  | ENT  |
                            | CTL  |      |      | GFUN | OPT  |
                            '------'------'      '------'------'
*/
    KC_TAB,  KC_Q, KC_W,    KC_E,    KC_R,        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,
    KC_ESC,  KC_A, KC_S,    KC_D,    KC_F,        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN,
    KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,        KC_N,     KC_M,     KC_COMM, KC_DOT,  GAME_TOG,
                            KC_LCTL, KC_SPC,      GFUN_SPC, GOPT_ENT
),

    [_GAME_FUN] = LAYOUT(
/*
    .------.------.------.------.------.            .------.------.------.------.------.
    | F1   | F2   | F3   | F4   | F5   |            | F6   | F7   | F8   | F9   | F10  |
    |      |      |      |      |      |            |      | Prev | Play | Next | Mute |
    |------+------+------+------+------|            |------+------+------+------+------|
    | ↓↓↓  |      |      |      |      |            |      | \ |  | [ {  | ] }  |      |
    |      |      |      |      |      |            |      |      |      |      |      |
    |------+------+------+------+------|            |------+------+------+------+------|
    | ↓↓↓  |      |      |      |      |            | F11  | F12  |      |      | ↓↓↓  |
    |      |      |      |      |      |            | VolD | VolU |      |      |      |
    '------'------'------'------'------'            '------'------'------'------'------'
                            .------.------.      .------.------.
                            | ↓↓↓  | ↓↓↓  |      | ↓↓↓  | ↓↓↓  |
                            |      |      |      |      |      |
                            '------'------'      '------'------'
*/
    KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,
    _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_BSLS, KC_LBRC, KC_RBRC, XXXXXXX,
    _______, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,      KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, _______,
                                _______, _______,      _______, _______
)

};


/* macro configuration */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KVM_1:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_1));
            }
            break;
        case KVM_2:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_2));
            }
            break;
        case KVM_3:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_3));
            }
            break;
        case KVM_4:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_RCTL) SS_DELAY(100) SS_TAP(X_4));
            }
            break;
        case VIM_CTLU:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("u"));
            }
            break;
        case VIM_CTLD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("d"));
            }
            break;
    }
    return true;
};

/* per key configuration */

// https://precondition.github.io/home-row-mods#finding-the-sweet-spot
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD_TAB:  // make CMD SPC faster
        case SFT_Z:    // make bottom row SFT faster
        case SFT_SLSH: // make bottom row SFT faster
        case SFT_BSLS: // make bottom row SFT faster
            return false;
        default:
            return true;
    }
}

// https://precondition.github.io/home-row-mods#finding-the-sweet-spot
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* adjust home row key timing to prevent letter rolls triggering modifiers */
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_BSPC:
        case FUN_SPC:
        case CMD_ENT:
            return false;
        default:
            return true;
    }
}

// https://docs.qmk.fm/#/tap_hold?id=permissive-hold
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_BSPC:
        case FUN_SPC:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}


/* caps word */
// https://docs.qmk.fm/#/feature_caps_word?id=configure-which-keys-are-word-breaking

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // keycodes that continue Caps Word, with shift applied
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // apply shift to next key
            return true;

        // keycodes that continue Caps Word, without shifting
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
        case KC_LSFT: // ensure manual shift does not break caps word
        case KC_RSFT: // ensure manual shift does not break caps word
            return true;

        default:
            return false;  // deactivate Caps Word
    }
}


/* custom lighting configuration */

// blok controller leds
const rgblight_segment_t PROGMEM rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_GREEN} // light 2 LEDs, starting with LED 1
);

const rgblight_segment_t PROGMEM rgb_colemakdh_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_WHITE}
);

const rgblight_segment_t PROGMEM rgb_gaming_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_gaming2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE}
);

// array of layers
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_capslock_layer,  // not used, see comment on duplicated layer below
    rgb_colemakdh_layer, // default layer
    rgb_gaming_layer,    // overrides other layers
    rgb_gaming2_layer,   // overrides other layers
    // there seems to be a bug activating layer 0, so adding caps as layer 5 as well
    rgb_capslock_layer
);

void keyboard_post_init_user(void) {
    // enable the LED layers
    rgblight_layers = rgb_layers;
}

// activate rgb_capslock_layer when Caps Lock is on
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _COLEMAK_DH));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _GAME));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAME_FUN));
    return state;
}

// activate rgb_capslock_layer when Caps Word activates
void caps_word_set_user(bool active) {
    if (active) {
        rgblight_set_layer_state(4, true);
    } else {
        rgblight_set_layer_state(4, false);
    }
}
