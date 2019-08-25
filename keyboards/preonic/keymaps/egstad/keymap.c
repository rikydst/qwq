#include QMK_KEYBOARD_H






/* LAYER NAMES
   ==========================================================================
   1. To create a layer, define a (readable) name and set layer value
   2. Under "Layer definitions" section, define keymaps
   ========================================================================== */

#define L_QWERTY  0 
#define L_LOWER   1 
#define L_RAISE   2
#define L_ADJUST  3  




/* TAP DANCE
   ==========================================================================
   1. Define TD names here
   2. Register action in tap_dance_actions[]
   ========================================================================== */

enum {
  TD_BRC = 0,
  TD_MIN,
  TD_GV_ESC,
  TD_BS
};




/* CUSTOM KEYMAPS
   ========================================================================== */

// Tap dances
#define TD_ESCP TD(TD_GV_ESC)           // Tap for grave, twice for escape
#define TD_MINS TD(TD_MIN)              // Tap for minus, twice for equal
#define TD_BRAC TD(TD_BRC)              // Tap for open brace, twice for close

// Layers
#define LT2_TAB LT(L_RAISE, KC_TAB)     // Tap for tab, hold for RAISE
#define LT2_ENT LT(L_RAISE, KC_ENT)     // Tap for tab, hold for RAISE
#define LT1_BSP LT(L_LOWER, KC_BSPACE)  // Tap for backspace, hold for LOWER
#define LT1_SPC LT(L_LOWER, KC_SPC)     // Tap for space, hold for LOWER

// Modifiers
#define MT_SHFT MT(MOD_RSFT, KC_ENT)    // Tap for enter, hold for shift
#define MT_HILF S(A(KC_LEFT))           // Press for shift + alt + left
#define MT_HIRT S(A(KC_RGHT))           // Press for shift + alt + right
#define MT_UNTB S(KC_TAB)               // Press for shift + tab






/* Layer definitions
   ========================================================================== */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------------------.
 * | ` ESC |  1 !  |  2 @  |  3 #  |  4 $  |  5 %  |  6 ^  |  7 &  |  8 *  |  9 (  |  0 )  | -_ =+ |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TB/RS |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | [{ }] | 
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | BS/LW |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  SFT  |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | SF/RN |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | LEADR |       |  CTL  |  ALT  |  CMD  |  BSP  | SP/LW | RN/RS |   ←   |   ↑   |   ↓   |   →   |    
 * `-----------------------------------------------------------------------------------------------
 */

[L_QWERTY] = LAYOUT_preonic_grid( \
/*01          02          03          04          05          06          07          08          09          10          11          12         */
  TD_ESCP,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       TD_MINS,    \
  LT2_TAB,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       TD_BRAC,    \
  LT1_BSP,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    \
  KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MT_SHFT,    \
  KC_LEAD,    _______,    KC_LCTL,    KC_LALT,    KC_LGUI,    KC_BSPACE,  LT1_SPC,    LT2_ENT,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT     \
),






 /* LOWER
 * ,-----------------------------------------------------------------------------------------------.
 * | ASHFT |       |       |       |       |       |       |       |       |       |       |  BSP  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | UNTAB |       |       |       |       |       |       |   -   |   +   |   *   |   /   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       | S+A+← | S+A+→ |       |       |       |       |   ←   |   ↑   |   ↓   |   →   |  RTN  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |  [ {  |  ] }  |   (   |   )   |  \ |  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |  >||  |       |  <<   | Vol-U | Vol-D |  >>   |    
 * `-----------------------------------------------------------------------------------------------'
 */

[L_LOWER] = LAYOUT_preonic_grid( \
/*01          02          03          04          05          06          07          08          09          10          11          12         */
  KC_ASTG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_BSPACE,  \
  MT_UNTB,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MINUS,   KC_PLUS,    KC_PAST,    KC_PSLS,    _______,    \
  _______,    MT_HILF,    MT_HIRT,    _______,    _______,    _______,    _______,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RIGHT,   KC_ENTER,   \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_LPRN,    KC_RPRN,    KC_BSLASH,  \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_MRWD,    KC_VOLU,    KC_VOLD,    KC_MFFD     \
),






