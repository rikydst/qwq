

//enum unicode_names {
//    EGRAVE,
//    EAIGU,
//    ECIRC,
//    ETREMA,
//    AGRAVE,
//    ACIRC,
//    ATREMA,
//    ICIRC,
//    ITREMA,
//    OCIRC,
//    OTREMA,
//    UCIRC,
//    UTREMA,
//    UAIGU,
//    WARNING,
//};
//const uint32_t unicode_map[] PROGMEM = {
//    [EGRAVE] = 0x00C8, // È
//    [EAIGU] = 0x00C9, // É
//    [ECIRC] = 0x00CA, // Ê
//    [ETREMA] = 0x00CB, // Ë
//    [AGRAVE] = 0x00C0, // À
//    [ACIRC] = 0x00C2, // Â
//    [ATREMA] = 0x00C4, // Ä
//    [ICIRC] = 0x00CE, // Î
//    [ITREMA] = 0x00CF, // Ï
//    [OCIRC] = 0x00D4, // Ô
//    [OTREMA] = 0x00D6, // Ö
//    [UAIGU] = 0x00D9, // Ù
//    [UCIRC] = 0x00DB, // Û
//    [UTREMA] = 0x00DC, // Ü
//    [WARNING] = 0x26A0, // warning
//};

// Initialize variable holding the binary


/*
 * default HHKB Layout
 */
#include QMK_KEYBOARD_H
//#include "print.h"


/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
 * │ ² │ & │ é │ " │ ' │ ( │ - │ è │ _ │ ç │ à │ ) │ = │       │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
 * │     │ A │ Z │ E │ R │ T │ Y │ U │ I │ O │ P │ ^ │ $ │     │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
 * │      │ Q │ S │ D │ F │ G │ H │ J │ K │ L │ M │ ù │ * │    │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
 * │    │ < │ W │ X │ C │ V │ B │ N │ , │ ; │ : │ ! │          │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
 * │    │    │    │                        │    │    │    │    │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 */
#define FR_SUP2 KC_GRV  // ²
#define FR_AMPR KC_1    // &
#define FR_EACU KC_2    // é
#define FR_DQUO KC_3    // "
#define FR_QUOT KC_4    // '
#define FR_LPRN KC_5    // (
#define FR_MINS KC_6    // -
#define FR_EGRV KC_7    // è
#define FR_UNDS KC_8    // _
#define FR_CCED KC_9    // ç
#define FR_AGRV KC_0    // à
#define FR_RPRN KC_MINS // )
#define FR_EQL KC_EQL   // =
#define FR_A KC_Q       // A
#define FR_Z KC_W       // Z
#define FR_E KC_E       // E
#define FR_R KC_R       // R
#define FR_T KC_T       // T
#define FR_Y KC_Y       // Y
#define FR_U KC_U       // U
#define FR_I KC_I       // I
#define FR_O KC_O       // O
#define FR_P KC_P       // P
#define FR_CIRC KC_LBRC // ^ (dead)
#define FR_DLR KC_RBRC  // $
#define FR_Q KC_A       // Q
#define FR_S KC_S       // S
#define FR_D KC_D       // D
#define FR_F KC_F       // F
#define FR_G KC_G       // G
#define FR_H KC_H       // H
#define FR_J KC_J       // J
#define FR_K KC_K       // K
#define FR_L KC_L       // L
#define FR_M KC_SCLN    // M
#define FR_UGRV KC_QUOT // ù
#define FR_ASTR KC_NUHS // *
#define FR_LABK KC_NUBS // <
#define FR_W KC_Z       // W
#define FR_X KC_X       // X
#define FR_C KC_C       // C
#define FR_V KC_V       // V
#define FR_B KC_B       // B
#define FR_N KC_N       // N
#define FR_COMM KC_M    // ,
#define FR_SCLN KC_COMM // ;
#define FR_COLN KC_DOT  // :
#define FR_EXLM KC_SLSH // !
#define FR_1 S(FR_AMPR)   // 1
#define FR_2 S(FR_EACU)   // 2
#define FR_3 S(FR_DQUO)   // 3
#define FR_4 S(FR_QUOT)   // 4
#define FR_5 S(FR_LPRN)   // 5
#define FR_6 S(FR_MINS)   // 6
#define FR_7 S(FR_EGRV)   // 7
#define FR_8 S(FR_UNDS)   // 8
#define FR_9 S(FR_CCED)   // 9
#define FR_0 S(FR_AGRV)   // 0
#define FR_DEG S(FR_RPRN) // °
#define FR_PLUS S(FR_EQL) // +
#define FR_DIAE S(FR_CIRC) // ¨ (dead)
#define FR_PND S(FR_DLR)   // £
#define FR_PERC S(FR_UGRV) // %
#define FR_MICR S(FR_ASTR) // µ
#define FR_RABK S(FR_LABK) // >
#define FR_QUES S(FR_COMM) // ?
#define FR_DOT S(FR_SCLN)  // .
#define FR_SLSH S(FR_COLN) // /
#define FR_SECT S(FR_EXLM) // §
#define FR_TILD ALGR(FR_EACU) // ~ (dead)
#define FR_HASH ALGR(FR_DQUO) // #
#define FR_LCBR ALGR(FR_QUOT) // {
#define FR_LBRC ALGR(FR_LPRN) // [
#define FR_PIPE ALGR(FR_MINS) // |
#define FR_GRV ALGR(FR_EGRV)  // ` (dead)
#define FR_BSLS ALGR(FR_UNDS) // (backslash)
#define FR_AT ALGR(FR_AGRV)   // @
#define FR_RBRC ALGR(FR_RPRN) // ]
#define FR_RCBR ALGR(FR_EQL)  // }
#define FR_EURO ALGR(KC_E)   // €
#define FR_CURR ALGR(FR_DLR) // ¤

