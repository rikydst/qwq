#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _NUMPAD 4 
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST,
  AE,
  EE,
  IE,
  VAD_NEE,
  VAI_NEE,
  SAI_NEE,
  SAD_NEE,
  HUI_NEE,
  HUD_NEE,
  TOG_NEE,
  RGB_ANM,
  RGB_PRE
};

enum td_hungarian_letters {
  U,
  O
};

uint32_t rgb_mode = RGBLIGHT_MODE_BREATHING + 1;


void tap_dance_u_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1: SEND_STRING(SS_RALT("]")); break;
    case 2: SEND_STRING(SS_RALT("-")); break;
    case 3: SEND_STRING(SS_RALT("\\")); break;
  }
}

void tap_dance_o_finished (qk_tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1: SEND_STRING(SS_RALT("=")); break;
    case 2: SEND_STRING(SS_RALT("0")); break;
    case 3: SEND_STRING(SS_RALT("[")); break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [U] = ACTION_TAP_DANCE_FN(tap_dance_u_finished),
  [O] = ACTION_TAP_DANCE_FN(tap_dance_o_finished)
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |                |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Ctrl | ALT  |Numpad| GUI  |Lower | SPC  |                | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
   KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
   KC_LCTL, KC_LALT, NUMPAD,  KC_LGUI, LOWER,   KC_SPC,       KC_BSPC, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |                |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |                |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |                |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,          KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,          KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,        KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |                |   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  | Home | End  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |                |  F12 | Pgup |Pgdown|      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |Insert|                |  Del |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6, KC_HOME, KC_END, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12, KC_PGUP, KC_PGDOWN ,_______, _______, _______, \
  _______, _______, _______, _______, _______, KC_INSERT,     KC_DEL, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------.                ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                |  F6  |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |                |  F12 |      |      |      |   \  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   _______, _______, KC_LBRC, KC_RBRC, _______, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        KC_F12,  _______, _______, _______, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | Reset|EEPRST|      |  EE  |      |      |                |      |  UE  |  IE  |  OE  |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  AE  |      |Aud on|Audoff|AGnorm|                |Qwerty|Colemk|      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TGLAS|      |      |      |      |      |                |      |      |      |      |      |      |
 * `-----------------------------------------'                `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  RESET,   EEP_RST, _______, EE,      _______, _______,       _______, TD(U),   IE,      TD(O),   _______,_______, \
  _______, AE,      _______, AU_ON,   AU_OFF,  AG_NORM,       QWERTY,  COLEMAK, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, \
  KC_ASTG, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______ \
),

/* Numpad
 * ,-----------------------------------------.               ,-----------------------------------------.
 * |      |      |      |      |      |      |               |   7  |   8  |   9  |   /  |      |      |      
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |      |      |      |               |   4  |   5  |   6  |   *  |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |  VAI |  VAD |  SAI |  SAD | HUI  | HUD  |               |   3  |   2  |   1  |   -  |      |      |
 * |------+------+------+------+------+------|               |------+------+------+------+------+------|
 * |      |      |      |RGBMPR|RGBMFW|RGBTGL|               | Bksp |   0  |      |   +  |      |      |
 * `-----------------------------------------'               `-----------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______,       KC_7,    KC_8,   KC_9,    KC_PSLS, _______, _______, \
  _______, _______, _______, _______, _______, _______,       KC_4,    KC_5,   KC_6,    KC_PAST, _______, _______, \
  VAI_NEE, VAD_NEE, SAI_NEE, SAD_NEE, HUI_NEE, HUD_NEE,       KC_1,    KC_2,   KC_3,    KC_PMNS, _______, _______, \
  _______, _______, _______, RGB_PRE, RGB_ANM, TOG_NEE,       KC_BSPC, KC_0,  _______,  KC_PPLS, _______, _______ \
)

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if(record->event.pressed){
	layer_on(_NUMPAD);
	PORTB &= ~(1<<0);
      } else {
	layer_off(_NUMPAD);
	PORTB |= (1<<0);
      }
      break;
    case AE:           
      if(record->event.pressed) {
	SEND_STRING(SS_RALT("'"));
      }    
      break;
    case EE:            
      if(record->event.pressed) {
	SEND_STRING(SS_RALT(";"));
      }    
      break;
    case IE:            
      if(record->event.pressed) {
	SEND_STRING(SS_RALT("z"));
      }    
      break;
    case VAI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_val_noeeprom();
      }    
      break;
    case VAD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_val_noeeprom();
      }    
      break;
    case SAI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_sat_noeeprom();
      }    
      break;
    case SAD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_sat_noeeprom();
      }    
      break;
    case HUI_NEE:            
      if(record->event.pressed) {
        rgblight_increase_hue_noeeprom();
      }    
      break;
    case HUD_NEE:            
      if(record->event.pressed) {
        rgblight_decrease_hue_noeeprom();
      }    
      break;
    case TOG_NEE:            
      if(record->event.pressed) {
	rgblight_toggle_noeeprom();
      }    
      break;
    case RGB_ANM:            
      if(record->event.pressed) {
        rgblight_step_noeeprom();
	rgb_mode = rgblight_get_mode();
      }    
      break;
    case RGB_PRE:            
      if(record->event.pressed) {
        rgblight_step_reverse_noeeprom();
	rgb_mode = rgblight_get_mode();
      }    
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _RAISE:
      rgblight_setrgb_at(255, 255, 255, RGBLED_NUM / 2);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _LOWER:
      rgblight_setrgb_at(255, 255, 255, RGBLED_NUM / 2 - 1);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    case _NUMPAD:
      rgblight_setrgb_at(0,255,0, 0);
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      break;
    default:
      rgblight_mode_noeeprom(rgb_mode);      
      break;
  }
  return state;
}

void led_set_user(uint8_t usb_led) {
  rgblight_sethsv_noeeprom(0, 255, 255);
  rgblight_mode_noeeprom(rgb_mode);
}

