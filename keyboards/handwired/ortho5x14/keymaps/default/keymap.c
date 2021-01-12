#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

// TAP DANCE ***********************************************************
//Tap Dance Declarations
enum {
  TD_DEL_BSPC = 0,
  TD_ESC_GRAVE,
  TD_TAB_TILDE,
  TD_MINS_UNDS,
  TD_EQL_PLUS,
  TD_LBRC_LCBR,
  TD_RBRC_RCBR,
  TD_SCLN_COLN,
  TD_QUOT_DQT,
  TD_COMM_LABK,
  TD_DOT_RABK,
  TD_SLSH_QUES,
  TD_BSLS_PIPE,
  TD_3_F3
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
   [TD_DEL_BSPC]  = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_BSPC),
   [TD_ESC_GRAVE]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE),
   [TD_TAB_TILDE]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_TILDE),

   [TD_MINS_UNDS]  = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),
   [TD_EQL_PLUS]  = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),

   [TD_LBRC_LCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
   [TD_RBRC_RCBR]  = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),

   [TD_SCLN_COLN]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
   [TD_QUOT_DQT]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQT),

   [TD_COMM_LABK]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LABK),
   [TD_DOT_RABK]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_RABK),
   [TD_SLSH_QUES]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_QUES),
   [TD_BSLS_PIPE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),

   [TD_3_F3]  = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3)
};

// Fillers to make layering more clear
// #define _______ KC_TRNS
// #define XXXXXXX KC_NO

#define KC_L1 LOWER
#define KC_L2 RAISE
// MO(_LOWER)
// MO(_RAISE)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-------------------------------------------------------------------------------------------------.
 * | DEL  | Bksp |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | HOME | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | PGUP | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  | Enter|
 * |------+------+------+------+------+------+------|------+------+------+------+------+------+------|
 * | PGDN | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   \  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | END  | Ctrl | Win  | Alt  | Lower|    Space    |    Space    |Raise | Alt  | Prop | Ctrl | Esc  |
 * `-------------------------------------------------------------------------------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,---------------+-----------------+-------+-------+----------+------+----+----+------+----------------+---------------+----------------+----------------+----------------.
     TD(TD_DEL_BSPC), KC_BSPACE       , KC_1  , KC_2  , KC_3     , KC_4 ,KC_5,KC_6,KC_7  , KC_8           , KC_9          , KC_0           ,TD(TD_MINS_UNDS),TD(TD_EQL_PLUS) ,
  //|---------------+-----------------+-------+-------+----------+------+----+----+------+----------------+---------------+----------------+----------------+----------------|
     KC_HOME        , TD(TD_TAB_TILDE),KC_Q   ,KC_W   ,KC_E      ,KC_R  ,KC_T,KC_Y,KC_U  , KC_I           , KC_O          , KC_P           ,TD(TD_LBRC_LCBR),TD(TD_RBRC_RCBR),
  //|---------------+-----------------+-------+-------+----------+------+----+----+------+----------------+---------------+----------------+----------------+----------------|
     KC_PGUP        , KC_CAPS         ,KC_A   ,KC_S   ,KC_D      ,KC_F  ,KC_G,KC_H,KC_J  ,KC_K            , KC_L          ,TD(TD_SCLN_COLN),TD(TD_QUOT_DQT) ,KC_ENT          ,
  //|---------------+-----------------+-------+-------+----------+------+----+----+------+----------------+---------------+----------------+----------------+----------------|
     KC_PGDN        , OSM(MOD_LSFT)   ,KC_Z   ,KC_X   ,KC_C      ,KC_V  ,KC_B,KC_N,KC_M  ,TD(TD_COMM_LABK),TD(TD_DOT_RABK),TD(TD_SLSH_QUES),TD(TD_BSLS_PIPE),KC_RSFT         ,
  //|---------------+-----------------+-------+-------+----------+------+----+----+------+----------------+---------------+----------------+----------------+----------------|
     KC_END         , KC_LCTRL        ,KC_LGUI,KC_LALT, KC_L1    ,  KC_SPACE ,  KC_SPACE , KC_L2          ,KC_RALT        ,KC_BTN2         ,KC_RCTRL        ,TD(TD_ESC_GRAVE)
  //`---------------+-----------------+-------+-------+----------+------+----+-----------+----------------+---------------+----------------+----------------+----------------'
  ),

/* Lower
 * ,-------------------------------------------------------------------------------------------------.
 * | INS  |  ~`  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  ~   |      |  UP  |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * |------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      | LEFT | DOWN |RIGHT |      |      |      |      |      |      |      |      |Enter |
 * |------+------+------+------+------+------+------|------+------+------+------+------+------+------|
 * |      |      |      |      |      |ISO ~ |ISO | |      |      |      |      |      |  UP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |             |      |      | Left | Down |Right |
 * `------------------------------------------------------------------------------------------+------'
 */
[_LOWER] = LAYOUT(
  KC_INS,  KC_GRV,  KC_F1,   KC_F2,   KC_F3   ,   KC_F4  ,   KC_F5  ,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  _______, KC_TILD, _______, KC_UP,   _______ , _______  , _______  , _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______  , _______  , _______, _______, _______, _______, _______, _______, KC_ENT,
  _______, _______, _______, _______, _______ ,S(KC_NUHS),S(KC_NUBS), _______, _______, _______, _______, _______, KC_UP  , _______,
  _______, _______, _______, _______, _______ ,      _______        ,      _______    , _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Raise
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|

 * ,-------------------------------------------------------------------------------------------------.
 * | INS  | Bksp |      |      |      |      |      |      |  7   |  8   |  9   |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |PrtScr|      |      |      |      |      |      |      |  4   |  5   |  6   |  -   |  /   |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------+------|
 * |ScrLck|      |      |      |      |      |      |      |  1   |  2   |  3   |  +   |  *   |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------+------|
 * |Pause |      |      |      |      |ISO # |ISO / |      |  0   |  ,   |  .   |  =   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |CtAlDl|      |      |      |      |             |             |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_INS,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_7,  KC_8,   KC_9,  _______, _______, _______,
  KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_4,  KC_5,   KC_6,  KC_MINS, KC_SLSH, XXXXXXX,
  KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_1,  KC_2,   KC_3,  KC_PLUS, KC_ASTR, KC_ENT,
  KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_NUHS, KC_NUBS,XXXXXXX,  KC_0,  KC_COMM, KC_DOT,KC_EQL, XXXXXXX, _______,
  LALT(LCTL(KC_DEL)), _______, _______, _______, _______,     _______,           _______,     _______,_______,XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-------------------------------------------------------------------------------------------------.
 * |      |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |Audoff|Aud on|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Voice-|Voice+|Musoff|Mus on|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |             |      |      |      |      |      |
 * `-------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, _______, _______, _______, _______,     _______,            _______,    _______,_______,_______, _______, _______
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
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
        // case COLEMAK:
        //   if (record->event.pressed) {
        //     #ifdef AUDIO_ENABLE
        //       PLAY_SONG(tone_colemak);
        //     #endif
        //     persistent_default_layer_set(1UL<<_COLEMAK);
        //   }
        //   return false;
        //   break;
        // case DVORAK:
        //   if (record->event.pressed) {
        //     #ifdef AUDIO_ENABLE
        //       PLAY_SONG(tone_dvorak);
        //     #endif
        //     persistent_default_layer_set(1UL<<_DVORAK);
        //   }
        //   return false;
        //   break;
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
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