enum custom_keycodes {
    MA_BACKTICK = SAFE_RANGE,
    MA_TILD,
    MA_DELLINE,
    MA_DOWN,
    MA_UP,
    MA_RIGHT,
    MA_LEFT,
    MA_DELX2,
    MA_BSPCX2,
    MA_DOWNX2,
    MA_UPX2,
    MA_RIGHTX2,
    MA_LEFTX2,
    MA_ENTX2,
    MA_DELX4,
    MA_BSPCX4,
    MA_DOWNX4,
    MA_UPX4,
    MA_RIGHTX4,
    MA_LEFTX4,
    MA_ENTX4,
    MA_LTHUMB,
    MA_LTHUMBE,
    MA_LTHUMBD,
    MA_LTHUMB1,
    MA_LTHUMB2,
    MA_LTHUMB3,
    MA_LTHUMBG,
    MA_LTHUMBB,
    MA_LTHUMBT,
    MA_LTHUMBY,
    MA_LPINKY,
    MA_LOSLBISTRIG,
    MA_CAPSLOCK,
    MA_0,
    MA_1,
    MA_2,
    MA_3,
    MA_4,
    MA_5,
    MA_6,
    MA_7,
    MA_8,
    MA_9,
    MA_EQL,
    MA_ASTR,
    MA_DOT,
    MA_MINS,
    MA_PLUS,
    MA_ENT,
    MA_SLSH,
    MA_CIRC,
    MA_SIMPLEARROW,
    MA_DOUBLEARROW,
    MA_MOUSE,
    MA_JUMPTAB,
    MA_JUMPDETAB,
    MA_SELLINE,
    MA_CTLALTDEL,
    MA_CAPSE,
    MA_CAPSU,
    MA_CAPSI,
    MA_CAPSA,
    MA_MOUSE_BTN1,
    MA_MS_WH_UP,
    MA_MS_WH_DOWN,
    MA_LPINKYQ,
    MA_LPINKYW,
    MA_MS_BTN1_UNREG,
    MA_MS_BTN1_REG,
    MA_MS_BTN1_TAP,
    MA_LPINKYMS,
    DRAG_SCROLL,
};

#define LA_BASE 0
#define LA_MOUSE 1 // Mouse x2
#define LA_CAPSLOCK 2
#define LA_LTHUMB 3
#define LA_LTHUMBEMO 4 // LSG
#define LA_LTHUMBDMO 5 // RSG
#define LA_LTHUMBEOSL 6 // LAG - CAG
#define LA_LTHUMBDOSL 7 // LSA - CSA
#define LA_LTHUMB1MO 8 // LALT
#define LA_LTHUMB2MO 9 // RCS
#define LA_LTHUMB3MO 10 // C(G())
#define LA_RTHUMB 11
#define LA_LPINKY 12
#define LA_LPINKYQ 13
#define LA_LPINKYW 14

uint8_t mod_state;