/* RAISE
 * ,-----------------------------------------------------------------------------------------------.
 * | ASHFT | BTSDN | BTSUP |  VUP  |  VDN  |       |       |   /   |   *   |   (   |   )   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |   7   |   8   |   9   |   +   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |   4   |   5   |   6   |   -   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  CAP  |       |       |       |       |       |       |   1   |   2   |   3   |   /   |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |   0   |   .   |   ,   |       |
 * `-----------------------------------------------------------------------------------------------'
 */
[L_RAISE] = LAYOUT_preonic_grid( \
/*01          02          03          04          05          06          07          08          09          10          11          12         */
  KC_ASTG,    KC_F1,      KC_F2,      KC_VOLU,    KC_VOLD,    _______,    _______,    KC_PSLS,    KC_PAST,    KC_LPRN,    KC_RPRN,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P7,      KC_P8,      KC_P9,      KC_PLUS,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P4,      KC_P5,      KC_P6,      KC_MINUS,   _______,    \
  KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P1,      KC_P2,      KC_P3,      KC_PSLS,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_P0,      KC_PDOT,    KC_COMM,    _______     \
),
 






/* Adjust (Raise + Lower together)
 * ,-----------------------------------------------------------------------------------------------.
 * |  F12  |  FN2  |  FN3  |  FN4  |  FN5  |  FN6  |  FN7  |  FN8  |  FN9  |  F10  |  F11  |  FN1  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | TOG SF|       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * | DESGN |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */

[L_ADJUST] = LAYOUT_preonic_grid( \
/*01          02          03          04          05          06          07          08          09          10          11          12         */
  KC_F12,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  KC_ASTG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______     \
)

};

// this function 
uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);
}






/* BLANK
 * ,-----------------------------------------------------------------------------------------------.
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |       |       |       |       |       |       |
 * `-----------------------------------------------------------------------------------------------'
 */
/* 
[L_BLANK] = LAYOUT_preonic_grid( \ 
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______     \
),
*/






/* Tap Dance Definitions
   ========================================================================== */

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Left Brace, twice for Right Brace
  [TD_BRC]  = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
  //Tap once for Minus, twice for Equal
  [TD_MIN]  = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
  // Tap once for Grave, tap twice for Escape
  [TD_GV_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_ESCAPE)
};






/* ==========================================================================
   Leader Key
   ========================================================================== */

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

    // Zoom Out
    SEQ_ONE_KEY(TD(TD_MIN)) {
      register_code(KC_LGUI);
      register_code(KC_KP_MINUS);
      unregister_code(KC_KP_MINUS);
      unregister_code(KC_LGUI);
    }

    // Zoom In
    SEQ_TWO_KEYS(TD(TD_MIN), TD(TD_MIN)) {
      register_code(KC_LGUI);
      register_code(KC_KP_PLUS);
      unregister_code(KC_KP_PLUS);      
      unregister_code(KC_LGUI);
    }  

    // Go to beginning of line
    SEQ_ONE_KEY(KC_J) {
      register_code(KC_LGUI);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LGUI);
    }
    // Go to end of line
    SEQ_ONE_KEY(KC_SCLN) {
      register_code(KC_LGUI);
      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);
      unregister_code(KC_LGUI);
    }
    // Select text from cursor, back
    SEQ_TWO_KEYS(KC_J, KC_J) {
      register_code(KC_LGUI);
      register_code(KC_LSHIFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LGUI);
    }
    // Select text from cursor, up
    SEQ_TWO_KEYS(KC_K, KC_K) {
      register_code(KC_LGUI);
      register_code(KC_LSHIFT);
      register_code(KC_UP);
      unregister_code(KC_UP);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LGUI);
    }
    // Select text from cursor, down
    SEQ_TWO_KEYS(KC_L, KC_L) {
      register_code(KC_LGUI);
      register_code(KC_LSHIFT);
      register_code(KC_DOWN);
      unregister_code(KC_DOWN);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LGUI);
    }
    // Select text from cursor, down
    SEQ_TWO_KEYS(KC_SCLN, KC_SCLN) {
      register_code(KC_LGUI);
      register_code(KC_LSHIFT);
      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);
      unregister_code(KC_LSHIFT);
      unregister_code(KC_LGUI);
    }


    leader_end();
  }
}




