#include QMK_KEYBOARD_H

// Config
const uint8_t MAIN_COLOR[3] = {0xFF, 0x00, 0x00};

// layers, ordering is important!
enum layers {
    _MAIN,
    _INDEX,
    _FN,
    _MULTIMEDIA,
    _EMOJI,
    _EXT1,
    _EXT2,
    _EXT3,
    _EXT4,
    _EXT5,
    _EXT6,
    _RGB,
    _CONFIG,
}

const layers_leds_map[] = {
    [_MAIN] = 0,
    [_INDEX] = 1,
    [_FN] = 2,
    [_MULTIMEDIA] = 3,
    [_EMOJI] = 4,
    [_EXT1] = 5,
    [_EXT2] = 6,
    [_EXT3] = 7,
    [_EXT4] = 8,
    [_EXT5] = 9,
    [_EXT6] = 10,
    [_RGB] = 11,
    [_CONFIG] = 12,
};

enum unicode_names {
    UC_GRINNING_FACE, // 😃
    UC_BEAMING_FACE, // 😁
    UC_GRINNING_FACE_WITH_SWEAT, // 😅
    UC_ROLLING_LAUGHING, // 🤣
    UC_FACE_TEARS_JOY, // 😂
    UC_WINKING_FACE, // 😉
    UC_SMILING_FACE_HALO, // 😇
    UC_SMILING_FACE_HEARTS, // 🥰
    UC_SMILING_FACE_HEART_EYES, // 😍
    UC_FACE_BLOWING_KISS, // 😘
    UC_FACE_SAVORING_FOOD, // 😋
    UC_ZANY_FACE, // 🤪
    UC_HUGGING_FACE, // 🤗
    UC_SHUSHING_FACE, // 🤫
    UC_THINKING_FACE, // 🤔
    UC_FACE_RAISED_EYEBROW, // 🤨
    UC_NEUTRAL_FACE, // 😐
    UC_SMIRKING_FACE, // 😏
    UC_FACE_ROLLING_EYES, // 🙄
    UC_PENSIVE_FACE, // 😔
    UC_FACE_VOMITING, // 🤮
    UC_WOOZY_FACE, // 🥴
    UC_PLEADING_FACE, // 🥺
    UC_LOUDLY_CRYING_FACE, // 😭
    UC_DISAPPOINTED_FACE, // 😞
    UC_FACE_SYMBOLS_MOUTH, // 🤬
    UC_SMILING_FACE_HORNS, // 😈
    UC_SKULL, // 💀
    UC_PILE_POO, // 💩
    UC_GHOST, // 👻
    UC_ALIEN_MONSTER, // 👾
    UC_RED_HEART, // ❤
    UC_BOMB, // 💣
    UC_WAVING_HAND, // 👋
    UC_OK_HAND, // 👌
    UC_CLAPPING_HANDS, // 👏
    UC_EYES, // 👀
    UC_MAN_FACEPALMING, // 🤦
    UC_TURTLE, // 🐢
    UC_SNAKE, // 🐍
    UC_SPOUTING_WHALE, // 🐳
    UC_DRAGON, // 🐉
    UC_TREX, // 🦖
    UC_ARGENTINA_A, // 🇦
    UC_ARGENTINA_R, // 🇷
    UC_THUMBSDOWN, // 👍
    UC_THUMBSUP, // 👎
};