bool isLeftThumbEMoStarted = false;
bool isLeftThumbDMoStarted = false;
//bool isDeadKeyCircStarted = false;
//bool isDeadKeyTremaStarted = false;
bool mouseLeft = false;
bool mouseRight = false;
bool mouseUp = false;
bool mouseDown = false;
bool isMouseX1Started = false;
bool isMouseX2Started = false;
bool isMouseX4Started = false;
bool scrollLeft = false;
bool scrollRight = false;
bool scrollUp = false;
bool scrollDown = false;
bool isScrollX1Started = false;
bool isScrollX2Started = false;
bool isScrollX4Started = false;
bool editModeLthumbOslStarted = false;
bool isLpinkyLayerMouseStarted = false;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LA_BASE Level: Default Layer
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Esc   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     |Win|
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Tab   | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | LGUI  | A | S | D | F | G | H | J | K | L | ; | '     | Ent |   x   | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
    | Shift | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |   x   | x |
    |-------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

        |------+------+-----------------------+------+------|
        | LAlt | Cont | ******* Space ******* | RGUI | RAlt |
        |------+------+-----------------------+------+------|
    */
    [LA_BASE] = LAYOUT(
        MA_MOUSE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, DRAG_SCROLL, KC_DEL, KC_LGUI,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, QK_REBOOT, MA_CAPSLOCK,
        MA_LPINKY, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_RCTL,
        KC_LALT, MA_LTHUMB, KC_SPC, MO(LA_RTHUMB), KC_RALT
    ),
    [LA_MOUSE] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_MS_BTN1_UNREG, MA_MS_BTN1_REG, MA_MS_BTN1_TAP, KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, MA_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        MA_LPINKYMS, KC_TRNS, MA_MS_WH_UP, MA_MS_WH_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFT, MA_DOWN, MA_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_CAPSLOCK] = LAYOUT(
        KC_TRNS, KC_TRNS, S(KC_E), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_E), KC_TRNS, KC_TRNS, S(KC_Q), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), MA_CIRC, KC_TRNS, KC_TRNS,
        MA_LPINKY, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), S(KC_SCLN), S(KC_U), KC_TRNS,
        KC_TRNS, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MO(LA_RTHUMB), KC_TRNS
    ),
    [LA_LTHUMB] = LAYOUT(
        MA_CAPSLOCK, MA_LTHUMB1, MA_LTHUMB2, MA_LTHUMB3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, C(KC_Q), C(KC_W), MA_LTHUMBE, C(KC_R), MA_LTHUMBT, MA_LTHUMBY, MA_7, MA_8, MA_9, MA_EQL, MA_ASTR, KC_TRNS, KC_TRNS,
        KC_TRNS, C(KC_Z), C(KC_S), MA_LTHUMBD, C(KC_F), MA_LTHUMBG, MA_DOT, MA_4, MA_5, MA_6, MA_MINS, MA_PLUS, MA_ENT,
        KC_LSFT, C(KC_A), C(KC_X), C(KC_C), C(KC_V), MA_LTHUMBB, MA_0, MA_1, MA_2, MA_3, MA_SLSH, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC, MO(LA_RTHUMB), KC_TRNS
    ),
    [LA_LTHUMBEMO] = LAYOUT(
        LSG(KC_ESC), MA_SELLINE, LSG(KC_2), LSG(KC_3), LSG(KC_4), LSG(KC_5), LSG(KC_6), LSG(KC_7), LSG(KC_8), LSG(KC_9), LSG(KC_0), LSG(KC_MINS), LSG(KC_EQL), LSG(KC_BSLS), KC_TRNS,
        LSG(KC_TAB), C(KC_V), C(KC_X), C(KC_C), LSG(KC_R), LSG(KC_T), LSG(KC_Y), LSG(KC_U), LSG(KC_I), LSG(KC_O), LSG(KC_P), LSG(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LSG(KC_A), G(KC_E), G(KC_D), LSG(KC_F), LSG(KC_G), LSG(KC_H), LSG(KC_J), LSG(KC_K), LSG(KC_L), LSG(KC_SCLN), LSG(KC_QUOT), LSG(KC_ENT),
        KC_TRNS, LSG(KC_Z), LSG(KC_X), LSG(KC_C), LSG(KC_V), LSG(KC_B), LSG(KC_N), LSG(KC_M), LSG(KC_COMM), LSG(KC_DOT), LSG(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, LSG(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBDMO] = LAYOUT(
        RSG(KC_ESC), MA_JUMPDETAB, MA_JUMPTAB, RSG(KC_3), RSG(KC_4), RSG(KC_5), RSG(KC_6), RSG(KC_7), RSG(KC_8), RSG(KC_9), RSG(KC_0), RSG(KC_MINS), RSG(KC_EQL), RSG(KC_BSLS), KC_TRNS,
        RSG(KC_TAB), RSG(KC_Q), RSG(KC_W), RSG(KC_E), RSG(KC_R), RSG(KC_T), RSG(KC_Y), RSG(KC_U), RSG(KC_I), RSG(KC_O), RSG(KC_P), RSG(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, RSG(KC_A), RSG(KC_S), RSG(KC_D), RSG(KC_F), RSG(KC_G), RSG(KC_H), RSG(KC_J), RSG(KC_K), RSG(KC_L), RSG(KC_SCLN), RSG(KC_QUOT), RSG(KC_ENT),
        KC_TRNS, RSG(KC_Z), RSG(KC_X), RSG(KC_C), RSG(KC_V), RSG(KC_B), RSG(KC_N), RSG(KC_M), RSG(KC_COMM), RSG(KC_DOT), RSG(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RSG(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBEOSL] = LAYOUT(
        LAG(KC_ESC), LAG(KC_1), LAG(KC_2), LAG(KC_3), LAG(KC_4), LAG(KC_5), LAG(KC_6), LAG(KC_7), LAG(KC_8), LAG(KC_9), LAG(KC_0), LAG(KC_MINS), LAG(KC_EQL), LAG(KC_BSLS), KC_TRNS,
        LAG(KC_TAB), LAG(KC_Q), LAG(KC_W), LAG(KC_E), LAG(KC_R), LAG(KC_T), LAG(KC_Y), LAG(KC_U), LAG(KC_I), LAG(KC_O), LAG(KC_P), LAG(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LAG(KC_A), LAG(KC_S), LAG(KC_D), LAG(KC_F), LAG(KC_G), LAG(KC_H), LAG(KC_J), LAG(KC_K), LAG(KC_L), LAG(KC_SCLN), LAG(KC_QUOT), LAG(KC_ENT),
        KC_TRNS, LAG(KC_Z), LAG(KC_X), LAG(KC_C), LAG(KC_V), LAG(KC_B), LAG(KC_N), LAG(KC_M), LAG(KC_COMM), LAG(KC_DOT), LAG(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMBDOSL] = LAYOUT(
        LSA(KC_ESC), LSA(KC_1), LSA(KC_2), LSA(KC_3), LSA(KC_4), LSA(KC_5), LSA(KC_6), LSA(KC_7), LSA(KC_8), LSA(KC_9), LSA(KC_0), LSA(KC_MINS), LSA(KC_EQL), LSA(KC_BSLS), KC_TRNS,
        LSA(KC_TAB), LSA(KC_Q), LSA(KC_W), LSA(KC_E), LSA(KC_R), LSA(KC_T), LSA(KC_Y), LSA(KC_U), LSA(KC_I), LSA(KC_O), LSA(KC_P), LSA(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LSA(KC_A), LSA(KC_S), LSA(KC_D), LSA(KC_F), LSA(KC_G), LSA(KC_H), LSA(KC_J), LSA(KC_K), LSA(KC_L), LSA(KC_SCLN), LSA(KC_QUOT), LSA(KC_ENT),
        KC_TRNS, LSA(KC_Z), LSA(KC_X), LSA(KC_C), LSA(KC_V), LSA(KC_B), LSA(KC_N), LSA(KC_M), LSA(KC_COMM), LSA(KC_DOT), LSA(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB1MO] = LAYOUT(
        LALT(KC_ESC), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), LALT(KC_MINS), LALT(KC_EQL), LALT(KC_BSLS), KC_TRNS,
        LALT(KC_TAB), LALT(KC_Q), LALT(KC_W), LALT(KC_E), LALT(KC_R), LALT(KC_T), LALT(KC_Y), LALT(KC_U), LALT(KC_I), LALT(KC_O), LALT(KC_P), LALT(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, LALT(KC_A), LALT(KC_S), LALT(KC_D), LALT(KC_F), LALT(KC_G), LALT(KC_H), LALT(KC_J), LALT(KC_K), LALT(KC_L), LALT(KC_SCLN), LALT(KC_QUOT), LALT(KC_ENT),
        KC_TRNS, LALT(KC_Z), LALT(KC_X), LALT(KC_C), LALT(KC_V), LALT(KC_B), LALT(KC_N), LALT(KC_M), LALT(KC_COMM), LALT(KC_DOT), LALT(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, LALT(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB2MO] = LAYOUT(
        RCS(KC_ESC), RCS(KC_1), RCS(KC_2), RCS(KC_3), RCS(KC_4), RCS(KC_5), RCS(KC_6), RCS(KC_7), RCS(KC_8), RCS(KC_9), RCS(KC_0), RCS(KC_MINS), RCS(KC_EQL), RCS(KC_BSLS), KC_TRNS,
        RCS(KC_TAB), RCS(KC_Q), RCS(KC_W), RCS(KC_E), RCS(KC_R), RCS(KC_T), RCS(KC_Y), RCS(KC_U), RCS(KC_I), RCS(KC_O), RCS(KC_P), RCS(KC_LBRC), KC_TRNS, KC_TRNS,
        KC_TRNS, RCS(KC_A), RCS(KC_S), RCS(KC_D), RCS(KC_F), RCS(KC_G), RCS(KC_H), RCS(KC_J), RCS(KC_K), RCS(KC_L), RCS(KC_SCLN), RCS(KC_QUOT), RCS(KC_ENT),
        KC_TRNS, RCS(KC_Z), RCS(KC_X), RCS(KC_C), RCS(KC_V), RCS(KC_B), RCS(KC_N), RCS(KC_M), RCS(KC_COMM), RCS(KC_DOT), RCS(KC_SLSH), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RCS(KC_SPC), KC_TRNS, KC_TRNS
    ),
    [LA_LTHUMB3MO] = LAYOUT(
        C(G(KC_ESC)), C(G(KC_1)), C(G(KC_2)), C(G(KC_3)), C(G(KC_4)), C(G(KC_5)), C(G(KC_6)), C(G(KC_7)), C(G(KC_8)), C(G(KC_9)), C(G(KC_0)), C(G(KC_MINS)), C(G(KC_EQL)), C(G(KC_BSLS)), KC_TRNS,
        C(G(KC_TAB)), C(G(KC_Q)), C(G(KC_W)), C(G(KC_E)), C(G(KC_R)), C(G(KC_T)), C(G(KC_Y)), C(G(KC_U)), C(G(KC_I)), C(G(KC_O)), C(G(KC_P)), C(G(KC_LBRC)), KC_TRNS, KC_TRNS,
        KC_TRNS, C(G(KC_A)), C(G(KC_S)), C(G(KC_D)), C(G(KC_F)), C(G(KC_G)), C(G(KC_H)), C(G(KC_J)), C(G(KC_K)), C(G(KC_L)), C(G(KC_SCLN)), C(G(KC_QUOT)), C(G(KC_ENT)),
        KC_TRNS, C(G(KC_Z)), C(G(KC_X)), C(G(KC_C)), C(G(KC_V)), C(G(KC_B)), C(G(KC_N)), C(G(KC_M)), C(G(KC_COMM)), C(G(KC_DOT)), C(G(KC_SLSH)), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, C(G(KC_SPC)), KC_TRNS, KC_TRNS
    ),
    [LA_RTHUMB] = LAYOUT(
        KC_TRNS, FR_EURO, MA_TILD, FR_HASH, MA_BACKTICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_LBRC, FR_RBRC, FR_LCBR, FR_RCBR, FR_AT, FR_MICR, KC_TRNS, KC_PSCR, KC_SCRL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_LABK, FR_RABK, FR_LPRN, FR_RPRN, FR_PIPE, FR_SECT, KC_PSLS, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_TRNS, KC_TRNS,
        KC_TRNS, FR_DEG, FR_SUP2, FR_DLR, FR_PERC, FR_PND, KC_PPLS, KC_PMNS, KC_TRNS, KC_MEDIA_PLAY_PAUSE, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [LA_LPINKY] = LAYOUT(
        KC_LGUI, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS,
        KC_TRNS, MA_LPINKYQ, MA_LPINKYW, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, MA_DOUBLEARROW, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ESC, KC_UP, KC_ENT, MA_DELLINE, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, MA_SIMPLEARROW, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        MA_CTLALTDEL, KC_LCTL, KC_BSPC, KC_TRNS, KC_TRNS
    ),
    [LA_LPINKYQ] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MA_DELX2, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, MA_UPX2, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ESC, MA_UPX2, MA_ENTX2, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFTX2, MA_DOWNX2, MA_RIGHTX2, KC_TRNS, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCTL, MA_BSPCX2, KC_TRNS, KC_TRNS
    ),
    [LA_LPINKYW] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, MA_DELX4, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, MA_UPX4, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ESC, MA_UPX4, MA_ENTX4, KC_TRNS, KC_TRNS, KC_TRNS, MA_LEFTX4, MA_DOWNX4, MA_RIGHTX4, KC_TRNS, KC_TRNS, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LCTL, MA_BSPCX4, KC_TRNS, KC_TRNS
    ),
};


bool processKeycodeIfLBase(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LTHUMB:
            if (record->event.pressed) {
                layer_on(LA_LTHUMB);
                register_mods(MOD_MASK_CTRL);
            }
            return false;
        case MA_LPINKY:
            if (record->event.pressed) {layer_on(LA_LPINKY);}
            return false;
        case MA_MOUSE:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_CSA) {
                    reset_keyboard();
                } else {
//                    set_auto_mouse_enable(true);
                    layer_on(LA_MOUSE);
                    isMouseX1Started = true;
                    isScrollX1Started = true;
                }
            }
            return false;
        case MA_CAPSLOCK:
            if (record->event.pressed) {
                layer_on(LA_CAPSLOCK);
            }
            return false;
        case KC_SLSH:
            if (record->event.pressed) {
                if ((mod_state & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) {
                    unregister_code16(KC_LSFT);
                    tap_code16(ALGR(KC_8));
                    register_code16(KC_LSFT);
                    return false;
                }
            }
            return true;
    }
    return true;
}
bool processKeycodeIfLMouse(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_MOUSE:
            if (record->event.pressed) {
//                set_auto_mouse_enable(false);
                layer_off(LA_MOUSE);
                isMouseX1Started = false;
                isScrollX1Started = false;
            }
            return false;
        case MA_MS_BTN1_UNREG:
            if (record->event.pressed) {
                if (isLpinkyLayerMouseStarted) {isMouseX2Started = true;}
                else {unregister_code16(KC_MS_BTN1);}
            } else {
                if (isLpinkyLayerMouseStarted) {isMouseX2Started = false;}
            }
            return false;
        case MA_MS_BTN1_REG:
            if (record->event.pressed) {
                if (isLpinkyLayerMouseStarted) {isMouseX4Started = true;}
                else {register_code16(KC_MS_BTN1);}
            } else {
                if (isLpinkyLayerMouseStarted) {isMouseX4Started = false;}
            }
            return false;
        case MA_MS_BTN1_TAP:
            if (record->event.pressed) {
                tap_code16(KC_MS_BTN1);
            }
            return false;
        case MA_LPINKYMS:
            if (record->event.pressed) {
                isLpinkyLayerMouseStarted = true;
            } else {
                isLpinkyLayerMouseStarted = false;
            }
            return false;
        case MA_MS_WH_DOWN:
            if (record->event.pressed) {
                scrollDown = true;
            } else {
                scrollDown = false;
            }
            return false;
        case MA_MS_WH_UP:
            if (record->event.pressed) {
                scrollUp = true;
            } else {
                scrollUp = false;
            }
            return false;
        case MA_DOWN:
            if (record->event.pressed) {
                mouseDown = true;
            } else {
                mouseDown = false;
            }
            return false;
        case MA_UP:
            if (record->event.pressed) {
                mouseUp = true;
            } else {
                mouseUp = false;
            }
            return false;
        case MA_LEFT:
            if (record->event.pressed) {
                mouseLeft = true;
            } else {
                mouseLeft = false;
            }
            return false;
        case MA_RIGHT:
            if (record->event.pressed) {
                mouseRight = true;
            } else {
                mouseRight = false;
            }
            return false;
    }

    return true;
}
bool processKeycodeIfLCapslock(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_CAPSLOCK:
            if (record->event.pressed) {
                layer_off(LA_CAPSLOCK);
            }
            return false;
        case MA_CIRC:
//            if (record->event.pressed) {
//                if (!(isDeadKeyTremaStarted) && mod_state && MOD_MASK_SHIFT) {isDeadKeyTremaStarted=true;}
//                else if (!isDeadKeyCircStarted) {isDeadKeyCircStarted=true;}
//            }
            return false;
//        case MA_CAPSE:
//            if (record->event.pressed) {
//                if (isDeadKeyTremaStarted) {
//                    tap_code16(X(ETREMA));
//                    isDeadKeyTremaStarted=false;
//                } else if (isDeadKeyCircStarted) {
//                    register_code16(KC_RALT);
//                    tap_code16(S(X(ECIRC)));
//                    unregister_code16(KC_RALT);
//                    isDeadKeyCircStarted=false;
//                } else {
//                    register_code16(KC_RALT);
//                    tap_code16(X(ECIRC));
////                    tap_code16(S(KC_E));
//                    unregister_code16(KC_RALT);
//                }
//            }
//            return false;
//        case MA_CAPSA:
//            if (record->event.pressed) {
//                if (isDeadKeyTremaStarted) {
//                    tap_code16(X(ATREMA));
//                    isDeadKeyTremaStarted=false;
//                }
//                else if (isDeadKeyCircStarted) {
//                    tap_code16(X(ACIRC));
//                    isDeadKeyCircStarted=false;
//                }
//                else {tap_code16(S(KC_Q));}
//            }
//            return false;
//        case MA_CAPSI:
//            if (record->event.pressed) {
//                if (isDeadKeyTremaStarted) {
//                    tap_code16(X(ITREMA));
//                    isDeadKeyTremaStarted=false;
//                }
//                else if (isDeadKeyCircStarted) {
//                    tap_code16(X(ICIRC));
//                    isDeadKeyCircStarted=false;
//                }
//                else {tap_code16(S(KC_I));}
//            }
//            return false;
//        case MA_CAPSU:
//            if (record->event.pressed) {
//                if (isDeadKeyTremaStarted) {
//                    tap_code16(X(UTREMA));
//                    isDeadKeyTremaStarted=false;
//                }
//                else if (isDeadKeyCircStarted) {
//                    tap_code16(X(UCIRC));
//                    isDeadKeyCircStarted=false;
//                }
//                else {tap_code16(S(KC_U));}
//            }
//            return false;
    }
//    if (isDeadKeyCircStarted) {isDeadKeyCircStarted=false;}
//    if (isDeadKeyTremaStarted) {isDeadKeyTremaStarted=false;}
    return processKeycodeIfLMouse(keycode, record);
}
bool processKeycodeIfLThumb(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_TAB:
            return true;
    }
    unregister_mods(MOD_MASK_CTRL);
    switch (keycode) {
        case MA_LPINKY:
            if (record->event.pressed) {
                register_code16(KC_LCTL);
                layer_on(LA_LPINKY);
                layer_off(LA_LTHUMB);
            }
            return false;
        case MA_LTHUMB:
        case KC_LCTL:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMB);
            }
            return false;
        case MA_LTHUMBE:
            if (record->event.pressed) {
                layer_on(LA_LTHUMBEMO);
            }
            return false;
        case MA_LTHUMBD:
            if (record->event.pressed) {
                layer_on(LA_LTHUMBDMO);
            }
            return false;
        case MA_LTHUMB1:
            if (record->event.pressed) {
                layer_on(LA_LTHUMB1MO);
            }
            return false;
        case MA_LTHUMB2:
            if (record->event.pressed) {
                layer_on(LA_LTHUMB2MO);
            }
            return false;
        case MA_LTHUMB3:
            if (record->event.pressed) {
                layer_on(LA_LTHUMB3MO);
            }
            return false;
        case MA_0:
            if (record->event.pressed) {
                tap_code16(FR_0);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_1:
            if (record->event.pressed) {
                tap_code16(FR_1);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_2:
            if (record->event.pressed) {
                tap_code16(FR_2);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_3:
            if (record->event.pressed) {
                tap_code16(FR_3);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_4:
            if (record->event.pressed) {
                tap_code16(FR_4);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_5:
            if (record->event.pressed) {
                tap_code16(FR_5);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_6:
            if (record->event.pressed) {
                tap_code16(FR_6);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_7:
            if (record->event.pressed) {
                tap_code16(FR_7);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_8:
            if (record->event.pressed) {
                tap_code16(FR_8);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_9:
            if (record->event.pressed) {
                tap_code16(FR_9);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_EQL:
            if (record->event.pressed) {
                tap_code16(FR_EQL);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_ASTR:
            if (record->event.pressed) {
                tap_code16(FR_ASTR);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_DOT:
            if (record->event.pressed) {
                tap_code16(FR_DOT);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_MINS:
            if (record->event.pressed) {
                tap_code16(FR_MINS);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_PLUS:
            if (record->event.pressed) {
                tap_code16(FR_PLUS);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_ENT:
            if (record->event.pressed) {
                tap_code16(KC_ENT);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_SLSH:
            if (record->event.pressed) {
                tap_code16(FR_SLSH);
            }
            register_mods(MOD_MASK_CTRL);
            return false;
        case MA_CAPSLOCK:
            if (record->event.pressed) {
                if (IS_LAYER_ON(LA_CAPSLOCK)) {
                    layer_off(LA_CAPSLOCK);
                } else {
                    layer_on(LA_CAPSLOCK);
                }
            }
            register_mods(MOD_MASK_CTRL);
            return false;
    }
    register_mods(MOD_MASK_CTRL);
    return true;
}
bool processKeycodeIfLThumbEMo(uint16_t keycode, keyrecord_t* record) {
    if ((keycode != MA_LTHUMB) & (keycode != MA_LTHUMBE)) {
        isLeftThumbEMoStarted = true;
    }
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMBEMO);
                if(!isLeftThumbEMoStarted) {
                    layer_on(LA_LTHUMBEOSL);
                } else {
                    isLeftThumbEMoStarted = false;
                    layer_off(LA_LTHUMB);
                }
            }
            return false;
        case MA_SELLINE:
            if (record->event.pressed) {
                tap_code16(KC_HOME);
                tap_code16(KC_HOME);
                register_code16(KC_LSFT);
                tap_code16(KC_END);
                tap_code16(KC_RGHT);
                unregister_code16(KC_LSFT);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfLThumbDMo(uint16_t keycode, keyrecord_t* record) {
    if ((keycode != MA_LTHUMB) & (keycode != MA_LTHUMBD)) {
        isLeftThumbDMoStarted = true;
    }
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMBDMO);
                if(!isLeftThumbDMoStarted) {
                    layer_on(LA_LTHUMBDOSL);
                } else {
                    isLeftThumbDMoStarted = false;
                    layer_off(LA_LTHUMB);
                }
            }
            return false;
        case MA_JUMPTAB:
            if (!(record->event.pressed)) {
                tap_code16(KC_HOME);
                tap_code16(KC_HOME);
                tap_code16(KC_TAB);
                tap_code16(KC_DOWN);
            }
            return false;
        case MA_JUMPDETAB:
            if (!(record->event.pressed)) {
                tap_code16(KC_UP);
                tap_code16(KC_HOME);
                tap_code16(KC_HOME);
                tap_code16(KC_DEL);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfLThumbEOsl(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KC_SPC:
            register_code16(KC_LCTL);
            editModeLthumbOslStarted = true;
            return false;
    }
    if (!(record->event.pressed)) {
        if (editModeLthumbOslStarted) {unregister_code16(KC_RCTL);}
        layer_off(LA_LTHUMB);
        layer_off(LA_LTHUMBEOSL);
    }
    return true;
}
bool processKeycodeIfLThumbDOsl(uint16_t keycode, keyrecord_t* record) {

    switch (keycode) {
        case KC_SPC:
            register_code16(KC_RCTL);
            editModeLthumbOslStarted = true;
            return false;
    }
    if (!(record->event.pressed)) {
        if (editModeLthumbOslStarted) {unregister_code16(KC_RCTL);}
        layer_off(LA_LTHUMB);
        layer_off(LA_LTHUMBDOSL);
    }
    return true;
}
bool processKeycodeIfLThumb1Mo(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMB1MO);
                layer_off(LA_LTHUMB);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfLThumb2Mo(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMB2MO);
                layer_off(LA_LTHUMB);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfLThumb3Mo(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                layer_off(LA_LTHUMB3MO);
                layer_off(LA_LTHUMB);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfRThumb(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_BACKTICK:
            if (record->event.pressed) {
                tap_code16(FR_GRV);
                // timer = timer_read();
                tap_code16(KC_SPC);
            }
            return false;
        case MA_TILD:
            if (record->event.pressed) {
                tap_code16(FR_TILD);
                tap_code16(KC_SPC);
            }
            return false;
    }
    return true;
}
bool processKeycodeIfLPinky(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LTHUMB:
            if (!(record->event.pressed)) {
                unregister_code16(KC_LCTL);
            }
            return false;
        case MA_LPINKY:
            if (!(record->event.pressed)) {
                layer_off(LA_LPINKY);
                if ((mod_state & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) {
                    layer_on(LA_LTHUMB);
                    register_mods(MOD_MASK_CTRL);
                }
            }
            return false;
        case MA_LPINKYQ:
            if (record->event.pressed) {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = true;}
                else {layer_on(LA_LPINKYQ);}
            } else {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = false;}
                else {layer_off(LA_LPINKYQ);}
            }
            return false;
        case MA_LPINKYW:
            if (record->event.pressed) {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = true;}
                else {layer_on(LA_LPINKYW);}
            } else {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = false;}
                else {layer_off(LA_LPINKYW);}
            }
            return false;
        case KC_UP:
            if (mod_state & MOD_MASK_CTRL) {
                if (record->event.pressed) {
                    unregister_code16(KC_LCTL);
                    tap_code16(KC_UP);
                    register_code16(KC_LCTL);
                    return false;
                }
            }
            return true;
        case KC_DOWN:
            if (mod_state & MOD_MASK_CTRL) {
                if (record->event.pressed) {
                    unregister_code16(KC_LCTL);
                    tap_code16(KC_DOWN);
                    register_code16(KC_LCTL);
                    return false;
                }
            }
            return true;
        case MA_DELLINE:
            if (record->event.pressed) {
                tap_code16(KC_HOME);
                tap_code16(KC_HOME);
                register_code16(KC_LSFT);
                tap_code16(KC_END);
                tap_code16(KC_RGHT);
                unregister_code16(KC_LSFT);
                tap_code16(KC_DEL);
            }
            return false;
        case MA_DOUBLEARROW:
            if (record->event.pressed) {
                tap_code16(FR_EQL);
                tap_code16(FR_RABK);
                tap_code16(KC_SPC);
            }
            return false;
        case MA_SIMPLEARROW:
            if (record->event.pressed) {
                tap_code16(FR_MINS);
                tap_code16(FR_RABK);
                tap_code16(KC_SPC);
            }
            return false;
        case KC_ESC:
            if (IS_LAYER_ON(LA_LTHUMBEOSL) || IS_LAYER_ON(LA_LTHUMBDOSL)) {
                if (!(record->event.pressed)) {
                    layer_off(LA_LTHUMB);
                    layer_off(LA_LTHUMBEOSL);
                    layer_off(LA_LTHUMBDOSL);
                }
                return false;
            }
            return true;
        case MA_CTLALTDEL:
            if (record->event.pressed) {
                tap_code16(C(A(KC_DEL)));
            }
            return true;
    }
    return true;
}
bool processKeycodeIfLPinkyQ(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LPINKYQ:
            if (!(record->event.pressed)) {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX2Started = false;}
                else {layer_off(LA_LPINKYQ);}
            }
            return false;
        case MA_UPX2:
            if (record->event.pressed) {
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
            }
            return false;
        case MA_DOWNX2:
            if (record->event.pressed) {
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
            }
            return false;
        case MA_LEFTX2:
            if (record->event.pressed) {
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
            }
            return false;
        case MA_RIGHTX2:
            if (record->event.pressed) {
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
            }
            return false;
        case MA_DELX2:
            if (record->event.pressed) {
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
            }
            return false;
        case MA_ENTX2:
            if (record->event.pressed) {
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
            }
            return false;
        case MA_BSPCX2:
            if (record->event.pressed) {
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
            }
            return false;
    }
    return processKeycodeIfLPinky(keycode, record);
}
bool processKeycodeIfLPinkyW(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MA_LPINKYW:
            if (!(record->event.pressed)) {
                if (IS_LAYER_ON(LA_MOUSE)) {isMouseX4Started = false;}
                else {layer_off(LA_LPINKYW);}
            }
            return false;
        case MA_UPX4:
            if (record->event.pressed) {
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
                tap_code16(KC_UP);
            }
            return false;
        case MA_DOWNX4:
            if (record->event.pressed) {
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
                tap_code16(KC_DOWN);
            }
            return false;
        case MA_LEFTX4:
            if (record->event.pressed) {
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
                tap_code16(KC_LEFT);
            }
            return false;
        case MA_RIGHTX4:
            if (record->event.pressed) {
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
                tap_code16(KC_RIGHT);
            }
            return false;
        case MA_DELX4:
            if (record->event.pressed) {
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
                tap_code16(KC_DEL);
            }
            return false;
        case MA_ENTX4:
            if (record->event.pressed) {
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
                tap_code16(KC_ENT);
            }
            return false;
        case MA_BSPCX4:
            if (record->event.pressed) {
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
                tap_code16(KC_BSPC);
            }
            return false;
    }
    return true;
}

//void keyboard_post_init_user(void) {
//    Customise these values to desired behaviour
//    debug_enable=true;
//    debug_matrix=true;
//    debug_keyboard=true;
//    debug_mouse=true;
//}

void matrix_scan_user(void) {
    if (isMouseX4Started) {
        if (mouseRight) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = 12;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseLeft) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = -12;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } if (mouseDown) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = 12;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseUp) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = -12;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        }
    }
    else if (isMouseX2Started) {
        if (mouseDown) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = 4;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseUp) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = -4;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } if (mouseRight) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = 4;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseLeft) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = -4;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        }
    }
    else if (isMouseX1Started) {
        if (mouseDown) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = 1;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseUp) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.y = -1;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } if (mouseRight) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = 1;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (mouseLeft) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.x = -1;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        }
    }
    if (isScrollX4Started) {
        if (scrollDown) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.v = -2.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (scrollUp) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.v = 2.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } if (scrollLeft) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.h = -2.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (scrollRight) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.h = 2.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        }
    }
    else if (isScrollX2Started) {
        if (scrollDown) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.v = -0.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (scrollUp) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.v = 0.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } if (scrollLeft) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.h = -0.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        } else if (scrollRight) {
            report_mouse_t currentReport = pointing_device_get_report();
            currentReport.h = 0.5;
            pointing_device_set_report(currentReport);
            pointing_device_send();
        }
    }
    else if (isScrollX1Started) {
            if (scrollDown) {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.v = -0.1;
                pointing_device_set_report(currentReport);
                pointing_device_send();
            } else if (scrollUp) {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.v = 0.1;
                pointing_device_set_report(currentReport);
                pointing_device_send();
            } if (scrollLeft) {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.h = -0.1;
                pointing_device_set_report(currentReport);
                pointing_device_send();
            } else if (scrollRight) {
                report_mouse_t currentReport = pointing_device_get_report();
                currentReport.h = 0.1;
                pointing_device_set_report(currentReport);
                pointing_device_send();
            }
        }
}


