#pragma once

// Tapping term settings
#undef TAPPING_TERM
#define TAPPING_TERM 250
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM_PER_KEY
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define IGNORE_TAPPING_FORCE_HOLD_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

// Combos
#define COMBO_COUNT 11
#define COMBO_TERM 200

// RGB LEDs
#if defined(LED_ANIMATIONS)
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_KNIGHT
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif
#define RGBLIGHT_SLEEP

// Bootmagic
//#define BOOTMAGIC_KEY_SALT KC_Y
//#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_Q
