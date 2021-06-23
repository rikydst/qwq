#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4B44
#define PRODUCT_ID      0x3935
#define DEVICE_VER      0x0002
#define MANUFACTURER    Kabe_Don
#define PRODUCT         98Ec

/* key matrix size */
#define MATRIX_ROWS 12
#define MATRIX_COLS 11

#define MATRIX_ROW_PINS {A4,B10,B2,B1,B0,B15,B13,B14,B12,A10,A9,A8}
#define MATRIX_COL_PINS {A0,B7,B8,B6,A3,A2,A1,B9,A7,A5,A6}
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

#define FORCE_NKRO

#define RGB_DI_PIN B4
#define RGBLED_NUM 24
#define RGBLIGHT_ANIMATIONS

#define WS2812_PWM_DRIVER PWMD3
#define WS2812_PWM_CHANNEL 1
#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#define WS2812_DMA_CHANNEL 3

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define ENCODERS_PAD_A { B3,A14 }
#define ENCODERS_PAD_B { B5,A15 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 3
/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 1
