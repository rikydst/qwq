// Copyright 2022 Alexander Lozyuk (@keyzog)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* Select hand configuration */
#define MASTER_LEFT

#define RGBLED_NUM 88

#define RGB_MATRIX_LED_COUNT 88
#define RGB_MATRIX_SPLIT { 44, 44 }
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define SPLIT_TRANSPORT_MIRROR

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 16
#define RGBLIGHT_VAL_STEP 16
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 16
#define RGB_MATRIX_VAL_STEP 16
#define RGB_MATRIX_SPD_STEP 10
// EFFECTS
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_WAVE
// KEYPRESSES EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif


/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
