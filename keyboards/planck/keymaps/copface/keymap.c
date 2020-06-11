#include QMK_KEYBOARD_H
#include "muse.h"

// Custom Keycode Definitions
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define META MO(_META)

#define KC_PRS LGUI(LALT(LCTL(KC_4)))
#define KC_EUR LALT(KC_4)
#define KC_MGRV LALT(KC_GRV)

#define KC_FORMAT LGUI(LALT(KC_L))
#define KC_FBSP LALT(KC_BSPC)
#define KC_FDEL LALT(KC_DEL)
#define KC_PS3 LSFT(LCTL(LGUI(KC_3)))
#define KC_PS4 LSFT(LCTL(LGUI(KC_4)))

#define HK_TM LALT(KC_2)
#define HK_AF9 LALT(KC_F9)

#define KC_SRC LGUI(KC_F12)
#define KC_RNME LSFT(KC_F6)

#define M_LGSPC LGUI_T(KC_SPC)
#define M_LCENT LCTL_T(KC_ENT)
#define M_LGENT LGUI_T(KC_ENT)

enum planck_layers {
  _MAC = 0,
  _WIN,
  _LOWER,
  _RAISE,
  _META,
  _ADJUST
};

enum planck_keycodes {
  MAC = SAFE_RANGE,
  WIN,
  KC_ARR,  // ->
  KC_FARR, // =>
  HK_CLOS, // />
  XD1,     // :D
  XD3,     // :DDD
  XD5,     // :DDDDD
  XD15,    // :DDDDDDDDDDDDDDD
};

enum tapdancers {
    T_BR = 0, // [, ]
    T_PA, // (, )
    T_CU, // {, }
    T_DL, // $, €
    T_SL, // slash, backslash
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [T_BR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  [T_PA] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [T_CU] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [T_DL] = ACTION_TAP_DANCE_DOUBLE(KC_DLR, KC_EUR),
  [T_SL] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAC] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,  KC_J,    KC_K,    KC_L,    XXXXXXX, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,  KC_M,    KC_COMM, KC_DOT,  XXXXXXX, KC_LEAD,
    KC_LGUI, KC_LCTL, KC_LALT, KC_LALT, LOWER,   KC_SPC,  META,  RAISE,   KC_RALT, KC_MPRV, KC_MPLY, KC_MNXT
),

[_WIN] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    XXXXXXX, XXXXXXX,  XXXXXXX,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,    KC_0,     XXXXXXX,
    _______, HK_TM,   XD1,     XD3,     XD5,     XD15,    XXXXXXX, XXXXXXX,    KC_ARR,     KC_FARR, HK_CLOS,  XXXXXXX,
    _______, _______, _______, _______, _______, KC_DEL,  KC_FBSP, RAISE,      KC_RALT,    KC_VOLD, KC_MUTE,  KC_VOLU
),

[_RAISE] = LAYOUT_planck_grid(
    KC_MGRV, KC_MINUS,   KC_EQL,  KC_EXLM,  KC_QUES, KC_PLUS, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_FBSP,
    KC_TILD, TD(T_BR), TD(T_CU), TD(T_PA), TD(T_DL), KC_SLSH, KC_RNME, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_FORMAT,
    _______, KC_UNDS,   KC_DQUO,  KC_QUOT,  KC_PIPE, KC_BSLS, XXXXXXX, KC_SCLN, KC_COLN, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______,   _______,  _______,  _______, KC_DEL,  KC_FDEL, _______, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU
),

[_META] = LAYOUT_planck_grid(
    XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_SRC, XXXXXXX,
    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,  KC_F10,  KC_F11,  KC_F12,  HK_AF9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJUST] = LAYOUT_planck_grid(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     WIN,     MAC, XXXXXXX,
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET
)
};

#ifdef AUDIO_ENABLE
  float song_qwerty_sound[][2]   = SONG(QWERTY_SOUND);
  float song_colemak_sound[][2]  = SONG(COLEMAK_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(song_colemak_sound);
        #endif
        set_single_persistent_default_layer(_MAC);
      }

      return false;
    case WIN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(song_qwerty_sound);
        #endif
        set_single_persistent_default_layer(_WIN);
      }

      return false;

    case KC_ARR:
      if (record->event.pressed) {
        SEND_STRING("->");
      }

      return false;

    case KC_FARR:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }

      return false;

    case XD1:
      if (record->event.pressed) {
        SEND_STRING(":D");
      }

      return false;

    case XD3:
      if (record->event.pressed) {
        SEND_STRING(":DDD");
      }

      return false;

    case XD5:
      if (record->event.pressed) {
        SEND_STRING(":DDDDD");
      }

      return false;

    case XD15:
      if (record->event.pressed) {
        SEND_STRING(":DDDDDDDDDDDDDDD");
      }

      return false;

    case HK_CLOS:
      if (record->event.pressed) {
        SEND_STRING("/>");
      }

      return false;
  }

  return true;
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Screenshot
        SEQ_ONE_KEY(KC_S) {
            register_code(KC_LGUI);
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(KC_4);
            unregister_code(KC_4);
            unregister_code(KC_LSFT);
            unregister_code(KC_LCTL);
            unregister_code(KC_LGUI);
        }
        // 1Pass browser
        SEQ_ONE_KEY(KC_A) {
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_BSLS);
            unregister_code(KC_BSLS);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
        }
        // 1Pass mini
        SEQ_TWO_KEYS(KC_A, KC_A) {
            register_code(KC_LGUI);
            register_code(KC_BSLS);
            unregister_code(KC_BSLS);
            unregister_code(KC_LGUI);
        }
        // Comment out
        SEQ_ONE_KEY(KC_F) {
            register_code(KC_LGUI);
            register_code(KC_SLSH);
            unregister_code(KC_SLSH);
            unregister_code(KC_LGUI);
        }
        // Spotlight
        SEQ_ONE_KEY(KC_SPC) {
            register_code(KC_LGUI);
            register_code(KC_SPC);
            unregister_code(KC_SPC);
            unregister_code(KC_LGUI);
        }
        // Auto format
        SEQ_ONE_KEY(KC_ENT) {
            register_code(KC_LSFT);
            register_code(KC_LGUI);
            register_code(KC_LALT);
            register_code(KC_F);
            unregister_code(KC_F);
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            unregister_code(KC_LSFT);
        }
    }
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