const uint32_t PROGMEM unicode_map[] = {
    [UC_GRINNING_FACE] = 0x1F603,
    [UC_BEAMING_FACE] = 0x1F601,
    [UC_GRINNING_FACE_WITH_SWEAT] = 0x1F605,
    [UC_ROLLING_LAUGHING] = 0x1F923,
    [UC_FACE_TEARS_JOY] = 0x1F602,
    [UC_WINKING_FACE] = 0x1F609,
    [UC_SMILING_FACE_HALO] = 0x1F607,
    [UC_SMILING_FACE_HEARTS] = 0x1F970,
    [UC_SMILING_FACE_HEART_EYES] = 0x1F60D,
    [UC_FACE_BLOWING_KISS] = 0x1F618,
    [UC_FACE_SAVORING_FOOD] = 0x1F60B,
    [UC_ZANY_FACE] = 0x1F92A,
    [UC_HUGGING_FACE] = 0x1F917,
    [UC_SHUSHING_FACE] = 0x1F92B,
    [UC_THINKING_FACE] = 0x1F914,
    [UC_FACE_RAISED_EYEBROW] = 0x1F928,
    [UC_NEUTRAL_FACE] = 0x1F610,
    [UC_SMIRKING_FACE] = 0x1F60F,
    [UC_FACE_ROLLING_EYES] = 0x1F644,
    [UC_PENSIVE_FACE] = 0x1F614,
    [UC_FACE_VOMITING] = 0x1F92E,
    [UC_WOOZY_FACE] = 0x1F974,
    [UC_PLEADING_FACE] = 0x1F97A,
    [UC_LOUDLY_CRYING_FACE] = 0x1F62D,
    [UC_DISAPPOINTED_FACE] = 0x1F61E,
    [UC_FACE_SYMBOLS_MOUTH] = 0x1F92C,
    [UC_SMILING_FACE_HORNS] = 0x1F608,
    [UC_SKULL] = 0x1F480,
    [UC_PILE_POO] = 0x1F4A9,
    [UC_GHOST] = 0x1F47B,
    [UC_ALIEN_MONSTER] = 0x1F47E,
    [UC_RED_HEART] = 0x2764,
    [UC_BOMB] = 0x1F4A3,
    [UC_WAVING_HAND] = 0x1F44B,
    [UC_OK_HAND] = 0x1F44C,
    [UC_CLAPPING_HANDS] = 0x1F44F,
    [UC_EYES] = 0x1F440,
    [UC_MAN_FACEPALMING] = 0x1F926,
    [UC_TURTLE] = 0x1F422,
    [UC_SNAKE] = 0x1F40D,
    [UC_SPOUTING_WHALE] = 0x1F433,
    [UC_DRAGON] = 0x1F409,
    [UC_TREX] = 0x1F996,
    [UC_ARGENTINA_A] = 0x1F1E6,
    [UC_ARGENTINA_R] = 0x1F1F7,
    [UC_THUMBSDOWN] = 0x1F44E,
    [UC_THUMBSUP] = 0x1F44D,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = LAYOUT_65_ansi(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_APP), KC_UP, KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LEAD, TO(_INDEX), MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_INDEX] = LAYOUT_65_ansi(
        TO(_MAIN), TO(_INDEX), TO(_FN), TO(_MULTIMEDIA), TO(_EMOJI), TO(_EXT1), TO(_EXT2), TO(_EXT3), TO(_EXT4), TO(_EXT5), TO(_EXT6), TO(_RGB), TO(_CONFIG), TO(_MAIN), KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), TO(_FN), KC_NO, KC_NO, KC_NO
    ),
    [_FN] = LAYOUT_65_ansi(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_PSCR,
        KC_TAB, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_INS, KC_SLCK,
        KC_APP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAUS,
        KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_U, KC_BTN2,
        KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, TO(_INDEX), KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R
    ),
    [_MULTIMEDIA] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPLY, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_VOLU, KC_MUTE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_MPRV, KC_VOLD, KC_MNXT
    ),
    [_EMOJI] = LAYOUT_65_ansi(
        TO(_MAIN), X(UC_GRINNING_FACE), X(UC_BEAMING_FACE), X(UC_GRINNING_FACE_WITH_SWEAT), X(UC_ROLLING_LAUGHING), X(UC_FACE_TEARS_JOY), X(UC_WINKING_FACE), X(UC_SMILING_FACE_HALO), X(UC_SMILING_FACE_HEARTS), X(UC_SMILING_FACE_HEART_EYES), X(UC_FACE_BLOWING_KISS), X(UC_FACE_SAVORING_FOOD), X(UC_ZANY_FACE), KC_BSPC, KC_HOME,
        KC_TAB, X(UC_HUGGING_FACE), X(UC_SHUSHING_FACE), X(UC_THINKING_FACE), X(UC_FACE_RAISED_EYEBROW), X(UC_NEUTRAL_FACE), X(UC_SMIRKING_FACE), X(UC_FACE_ROLLING_EYES), X(UC_PENSIVE_FACE), X(UC_FACE_VOMITING), X(UC_WOOZY_FACE), X(UC_PLEADING_FACE), X(UC_LOUDLY_CRYING_FACE), X(UC_THUMBSUP), KC_END,
        KC_APP, X(UC_DISAPPOINTED_FACE), X(UC_FACE_SYMBOLS_MOUTH), X(UC_SMILING_FACE_HORNS), X(UC_SKULL), X(UC_PILE_POO), X(UC_GHOST), X(UC_ALIEN_MONSTER), X(UC_RED_HEART), X(UC_BOMB), X(UC_WAVING_HAND), X(UC_OK_HAND), KC_ENT, KC_PGUP,
        KC_LSFT, X(UC_CLAPPING_HANDS), X(UC_EYES), X(UC_MAN_FACEPALMING), X(UC_TURTLE), X(UC_SNAKE), X(UC_SPOUTING_WHALE), X(UC_DRAGON), X(UC_TREX), X(UC_ARGENTINA_A), X(UC_ARGENTINA_R), X(UC_THUMBSDOWN), KC_UP, KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LEAD, TO(_INDEX), TO(_MAIN), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_EXT1] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_EXT2] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_EXT3] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_EXT4] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_EXT5] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_EXT6] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_RGB] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, RGB_TOG, RGB_RMOD, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, KC_NO, KC_NO, KC_NO,
        KC_NO, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
    [_CONFIG] = LAYOUT_65_ansi(
        TO(_MAIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL2,
        KC_NO, KC_PWR, KC_SLEP, KC_WAKE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, DEBUG, EEP_RST, KC_NO, KC_ACL1,
        KC_NO, UC_RMOD, UC_MOD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ACL0,
        KC_NO, MAGIC_TOGGLE_NKRO, MAGIC_UNHOST_NKRO, MAGIC_HOST_NKRO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_INDEX), KC_NO, KC_NO, KC_NO, KC_NO
    ),
};

void rgb_matrix_indicators_user(void) {

    // CapsLock Light
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(30, MAIN_COLOR[0], MAIN_COLOR[1], MAIN_COLOR[2]);
    }

    // Show Selected Layer
    rgb_matrix_set_color(layers_leds_map[get_highest_layer(layer_state)], MAIN_COLOR[0], MAIN_COLOR[1], MAIN_COLOR[2]);
}
