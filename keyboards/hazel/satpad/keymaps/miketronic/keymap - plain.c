#include QMK_KEYBOARD_H


enum layers {
  _HOME,       // home base layer
  _LOWER,  
  _RAISE,
  _ADJUST,
  _FUNCTION,
  _SYMBOLS,     
  _ARROWPAD,
};

// TAP DANCE DECLARATIONS  ============================================================================
enum {
   T_BR = 0, // [, ]
   // T_PA,     // (, )
    T_SL,     // slash, backslash
   // T_UPRT,   // up, right
   // T_DNLT,   // down, left
    T_QUOTE,    // quote, double quote
    T_DOTENT, // dot, enter
    T_TSPC,     // T, space
    T_COMMSPC,  // space, comma
    T_DOTSPC,   // space, dot
    T_QEXC,     // Tap once for ?, twice for !
    T_QESC,     // Tap once for "q", twice for escape  
   // T_NENT,     // N, enter
   // T_TE,     // tab, escape
    T_CP,     // copy, paste
};

//TAP DANCE DEFINITIONS ===========================================
qk_tap_dance_action_t tap_dance_actions[] = {
 [T_BR] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),         // Tap once for [, twice for ]
 // [T_PA] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [T_SL] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
 // [T_UPRT] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_RGHT),
 // [T_DNLT] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_LEFT),
  [T_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),     // Tap once for quote, twice for double quote
  [T_DOTENT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_ENT),      // Tap once for dot, twice for enter
  [T_TSPC] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_SPC),          // Tap once for "t", twice for space
  [T_COMMSPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_COMM),    // Tap once for space, twice for comm
  [T_DOTSPC] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_DOT),      // Tap once for space, twice for dot
  [T_QEXC] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_EXLM),      // Tap once for ?, twice for !  
  [T_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),          // Tap once for "q", twice for escape 
 // [T_NENT] = ACTION_TAP_DANCE_DOUBLE(KC_N, KC_ENT),          // Tap once for "n", twice for enter
 // [T_TE] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),      // Tap once for tab, twice for esc
  [T_CP] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_V)),
  //[X_CTL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)

};

