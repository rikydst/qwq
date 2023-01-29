// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once
// clang-format off
#define RGBLIGHT_EFFECT_BREATHE_TABLE

// Breathing center: 1.85
// Breathing max:    255

const uint8_t PROGMEM rgblight_effect_breathe_table[] = {
#if RGBLIGHT_BREATHE_TABLE_SIZE == 256
    0x22, 0x23, 0x25, 0x26, 0x28, 0x29, 0x2A, 0x2C,
    0x2D, 0x2F, 0x30, 0x32, 0x33, 0x35, 0x36, 0x38,
    0x3A, 0x3B, 0x3D, 0x3E, 0x40, 0x42, 0x43, 0x45,
    0x47, 0x49, 0x4A, 0x4C, 0x4E, 0x50, 0x51, 0x53,
    0x55, 0x57, 0x59, 0x5A, 0x5C, 0x5E, 0x60, 0x62,
    0x64, 0x66, 0x68, 0x69, 0x6B, 0x6D, 0x6F, 0x71,
    0x73, 0x75, 0x77, 0x79, 0x7B, 0x7D, 0x7F, 0x81,
    0x83, 0x85, 0x87, 0x89, 0x8A, 0x8C, 0x8E, 0x90,
    0x92, 0x94, 0x96, 0x98, 0x9A, 0x9C, 0x9E, 0x9F,
    0xA1, 0xA3, 0xA5, 0xA7, 0xA8, 0xAA, 0xAC, 0xAE,
    0xAF, 0xB1, 0xB3, 0xB4, 0xB6, 0xB8, 0xB9, 0xBB,
    0xBC, 0xBE, 0xBF, 0xC1, 0xC2, 0xC3, 0xC5, 0xC6,
    0xC7, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xD0,
    0xD1, 0xD2, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7,
    0xD7, 0xD8, 0xD9, 0xD9, 0xDA, 0xDA, 0xDB, 0xDB,
    0xDB, 0xDC, 0xDC, 0xDC, 0xDC, 0xDC, 0xDD, 0xDD,
    0xDD, 0xDD, 0xDC, 0xDC, 0xDC, 0xDC, 0xDC, 0xDB,
    0xDB, 0xDB, 0xDA, 0xDA, 0xD9, 0xD9, 0xD8, 0xD7,
    0xD7, 0xD6, 0xD5, 0xD4, 0xD3, 0xD2, 0xD2, 0xD1,
    0xD0, 0xCE, 0xCD, 0xCC, 0xCB, 0xCA, 0xC9, 0xC7,
    0xC6, 0xC5, 0xC3, 0xC2, 0xC1, 0xBF, 0xBE, 0xBC,
    0xBB, 0xB9, 0xB8, 0xB6, 0xB4, 0xB3, 0xB1, 0xAF,
    0xAE, 0xAC, 0xAA, 0xA8, 0xA7, 0xA5, 0xA3, 0xA1,
    0x9F, 0x9E, 0x9C, 0x9A, 0x98, 0x96, 0x94, 0x92,
    0x90, 0x8E, 0x8C, 0x8A, 0x89, 0x87, 0x85, 0x83,
    0x81, 0x7F, 0x7D, 0x7B, 0x79, 0x77, 0x75, 0x73,
    0x71, 0x6F, 0x6D, 0x6B, 0x69, 0x68, 0x66, 0x64,
    0x62, 0x60, 0x5E, 0x5C, 0x5A, 0x59, 0x57, 0x55,
    0x53, 0x51, 0x50, 0x4E, 0x4C, 0x4A, 0x49, 0x47,
    0x45, 0x43, 0x42, 0x40, 0x3E, 0x3D, 0x3B, 0x3A,
    0x38, 0x36, 0x35, 0x33, 0x32, 0x30, 0x2F, 0x2D,
    0x2C, 0x2A, 0x29, 0x28, 0x26, 0x25, 0x23, 0x22
#endif

#if RGBLIGHT_BREATHE_TABLE_SIZE == 128
    0x22, 0x25, 0x28, 0x2A,
    0x2D, 0x30, 0x33, 0x36,
    0x3A, 0x3D, 0x40, 0x43,
    0x47, 0x4A, 0x4E, 0x51,
    0x55, 0x59, 0x5C, 0x60,
    0x64, 0x68, 0x6B, 0x6F,
    0x73, 0x77, 0x7B, 0x7F,
    0x83, 0x87, 0x8A, 0x8E,
    0x92, 0x96, 0x9A, 0x9E,
    0xA1, 0xA5, 0xA8, 0xAC,
    0xAF, 0xB3, 0xB6, 0xB9,
    0xBC, 0xBF, 0xC2, 0xC5,
    0xC7, 0xCA, 0xCC, 0xCE,
    0xD1, 0xD2, 0xD4, 0xD6,
    0xD7, 0xD9, 0xDA, 0xDB,
    0xDB, 0xDC, 0xDC, 0xDD,
    0xDD, 0xDC, 0xDC, 0xDC,
    0xDB, 0xDA, 0xD9, 0xD8,
    0xD7, 0xD5, 0xD3, 0xD2,
    0xD0, 0xCD, 0xCB, 0xC9,
    0xC6, 0xC3, 0xC1, 0xBE,
    0xBB, 0xB8, 0xB4, 0xB1,
    0xAE, 0xAA, 0xA7, 0xA3,
    0x9F, 0x9C, 0x98, 0x94,
    0x90, 0x8C, 0x89, 0x85,
    0x81, 0x7D, 0x79, 0x75,
    0x71, 0x6D, 0x69, 0x66,
    0x62, 0x5E, 0x5A, 0x57,
    0x53, 0x50, 0x4C, 0x49,
    0x45, 0x42, 0x3E, 0x3B,
    0x38, 0x35, 0x32, 0x2F,
    0x2C, 0x29, 0x26, 0x23
#endif

#if RGBLIGHT_BREATHE_TABLE_SIZE == 64
    0x22, 0x28,
    0x2D, 0x33,
    0x3A, 0x40,
    0x47, 0x4E,
    0x55, 0x5C,
    0x64, 0x6B,
    0x73, 0x7B,
    0x83, 0x8A,
    0x92, 0x9A,
    0xA1, 0xA8,
    0xAF, 0xB6,
    0xBC, 0xC2,
    0xC7, 0xCC,
    0xD1, 0xD4,
    0xD7, 0xDA,
    0xDB, 0xDC,
    0xDD, 0xDC,
    0xDB, 0xD9,
    0xD7, 0xD3,
    0xD0, 0xCB,
    0xC6, 0xC1,
    0xBB, 0xB4,
    0xAE, 0xA7,
    0x9F, 0x98,
    0x90, 0x89,
    0x81, 0x79,
    0x71, 0x69,
    0x62, 0x5A,
    0x53, 0x4C,
    0x45, 0x3E,
    0x38, 0x32,
    0x2C, 0x26
#endif
};

static const int table_scale = 256 / sizeof(rgblight_effect_breathe_table);

