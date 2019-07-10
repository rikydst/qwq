#include QMK_KEYBOARD_H

/*
Let's Split physical layout
1u == 8chars
* == Homing keys
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   |        |        |        |        |        |        |   |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |   *    |        |   |        |   *    |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |   |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |   |        |        |        |        |        |        |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/

// Layers
#define SYMBOL MO(1)
#define NUMBER MO(2)
#define SPECIAL MO(3)
#define MOVE LT(4, KC_ESC)      // Esc => MOVEMENT layer when held

// Modifiers
// #define SFTENT RSFT_T(KC_ENT)   // Enter => Shift when held
#define CTLTAB LCTL_T(KC_TAB)   // Tab => Ctrl when held

// ISO keycodes with Swedish layout names
#define SE_PLUS KC_MINS         // +
#define SE_QSTM S(SE_PLUS)      // Question mark
#define SE_TCK KC_EQL           // Fronttick (´)
#define SE_BTCK S(SE_TCK)       // Backtick (`)
#define SE_UML KC_RBRC          // Umlaut (¨)
#define SE_TAK S(SE_UML)        // Caret (^)
#define SE_TILD A(SE_UML)       // Tilde (~)
#define SE_QUT KC_NUHS          // Singlequote (')
#define SE_DQUT S(KC_2)         // Doublequote (")
#define SE_AST S(SE_QUT)        // Asterisk
#define SE_AUML KC_QUOT         // Ä
#define SE_ARNG KC_LBRC         // Å
#define SE_OUML KC_SCLN         // Ö
#define SE_LT KC_NUBS           // <
#define SE_GT S(SE_LT)          // >
#define SE_DASH KC_SLSH         // -
#define SE_USCR S(SE_DASH)      // _
#define SE_AT RALT(KC_2)        // @
#define SE_EXCL S(KC_1)         // !
#define SE_HASH S(KC_3)         // #
#define SE_USD RALT(KC_4)       // $
#define SE_PCNT S(KC_5)         // %
#define SE_AMP S(KC_6)          // &
#define SE_EQLS S(KC_0)         // =

// Apple-specific layout keys
#define AP_SLS S(KC_7)          // /
#define AP_PIPE LALT(KC_7)      // |
#define AP_BSLS A(AP_SLS)       // Backslash
#define AP_LCBR A(AP_LPAR)      // {
#define AP_RCBR A(AP_RPAR)      // }
#define AP_LBR A(KC_8)          // [
#define AP_RBR A(KC_9)          // ]
#define AP_LPAR S(KC_8)         // (
#define AP_RPAR S(KC_9)         // )

// My common shortcuts
#define MY_PREV KC_MRWD         // Media: Previous
#define MY_NEXT KC_MFFD         // Media: Next
#define MY_PLAY KC_MPLY         // Media: Play/Pause
#define MY_VOLU KC__VOLUP       // Media: Volume Up
#define MY_VOLD KC__VOLDOWN     // Media: Volume Down
#define MY_MUTE KC__MUTE        // Media: Mute
#define MY_SLEP G(A(KC_POWER))  // Mac: Sleep
#define MY_LOCK C(A(KC_L))      // Mac: Lock


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
0 DEFAULT
   Main layout for alphas and modifiers
   Tab => Ctrl when held
   Esc => MOVEMENT layer when held
   Enter => Shift when held
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   |Esc/MOVE|   Q    |   W    |   E    |   R    |   T    |   |   Y    |   U    |   I    |   O    |   P    |   Å    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |Ctrl/Tab|   A    |   S    |   D    |*  F    |   G    |   |   H    |*  J    |   K    |   L    |   Ö    |   Ä    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |  Shift |   Z    |   X    |   C    |   V    |   B    |   |   N    |   M    |   ,    |   .    |   -    | Enter  |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   | SPECIAL|  Ctrl  |  Alt   |  Cmd   | NUMBER | Space  |   | Backspc| SYMBOL |  Left  |  Down  |   Up   | Right  |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/
[0] = LAYOUT_ortho_4x12(
    MOVE,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
    CTLTAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    SE_OUML, SE_AUML,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_DASH, KC_SFTENT,
    SPECIAL, KC_LCTL, KC_LALT, KC_LGUI, NUMBER,  KC_SPC,      KC_BSPC, SYMBOL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/*
1 SYMBOLS
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   |   `    |   !    |   @    |   {    |   }    |   &    |   |        |        |        |        |        |   ´    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |   ~    |   ^    |   $    |   (    |*  )    |   '    |   |        |*       |        |        |        |   ¨    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |   |    |   #    |   %    |   [    |   ]    |   "    |   |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |   ?    |   \    |   <    |   >    |   /    |   |  Del   |XXXXXXXX|        |        |        |        |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/
[1] = LAYOUT_ortho_4x12(
    SE_BTCK, SE_EXCL, SE_AT,   AP_LCBR, AP_RCBR, SE_AMP,      _______, _______, _______, _______, _______, SE_TCK,
    SE_TILD, SE_TAK,  SE_USD,  AP_LPAR, AP_RPAR, SE_QUT,      _______, _______, _______, _______, _______, SE_UML,
    AP_PIPE, SE_HASH, SE_PCNT, AP_LBR,  AP_RBR,  SE_DQUT,     _______, _______, _______, _______, _______, _______,
    _______, SE_QSTM, AP_BSLS, SE_LT,   SE_GT,   AP_SLS,      KC_DEL,  _______, _______, _______, _______, _______
),

/*
2 NUMBERS
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   |        |  F1    |  F2    |  F3    |  F4    |        |   |        |   7    |   8    |   9    |   *    |   ´    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |  F5    |  F6    |  F7    |* F8    |        |   |        |*  4    |   5    |   6    |   +    |   ¨    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |  F9    |  F10   |  F11   |  F12   |        |   |        |   1    |   2    |   3    |   =    |   '    |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |XXXXXXXX|        |   |  Del   |        |   0    |        |        |        |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/
[2] = LAYOUT_ortho_4x12(
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,    _______, KC_7,    KC_8,    KC_9,    SE_AST,  _______,
    _______,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,    _______, KC_4,    KC_5,    KC_6,    SE_PLUS, _______,
    _______,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    _______, KC_1,    KC_2,    KC_3,    SE_EQLS, _______,
    _______,  _______, _______, _______, _______, _______,    KC_DEL,  _______, KC_0,    _______, _______, _______
),

/*
3 SPECIAL
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   | Reset  |EEPReset|        |        |        |        |   |  Lock  |        | VolUp  |        |        | Backspc|
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |*       |        |   |        |* Prev  |  Play  |  Next  |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |   |        |        | VolDn  |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |XXXXXXXX|        |        |        |        |        |   |  Mute  |        |        |        |        | Sleep  |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/
[3] = LAYOUT_ortho_4x12(
    RESET,   EEP_RST, _______, _______, _______, _______,     MY_LOCK, _______, MY_VOLU, _______, _______, KC_BSPC,
    _______, _______, _______, _______, _______, _______,     _______, MY_PREV, MY_PLAY, MY_NEXT, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, MY_VOLD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     MY_MUTE, _______, _______, _______, _______, MY_SLEP
),

/*
4 MOVEMENT
                             LEFT                                                     RIGHT
   ,-----------------------------------------------------.   ,-----------------------------------------------------.
   |XXXXXXXX|        |        |        |        |        |   |  Ins   |  Home  |   Up   |  End   |  PgUp  | Backspc|
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |*       |        |   |        |* Left  |  Down  | Right  |  PgDn  |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |   |        |        |        |        |        |        |
   |--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------|
   |        |        |        |        |        |        |   |  Del   |        |        |        |        |        |
   `-----------------------------------------------------´   `-----------------------------------------------------'
*/
[4] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______,     KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_BSPC,
    _______, _______, _______, _______, _______, _______,     _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     KC_DEL,  _______, _______, _______, _______, _______
)


};





