//bool set_scrolling = false;
//void pointing_device_driver_init(void) {}
//report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) {
//    return mouse_report;
//}
//uint16_t pointing_device_driver_get_cpi(void) { return 0; }
//void pointing_device_driver_set_cpi(uint16_t cpi) {}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
//    if (keycode == DRAG_SCROLL && record->event.pressed) {
//        set_scrolling = !set_scrolling;
//    }

    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    if (IS_LAYER_ON(LA_LPINKY)) {
        if (IS_LAYER_ON(LA_LPINKYW)) {
            if (!processKeycodeIfLPinkyW(keycode, record)) {return false;}
        } else if (IS_LAYER_ON(LA_LPINKYQ)) {
            if (!processKeycodeIfLPinkyQ(keycode, record)) {return false;}
        } else {
            if (!processKeycodeIfLPinky(keycode, record)) {return false;}
        }
    }
    if (IS_LAYER_ON(LA_RTHUMB)) {
        if (!processKeycodeIfRThumb(keycode, record)) {return false;}
    }
    if (IS_LAYER_ON(LA_LTHUMB)) {
        if (IS_LAYER_ON(LA_LTHUMBEOSL)) {
            return processKeycodeIfLThumbEOsl(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMBEMO)) {
            return processKeycodeIfLThumbEMo(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMBDOSL)) {
            return processKeycodeIfLThumbDOsl(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMBDMO)) {
            return processKeycodeIfLThumbDMo(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMB1MO)) {
            return processKeycodeIfLThumb1Mo(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMB2MO)) {
            return processKeycodeIfLThumb2Mo(keycode, record);
        } else if (IS_LAYER_ON(LA_LTHUMB3MO)) {
            return processKeycodeIfLThumb3Mo(keycode, record);
        } else {
            if (!processKeycodeIfLThumb(keycode, record)) {return false;}
        }
    }
    if (IS_LAYER_ON(LA_CAPSLOCK)) {
        if (!processKeycodeIfLCapslock(keycode, record)) {return false;}
    }
    if (IS_LAYER_ON(LA_MOUSE)) {
        if (!processKeycodeIfLMouse(keycode, record)) {return false;}
    }
    return processKeycodeIfLBase(keycode, record);

}



//report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
//    if (set_scrolling) {
//        report_mouse_t currentReport = pointing_device_get_report();
//            currentReport.v = 1;
//            currentReport.h = 1;
//            currentReport.buttons |= MOUSE_BTN1;  // this is defined in report.h
//        pointing_device_set_report(currentReport);
//        pointing_device_send();
//    }
//    return mouse_report;
//}
