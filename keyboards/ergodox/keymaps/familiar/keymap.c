#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// Layers
#define BASE 0 // default layer
#define INTL 1 // international symbols
#define INSF 2 // international symbols shifted
#define NUMP 3 // numpad
#define ARRW 4 // function, media, arrow keys

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
/* layer 0 : default
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESC    |   1  |   2  |   3  |   4  |   5  |   6  |           |  7   |   8  |   9  |   0  |   -  |   =  | BCKSPC |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | TAB    |   Q  |   W  |   E  |   R  |   T  | HOME |           | PGUP |   Y  |   U  |   I  |   O  |   P  | DELETE |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | `      |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ENTER |
 * |--------+------+------+------+------+------|  END |           | PGDN |------+------+------+------+------+--------|
 * | (/LSFT |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  UP  | )/RSFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | LCTRL  | LGUI | MENU |   '  | LALT |                                       |[/RALT|   ]  | LEFT | DOWN |  RIGHT |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | VOL- | VOL+ |       |PRTSCR|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |SLASH/| MUTE |       |NUMLCK|WHACK/|      |
 *                                 | SPC  | MO(1)|------|       |------|MO(1) | SPC  |
 *                                 |      |      | LAY3 |       | LAY2 |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = KEYMAP(
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_HOME,
        KC_GRV,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSPO,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_END,
        KC_LCTL,    KC_LGUI,    KC_MENU,    KC_QUOT,    KC_LALT,
                                                                    KC_VOLD,    KC_VOLU,
                                                                                KC_MUTE,
                                                KC_SPC,     LT(ARRW, KC_SLSH),  TG(INTL),
        // right hand
            KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,
            KC_PGUP,    KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENTER,
            KC_PGDN,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSPC,
                        MT(MOD_RALT, KC_LBRC),  KC_RBRC,    KC_LEFT,    KC_DOWN,    KC_RGHT,
            KC_PSCR,     _______,
            KC_NLCK,
            TG(NUMP),   LT(ARRW, C_BSLS),   KC_SPC
    ),

/* layer 1: International symbols, etc
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |     ´  |   ¡  |   ²  |   ³  |   ¤  |   €  |   ¼  |           |  ½   |  ¾   |  ‘   |  ’   |  ¥   |  ×   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   ä  |   å  |   é  |   ®  |   þ  |      |           |      |  ü   |  ú   |  í   |  ó   |  ö   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   á  |   ß  |   ð  |      |      |------|           |------|      |      |      |  ø   |  ¶   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |MO(INSF)|   æ  |      |   ©  |      |      |      |           |      |  ñ   |  µ   |  ç   |      |      |MO(INSF)|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |   ¬  |   ¿  |                                       |  «   |  »   |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[INTL] = KEYMAP(
        // left hand
        UC(0x00B4), UC(0x00A1), UC(0x00B2), UC(0x00B3), UC(0x00A4), UC(0x20AC), UC(0x00BC),
        _______,    UC(0x00E4), UC(0x00E5), UC(0x00E9), UC(0x00AE), UC(0x00FE), _______,
        _______,    UC(0x00E1), UC(0x00DF), UC(0x00F0), _______,    _______,
        MO(INSF),   UC(0x00E6), _______,    UC(0x00A9), _______,    _______,    _______,
        _______,    _______,    _______,    UC(0x00AC), UC(0x00BF),
                                            _______,    _______,
                                                        _______,
                            _______,        _______,    _______,
        // right hand
            UC(0x00BD), UC(0x00BE), UC(0x2018), UC(0x2019), UC(0x00A5), UC(0x00D7), _______,
            _______,    UC(0x00FC), UC(0x00FA), UC(0x00ED), UC(0x00F3), UC(0x00F6), _______,
                        _______,    _______,    _______,    UC(0x00F8), UC(0x00B6), _______,
            _______,    UC(0x00F1), UC(0x00B5), UC(0x00E7), _______,    _______,    MO(INSF),
                                    UC(0x00AB), UC(0x00BB), _______,    _______,    _______,
            _______,    _______,
            _______,
            _______,    _______,    _______
    ),

/* layer 2 : international symbols, shifted
 * This layer is an ugly workaround; it pretends that SHIFT still works normally on keys
 * which don't produce an "upper case" or "shifted" international symobol.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |     ¨  |   ¹  |      |      |   £  |      |      |           |      |      |      |      |  —  |  ÷   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Ä  |   Å  |   É  |      |   Þ  |      |           |      |  Ü   |  Ú   |  Í   |  Ó   |  Ö   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Á  |   §  |   Ð  |      |      |------|           |------|      |      |      |  Ø   |  °   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Æ  |      |   ¢  |      |      |      |           |      |  Ñ   |      |  Ç   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |   ¦  |      |                                       |      |      |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[INSF] = KEYMAP(
        // left hand
        UC(0x00A8), UC(0x00B9), _______,    _______,    UC(0x00A3), _______,    _______,
        _______,    UC(0x00C4), UC(0x00C5), UC(0x00C9), _______,    UC(0x00DE), _______,
        _______,    UC(0x00C1), UC(0x00A7), UC(0x00D0), S(KC_F),    S(KC_G),
        _______,    UC(0x00C6), S(KC_X),    UC(0x00A2), S(KC_V),    S(KC_B),    _______,
        _______,    _______,    _______,    UC(0x00A6), _______,
                                                                    _______,    _______,
                                                                                _______,
                                                    _______,        _______,    _______,
        // right hand
            _______,    _______,    _______,    _______,    UC(0x2014), UC(0x00F7), _______,
            _______,    UC(0x00DC), UC(0x00DA), UC(0x00CD), UC(0x00D3), UC(0x00D6), _______,
                        S(KC_H),    S(KC_J),    S(KC_K),    UC(0x00D8), UC(0x00B0), _______,
            _______,    UC(0x00D1), _______,    UC(0x00C7), S(KC_DOT),  _______,    _______,
                                    _______,    _______,    _______,    _______,    _______,
            _______,    _______,
            _______,
            _______,    _______,    _______
    ),

/* layer 3: numberpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |   (  |   )  |   /  |  *   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |  -   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                       |   0  |   .  |   ,  | ENTER|        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMP] = KEYMAP(
        // left hand
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,
                                            _______,    _______,
                                                        _______,
                            _______,        _______,    _______,
        // right hand
            _______,    _______,    S(KC_9),    S(KC_0),    KC_PSLS,    KC_PAST,    _______,
            _______,    _______,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PMNS,    _______,
                        _______,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PPLS,    _______,
            _______,    _______,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PEQL,    _______,
                                    KC_KP_0,    KC_KP_DOT,  KC_PCMM,    KC_PENT,    _______,
            _______,    _______,
            _______,
            _______,    _______,    _______
    ),

/* layer 4 : functions and arrows
 * This layer is at the top so that the functions still work no matter what layers are active.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ESCAPE |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  | SYSREQ |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  UP  |      |      |      |           |      |      |      |      |      |      | INSERT |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CAPSLOCK|      | LEFT | DOWN |RIGHT |      |------|           |------| LEFT | DOWN |  UP  | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |M_PREV|M_STOP|M_PLPS|M_NEXT|      |      |           |      |      |      |      |      | PGUP |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                       |      |      | HOME | PGDN |    END |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | PAUSE|       |SYSREQ|      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |SCRLK |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[ARRW] = KEYMAP(
        // left hand
        KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
        _______,    _______,    _______,    KC_UP,      _______,    _______,    _______,
        KC_CAPS,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,
                                                                    _______,    KC_PAUSE,
                                                                                _______,
                                                    _______,        _______,    _______,
        // right hand
            KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_SYSREQ,
            _______,    _______,    _______,    _______,    _______,    _______,    KC_INS,
                        KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
            _______,    _______,    _______,    _______,    _______,    KC_PGUP,    _______,
                                    _______,    _______,    KC_HOME,    KC_PGDN,    KC_END,
            KC_SYSREQ,  _______,
            KC_SLCK,
            _______,    _______,    _______
    ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX); // Linux
    //set_unicode_input_mode(UC_OSX); // Mac OSX
    //set_unicode_input_mode(UC_WIN); // Windows (with registry key, see wiki)
    //set_unicode_input_mode(UC_WINC); // Windows (with WinCompose, see wiki)
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case INTL:
        case INSF:
            ergodox_right_led_1_on();
            break;
        case NUMP:
            ergodox_right_led_2_on();
            break;
        case ARRW:
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