// KANINMATS LAYOUT

// #include QMK_KEYBOARD_H
// #include "kaninmat.h"
//
// extern keymap_config_t keymap_config;
//
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	/* QWERTY
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * | Ctrl | <|>  | Win  | Alt  |Lower |Space |VIM_W |Raise | Left | Down |  Up  |Right |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_QWERTY] = LAYOUT(
// 		KC_TAB           , KC_Q    , KC_W    , KC_E    , KC_R  , KC_T   , KC_Y  , KC_U  , KC_I    , KC_O    , KC_P    , KC_BSPC ,
// 		LT(_NAVI,KC_ESC) , KC_A    , KC_S    , KC_D    , KC_F  , KC_G   , KC_H  , KC_J  , KC_K    , KC_L    , KC_SCLN , KC_QUOT ,
// 		KC_LSFT          , KC_Z    , KC_X    , KC_C    , KC_V  , KC_B   , KC_N  , KC_M  , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT  ,
// 		KC_LCTL          , KC_NUBS , KC_LGUI , KC_LALT , LOWER , KC_SPC , VIM_W , RAISE , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT),
//
// 	/* Navigational
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |      |      |      |      |      |      |      |TAP_G |      |      |      | Del  |
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |  Up  |Right |      |      |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |      |      |      |      |      | Mute | Mute |      | Home | End  | PgDn | PgUp |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_NAVI] = LAYOUT(
// 		_______ , _______ , _______ , _______ , _______ , _______ , _______ , TD(TAP_G) , _______ , _______  , _______ , KC_DEL  ,
// 		_______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_LEFT , KC_DOWN   , KC_UP   , KC_RIGHT , _______ , _______ ,
// 		_______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______   , _______ , _______  , _______ , _______ ,
// 		_______ , _______ , _______ , _______ , _______ , KC_MUTE , KC_MUTE , _______   , KC_HOME , KC_END   , KC_PGDN , KC_PGUP),
//
// 	/* Lower
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * |Pause |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |   :  |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Home | End  | PSCR |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |      |      |      |  App |      | DIFF |VIM_CP|      | Home | End  | PgDn | PgUp |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_LOWER] = LAYOUT(
// 		KC_TILD , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_DEL    ,
// 		KC_PAUS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_UNDS , KC_PLUS , KC_LCBR , KC_RCBR , KC_PIPE   ,
// 		_______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , KC_HOME , KC_END  , KC_PSCREEN,
// 		_______ , _______ , _______ , KC_APP  , _______ , MY_DIFF , VIM_CP  , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END)   ,
//
// 	/* Raise
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * | RCtl |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  ;   |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | PgUp | PgDn |Insert|
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |      |      |      |      |      | PLAY |VIM_CN|      | Home | PgDn | PgUp | End  |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_RAISE] = LAYOUT(
// 		KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6   , KC_7    , KC_8    , KC_9    , KC_0    , KC_DEL ,
// 		KC_RCTL , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6  , KC_MINS , KC_EQL  , KC_LBRC , KC_RBRC , KC_BSLS,
// 		_______ , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12 , MY_BSLS , MY_PIPE , KC_PGUP , KC_PGDN , KC_INS ,
// 		_______ , _______ , _______ , _______ , _______ , KC_MPLY , VIM_CN , _______ , KC_HOME , KC_PGDN , KC_PGUP , KC_END),
//
// 	/* Adjust (Lower + Raise)
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |  `   | Build| Clean|      |      |      |      |      |      |      |      |RESET |
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * |VIM_W |   @  |      |  €   |  µ   |      |      |      |      |      |      |MY_NT |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |VIM_CP|      |      |      |      |      |      |      |      |      |      |  MD  |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |VIM_CN|      |      |      |      |      |      |      |      |VIM_BP|VIM_BN| Game |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_ADJUST] = LAYOUT(
// 		MY_APO , CLEAN   , BUILD   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , RESET     ,
// 		VIM_W  , MY_AT   , _______ , MY_EURO , MY_MICR , _______ , _______ , _______ , _______ , _______ , _______ , MY_NT     ,
// 		VIM_CP , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , MY_MD     ,
// 		VIM_CN , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , VIM_BP  , VIM_BN  , TO(_GAME)),
//
// 	/* Game
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |QWERTY|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |QWERTY|
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   I  |   O  |   P  |      |SCRSH |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |      |   X  |  Up  |   C  |      |      |      |      |      |      |      |      |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |      | Left | Down | Right| GFN  |      |      |      |      |      |      |      |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_GAME] = LAYOUT(
// 		TO(_QWERTY) , KC_1    , KC_2    , KC_3    , KC_4     , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , TO(_QWERTY),
// 		_______     , KC_A    , KC_S    , KC_D    , KC_F     , KC_G    , KC_H    , KC_I    , KC_O    , KC_P    , _______ , MY_SCRSH   ,
// 		_______     , KC_X    , KC_UP   , KC_C    , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______    ,
// 		_______     , KC_LEFT , KC_DOWN , KC_RGHT , MO(_GFN) , _______ , _______ , _______ , _______ , _______ , _______ , _______)   ,
//
// 	/* Game Fn-layer
// 	 * ,-----------------------------------------------------------------------------------.
// 	 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |QWERTY|
// 	 * |------+------+------+------+------+-------------+------+------+------+------+------|
// 	 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   I  |   O  |   P  |      |      |
// 	 * |------+------+------+------+------+------|------+------+------+------+------+------|
// 	 * |      |   X  |  Up  |   C  |      |      |      |      |      |      |      |      |
// 	 * |------+------+------+------+------+------+------+------+------+------+------+------|
// 	 * |      | Left | Down | Right|      |      |      |      |      |      |      |      |
// 	 * `-----------------------------------------------------------------------------------'
// 	 */
// 	[_GFN] = LAYOUT(
// 		_______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , TO(_QWERTY),
// 		_______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_F    , KC_G    , KC_H    , KC_I    , KC_O    , KC_P    , _______    ,
// 		_______ , KC_X    , KC_UP   , KC_C    , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______    ,
// 		_______ , KC_LEFT , KC_DOWN , KC_RGHT , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______)
// };