#define XXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
// #define TSKMGR LCTL(LSFT(KC_ESC))
#define CLIP LCTL(LALT(KC_Q))		// Clipboard
#define SS LCTL(LALT(KC_G))		    // Greenshot region



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * LEGEND:
 *
 * ,--------------------------------.
 * |     Top row: shifted character |
 * | Central row: standard char     |
 * |  Bottom row: hold modifier     |
 * `--------------------------------'
 *
 *  "____" means free to be assigned
 *
 */

/* Workman Home Layer
 * ,----------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |   Q  |   D  |   R  |   W  |   B  |      |   J  |   F  |   U  |   P  | BKSPC|
 * |Escape| FUNCT|      |      |SYMBOL|      |SYMBOL|      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |   A  |   S  |   H  |   T  |   G  |      |   Y  |   N  |   E  |   O  |   I  |
 * | Shift|      |      |2x SPC| OSkey|      | OSkey|      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |   Z  |   X  |   M  |   C  |   V  |      |   K  |   L  | Space| Space|      |
 * | FUNCT| CTRL |  OS  |  ALT |LOWER |      | RAISE|  Alt |   ,  |   .  | Enter|
 * '----------------------------------------------------------------------------'
 * 
 *   http://www.keyboard-layout-editor.com/#/gists/fcc6c759cf335abf31f6c200db3b9aca
 *   
 */
  [_HOME] = LAYOUT_3x11(
    TD(T_QESC), LT(_FUNCTION, KC_D), KC_R, KC_W, LT(_SYMBOLS, KC_B),   XXXX, LT(_SYMBOLS, KC_J), KC_F, KC_U, KC_P, MT(MOD_RSFT, KC_BSPC),
    MT(MOD_LSFT, KC_A), KC_S, KC_H, TD(T_TSPC),   MT(MOD_LGUI, KC_G),  XXXX, MT(MOD_RGUI, KC_Y), KC_N, KC_E, KC_O, MT(MOD_RSFT, KC_I),
    LT(_FUNCTION, KC_Z), MT(MOD_LCTL, KC_X),     MT(MOD_LGUI, KC_M),   MT(MOD_LALT, KC_C), LT(_LOWER, KC_V), XXXX, LT(_RAISE, KC_K), MT(MOD_LALT, KC_L), TD(T_COMMSPC),   TD(T_DOTSPC),   KC_ENT
  ),




/* LOWER LAYER 
 * ,----------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   &  |   *  |   (  |   )  |
 * |      | VOL+ |      |      |      |      |  / \ |   7  |   8  |   9  |   0  |
 * |      |      |      |      |      |      | ____ | ____ | ____ | ____ | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   $  |   %  |   ^  |      |
 * |  TAB | MUTE |      |      |      |      |  [ ] |   4  |   5  |   6  | Del  |
 * | Shift|      |      |      |      |      | ____ | ____ | ____ | ____ | Shift|
 * | -----+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      | XXXX |      |      |   !  |   @  |   #  |      | 
 * |      | VOL- |      |      | XXXX |      |      |   1  |   2  |   3  |  .   | 
 * |      |      |      |      | XXXX |      | ____ | ____ | ____ | ____ | Enter| 
 * '----------------------------------------------------------------------------'       
 */
  [_LOWER] = LAYOUT_3x11(
    XXXX, KC_VOLU, XXXX, XXXX,  XXXX,    XXXX, TD(T_SL), KC_7, KC_8, KC_9, MT(MOD_RSFT, KC_0),
    MT(MOD_LSFT, KC_TAB), KC_MUTE, XXXX,    XXXX, XXXX,     XXXX, TD(T_BR), KC_4, KC_5, KC_6, MT(MOD_RSFT, KC_DEL),
    XXXX, KC_VOLD, XXXX, XXXX,     _______, XXXX, _______,  KC_1, KC_2, KC_3, TD(T_DOTENT)
  ),

/* RAISE LAYER
 * ,----------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |
 * |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |
 * | ____ | ____ | ____ | ____ | ____ |      | ____ | ____ |  Alt | Ctrl | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |   _  |   +  |   {  |      |   _  |  |   |   :  |   "  |      |
 * |  TAB |   `  |   -  |   =  |   [  |      |   -  |  \   |   ;  |   '  | Del  |
 * | Shift| ____ | ____ | AltGr| OSkey|      | OSkey| AltGr| ____ | ____ | Shift|
 * | -----+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      | XXXX |   >  |   ?  |      |      | 
 * |      |BackSp|  Del | Enter|      |      | XXXX |   .  |   /  | Enter|      | 
 * |      | Ctrl |  Alt | ____ | ____ |      | XXXX |  Alt | Ctrl | Shift|      | 
 * '----------------------------------------------------------------------------'       
 */
  [_RAISE] = LAYOUT_3x11(
    KC_1, KC_2, KC_3, KC_4, KC_5, _______, KC_6, KC_7, MT(MOD_LALT, KC_8), MT(MOD_RCTL,KC_9), MT(MOD_RSFT, KC_0),
    MT(MOD_LSFT, KC_TAB), KC_GRV, KC_MINS, MT(MOD_RALT, KC_EQL), MT(MOD_LGUI, KC_LBRC), _______, KC_MINS, MT(MOD_RALT, KC_BSLS), KC_SCLN, KC_QUOT, MT(MOD_RSFT, KC_DEL),
    KC_LEFT, MT(KC_LCTL, KC_BSPC), MT(KC_LALT, KC_DEL), KC_ENT, _______, XXXX, _______, MT(MOD_LALT, KC_DOT), MT(MOD_RCTL, KC_SLSH), MT(MOD_RSFT, KC_ENT), KC_RGHT
  ),
   
/* ADJUST LAYER  (LOWER + RAISE)
 * ,----------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |
 * | BOOT |      |      |      |      |      |      |      |      |      |CALTDEL|
 * |      | ____ | ____ | ____ | ____ |      | ____ | ____ | ____ | ____ | ____ |
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |  TAB |      |      |      |      |      |      |      |      |      | Del  |
 * | Shift| ____ | ____ | ____ | ____ |      | ____ | ____ | ____ | ____ | Shift|
 * | -----+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      | XXXX |      | XXXX |      |      |      |      | 
 * |      | CTRL |  ALT | Enter| XXXX |      | XXXX |      |      |      |  .   | 
 * |      |      |      | Shift| XXXX |      | XXXX | ____ | ____ | ____ | Enter| 
 * '----------------------------------------------------------------------------'       
 */
  [_ADJUST] = LAYOUT_3x11(
    QK_BOOT,              XXXX, XXXX, XXXX, XXXX,    XXXX, XXXX,    XXXX, XXXX, XXXX, CALTDEL,
    MT(MOD_LSFT, KC_TAB), XXXX, XXXX, XXXX, XXXX,    XXXX, XXXX,    XXXX, XXXX, XXXX, MT(MOD_RSFT, KC_DEL),
    XXXX,                 XXXX, XXXX, XXXX, _______, XXXX, _______, XXXX, XXXX, XXXX, MT(KC_ENT, KC_DOT)
  ),

/* FUNCTION LAYER
 * ,----------------------------------------------------------------------------.
 * |1COPY |      |      |      |      |      |      |      |      |      |      |
 * |2PASTE| CLIP |  SS  |      |      |      |      |      |  UP  |      |DELETE|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |  TAB | M05  | M06  | M07  | M08  |      |      | LEFT | DOWN | RIGHT|  " ' |      
 * | Shift|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |      |      |      |      |      |      |      |      |      |      |  
 * | XXXX | M01  | M02  | M03  | M04  |      |      |   ?  |   ,  |   .  |   ?  |
 * | XXXX |      |      |      |      |      |      |   !  | ____ | ____ |   !  |
 * '----------------------------------------------------------------------------'       
 */

  [_FUNCTION] = LAYOUT_3x11(
    TD(T_CP),             CLIP,     SS,       XXXX,     XXXX,   XXXX, XXXX,   XXXX,       KC_UP,   XXXX,    KC_DEL,
    MT(MOD_LSFT, KC_TAB), XXXX,   XXXX,   XXXX,   XXXX, XXXX, XXXX,   KC_LEFT,    KC_DOWN, KC_RGHT, TD(T_QUOTE),
    _______,              XXXX,   XXXX,   XXXX,   XXXX, XXXX, XXXX, TD(T_QEXC), KC_COMM, KC_DOT,  TD(T_QEXC)
  ),


/* SYMBOLS
 * ,----------------------------------------------------------------------------.
 * |      |      |      |      | XXXX |      | XXXX |      |      |      |      |
 * |   $  |   ^  |   <  |   >  | XXXX |      | XXXX |   |  |   [  |   ]  |   -  |
 * |      |      |      |      | XXXX |      | XXXX |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * |   %  |   :  |   ;  |   +  |   =  |      |      |      |   (  |   )  |   _  |
 * |      |      |      |      |      |      |      |      |      |      |      |
 * | -----+------+------+------+------+------|------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | 
 * |   &  |   '  |   "  |   *  |   #  |      |   !  |   ?  |   /  |   \  |   @  | 
 * |      |      |      |      |      |      |      |      |      |      |      | 
 * '----------------------------------------------------------------------------'
 * 
 *   http://www.keyboard-layout-editor.com/#/gists/fcc6c759cf335abf31f6c200db3b9aca
 */
  [_SYMBOLS] = LAYOUT_3x11(
    KC_DLR, KC_CIRC, KC_LABK, KC_RABK, XXXX,     _______, XXXX, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINS,
    KC_PERC, KC_COLN, KC_SCLN, KC_PLUS, KC_EQL,  _______, XXXX, XXXX, KC_LPRN, KC_RPRN, KC_UNDS,
    KC_AMPR, KC_QUOT, KC_DQUO, KC_ASTR, KC_HASH, _______, KC_EXLM, KC_QUES, KC_SLSH, KC_BSLS, KC_AT
  ),


    
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
  // eeconfig_init(); // reset keyboard to a standard default state; useful when new releases messup with eeprom values
  // set num lock on at start (for numonly layer to work)
  if (!host_keyboard_led_state().num_lock) {
      tap_code(KC_NUM_LOCK);
  }
}

void matrix_scan_user(void) {
}


const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_HOME] = { ENCODER_CCW_CW(LCTL(KC_V), LCTL(KC_C)) },
    [_SYMBOLS] = { ENCODER_CCW_CW(KC_SPC, KC_ENT) },                            
    [_RAISE] = { ENCODER_CCW_CW(KC_SPC, KC_ENT) },
    [_LOWER] = { ENCODER_CCW_CW(KC_SPC, KC_ENT) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_SPC, KC_ENT) },
    [_FUNCTION] = { ENCODER_CCW_CW(KC_SPC, KC_ENT) },
};
 

oled_rotation_t oled_init_user(oled_rotation_t rotation){   
    return OLED_ROTATION_270;
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LAYER\n-----\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _FUNCTION:
            oled_write_P(PSTR("FUNCT"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR(" ADJ "), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("SYMB"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("HOME"), false);
    }

// Host Keyboard LED Status
   // led_t led_state = host_keyboard_led_state();
   // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
   // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
   // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
  
 return false;
}
#endif

