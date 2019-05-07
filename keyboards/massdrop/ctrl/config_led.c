#ifdef RGB_MATRIX_ENABLE
#include "ctrl.h"

#include "led_matrix.h"
#include "rgb_matrix.h"
#include "config_led.h"

rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {
  // R0
  { {  0 | (0 << 4) }, { 13.714 * 0.547,  13.714 * 0.553 }, 1 }, // KC_ESC
  { {  0 | (1 << 4) }, { 13.714 * 2.547,  13.714 * 0.553 }, 4 }, // KC_F1
  { {  0 | (2 << 4) }, { 13.714 * 3.547,  13.714 * 0.553 }, 4 }, // KC_F2
  { {  0 | (3 << 4) }, { 13.714 * 4.547,  13.714 * 0.553 }, 4 }, // KC_F3
  { {  0 | (4 << 4) }, { 13.714 * 5.547,  13.714 * 0.553 }, 4 }, // KC_F4
  { {  0 | (5 << 4) }, { 13.714 * 7.047,  13.714 * 0.553 }, 1 }, // KC_F5
  { {  0 | (6 << 4) }, { 13.714 * 8.047,  13.714 * 0.553 }, 1 }, // KC_F6
  { {  0 | (7 << 4) }, { 13.714 * 9.047,  13.714 * 0.553 }, 1 }, // KC_F7
  { {  6 | (0 << 4) }, { 13.714 * 10.047, 13.714 * 0.553 }, 1 }, // KC_F8
  { {  6 | (1 << 4) }, { 13.714 * 11.547, 13.714 * 0.553 }, 4 }, // KC_F9
  { {  6 | (2 << 4) }, { 13.714 * 12.547, 13.714 * 0.553 }, 4 }, // KC_F10
  { {  6 | (3 << 4) }, { 13.714 * 13.547, 13.714 * 0.553 }, 4 }, // KC_F11
  { {  6 | (4 << 4) }, { 13.714 * 14.547, 13.714 * 0.553 }, 4 }, // KC_F12
  { {  6 | (5 << 4) }, { 13.714 * 16.047, 13.714 * 0.553 }, 1 }, // KC_PSCR
  { {  6 | (6 << 4) }, { 13.714 * 17.047, 13.714 * 0.553 }, 1 }, // KC_SLCK
  { {  6 | (7 << 4) }, { 13.714 * 18.047, 13.714 * 0.553 }, 1 }, // KC_PAUS
  // R1
  { {  1 | (0 << 4) }, { 13.714 * 0.547,  13.714 * 2.053 }, 4 }, // KC_GRV
  { {  1 | (1 << 4) }, { 13.714 * 1.547,  13.714 * 2.053 }, 4 }, // KC_1
  { {  1 | (2 << 4) }, { 13.714 * 2.547,  13.714 * 2.053 }, 4 }, // KC_2
  { {  1 | (3 << 4) }, { 13.714 * 3.547,  13.714 * 2.053 }, 4 }, // KC_3
  { {  1 | (4 << 4) }, { 13.714 * 4.547,  13.714 * 2.053 }, 4 }, // KC_4
  { {  1 | (5 << 4) }, { 13.714 * 5.547,  13.714 * 2.053 }, 4 }, // KC_5
  { {  1 | (6 << 4) }, { 13.714 * 6.547,  13.714 * 2.053 }, 4 }, // KC_6
  { {  1 | (7 << 4) }, { 13.714 * 7.547,  13.714 * 2.053 }, 4 }, // KC_7
  { {  7 | (0 << 4) }, { 13.714 * 8.547,  13.714 * 2.053 }, 4 }, // KC_8
  { {  7 | (1 << 4) }, { 13.714 * 9.547,  13.714 * 2.053 }, 4 }, // KC_9
  { {  7 | (2 << 4) }, { 13.714 * 10.547, 13.714 * 2.053 }, 4 }, // KC_0
  { {  7 | (3 << 4) }, { 13.714 * 11.547, 13.714 * 2.053 }, 4 }, // KC_MINS
  { {  7 | (4 << 4) }, { 13.714 * 12.547, 13.714 * 2.053 }, 4 }, // KC_EQL
  { {  7 | (5 << 4) }, { 13.714 * 14.047, 13.714 * 2.053 }, 1 }, // KC_BSPC
  { {  7 | (6 << 4) }, { 13.714 * 16.047, 13.714 * 2.053 }, 1 }, // KC_INS
  { {  7 | (7 << 4) }, { 13.714 * 17.047, 13.714 * 2.053 }, 1 }, // KC_HOME
  { {  9 | (7 << 4) }, { 13.714 * 18.047, 13.714 * 2.053 }, 1 }, // KC_PGUP
  // R2
  { {  2 | (0 << 4) }, { 13.714 * 0.798,  13.714 * 3.053 }, 1 }, // KC_TAB
  { {  2 | (1 << 4) }, { 13.714 * 2.047,  13.714 * 3.053 }, 4 }, // KC_Q
  { {  2 | (2 << 4) }, { 13.714 * 3.047,  13.714 * 3.053 }, 4 }, // KC_W
  { {  2 | (3 << 4) }, { 13.714 * 4.047,  13.714 * 3.053 }, 4 }, // KC_E
  { {  2 | (4 << 4) }, { 13.714 * 5.047,  13.714 * 3.053 }, 4 }, // KC_R
  { {  2 | (5 << 4) }, { 13.714 * 6.047,  13.714 * 3.053 }, 4 }, // KC_T
  { {  2 | (6 << 4) }, { 13.714 * 7.047,  13.714 * 3.053 }, 4 }, // KC_Y
  { {  2 | (7 << 4) }, { 13.714 * 8.047,  13.714 * 3.053 }, 4 }, // KC_U
  { {  8 | (0 << 4) }, { 13.714 * 9.047,  13.714 * 3.053 }, 4 }, // KC_I
  { {  8 | (1 << 4) }, { 13.714 * 10.047, 13.714 * 3.053 }, 4 }, // KC_O
  { {  8 | (2 << 4) }, { 13.714 * 11.047, 13.714 * 3.053 }, 4 }, // KC_P
  { {  8 | (3 << 4) }, { 13.714 * 12.047, 13.714 * 3.053 }, 4 }, // KC_LBRC
  { {  8 | (4 << 4) }, { 13.714 * 13.047, 13.714 * 3.053 }, 4 }, // KC_RBRC
  { {  8 | (5 << 4) }, { 13.714 * 14.296, 13.714 * 3.053 }, 4 }, // KC_BSLS
  { {  8 | (6 << 4) }, { 13.714 * 16.047, 13.714 * 3.053 }, 1 }, // KC_DEL
  { {  8 | (7 << 4) }, { 13.714 * 17.047, 13.714 * 3.053 }, 1 }, // KC_END
  { {  9 | (6 << 4) }, { 13.714 * 18.047, 13.714 * 3.053 }, 1 }, // KC_PGDN
  // R3
  { {  3 | (0 << 4) }, { 13.714 * 0.922,  13.714 * 4.053 }, 1 }, // KC_CAPS
  { {  3 | (1 << 4) }, { 13.714 * 2.298,  13.714 * 4.053 }, 4 }, // KC_A
  { {  3 | (2 << 4) }, { 13.714 * 3.298,  13.714 * 4.053 }, 4 }, // KC_S
  { {  3 | (3 << 4) }, { 13.714 * 4.296,  13.714 * 4.053 }, 4 }, // KC_D
  { {  3 | (4 << 4) }, { 13.714 * 5.296,  13.714 * 4.053 }, 4 }, // KC_F
  { {  3 | (5 << 4) }, { 13.714 * 6.296,  13.714 * 4.053 }, 4 }, // KC_G
  { {  3 | (6 << 4) }, { 13.714 * 7.296,  13.714 * 4.053 }, 4 }, // KC_H
  { {  3 | (7 << 4) }, { 13.714 * 8.296,  13.714 * 4.053 }, 4 }, // KC_J
  { {  9 | (0 << 4) }, { 13.714 * 9.296,  13.714 * 4.053 }, 4 }, // KC_K
  { {  9 | (1 << 4) }, { 13.714 * 10.296, 13.714 * 4.053 }, 4 }, // KC_L
  { {  9 | (2 << 4) }, { 13.714 * 11.296, 13.714 * 4.053 }, 4 }, // KC_SCLN
  { {  9 | (3 << 4) }, { 13.714 * 12.296, 13.714 * 4.053 }, 4 }, // KC_QUOT
  { {  9 | (4 << 4) }, { 13.714 * 13.922, 13.714 * 4.053 }, 1 }, // KC_ENT
  // R4
  { {  4 | (0 << 4) }, { 13.714 * 1.172,  13.714 * 5.053 }, 1 }, // KC_LSFT
  { {  4 | (1 << 4) }, { 13.714 * 2.798,  13.714 * 5.053 }, 4 }, // KC_Z
  { {  4 | (2 << 4) }, { 13.714 * 3.798,  13.714 * 5.053 }, 4 }, // KC_X
  { {  4 | (3 << 4) }, { 13.714 * 4.798,  13.714 * 5.053 }, 4 }, // KC_C
  { {  4 | (4 << 4) }, { 13.714 * 5.798,  13.714 * 5.053 }, 4 }, // KC_V
  { {  4 | (5 << 4) }, { 13.714 * 6.798,  13.714 * 5.053 }, 4 }, // KC_B
  { {  4 | (6 << 4) }, { 13.714 * 7.798,  13.714 * 5.053 }, 4 }, // KC_N
  { {  4 | (7 << 4) }, { 13.714 * 8.798,  13.714 * 5.053 }, 4 }, // KC_M
  { { 10 | (0 << 4) }, { 13.714 * 9.798,  13.714 * 5.053 }, 4 }, // KC_COMM
  { { 10 | (1 << 4) }, { 13.714 * 10.798, 13.714 * 5.053 }, 4 }, // KC_DOT
  { { 10 | (2 << 4) }, { 13.714 * 11.798, 13.714 * 5.053 }, 4 }, // KC_SLSH
  { { 10 | (3 << 4) }, { 13.714 * 13.672, 13.714 * 5.053 }, 1 }, // KC_RSFT
  { {  9 | (5 << 4) }, { 13.714 * 17.047, 13.714 * 5.053 }, 1 }, // KC_UP
  // R5
  { {  5 | (0 << 4) }, { 13.714 * 0.672,  13.714 * 6.053 }, 1 }, // KC_LCTL
  { {  5 | (1 << 4) }, { 13.714 * 1.922,  13.714 * 6.053 }, 1 }, // KC_LGUI
  { {  5 | (2 << 4) }, { 13.714 * 3.172,  13.714 * 6.053 }, 1 }, // KC_LALT
  { {  5 | (3 << 4) }, { 13.714 * 6.922,  13.714 * 6.053 }, 4 }, // KC_SPC
  { {  5 | (4 << 4) }, { 13.714 * 10.672, 13.714 * 6.053 }, 1 }, // KC_RALT
  { {  5 | (5 << 4) }, { 13.714 * 11.922, 13.714 * 6.053 }, 1 }, // MO(1)
  { {  5 | (6 << 4) }, { 13.714 * 13.172, 13.714 * 6.053 }, 1 }, // KC_APP
  { {  5 | (7 << 4) }, { 13.714 * 14.422, 13.714 * 6.053 }, 1 }, // KC_RCTL
  { { 10 | (4 << 4) }, { 13.714 * 16.047, 13.714 * 6.053 }, 1 }, // KC_LEFT
  { { 10 | (5 << 4) }, { 13.714 * 17.047, 13.714 * 6.053 }, 1 }, // KC_DOWN
  { { 10 | (6 << 4) }, { 13.714 * 18.047, 13.714 * 6.053 }, 1 }, // KC_RGHT
  // Underglow / Border
  { { 0xFF }, { 13.714 * 18.458, 13.714 * 6.460 }, 4 },
  { { 0xFF }, { 13.714 * 16.927, 13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 15.400, 13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 13.874, 13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 12.347, 13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 10.820, 13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 9.294,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 7.767,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 6.240,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 4.714,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 3.187,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 1.660,  13.714 * 6.600 }, 4 },
  { { 0xFF }, { 13.714 * 0.138,  13.714 * 6.460 }, 4 },
  { { 0xFF }, { 13.714 * 0.000,  13.714 * 4.880 }, 4 },
  { { 0xFF }, { 13.714 * 0.000,  13.714 * 3.300 }, 4 },
  { { 0xFF }, { 13.714 * 0.000,  13.714 * 1.720 }, 4 },
  { { 0xFF }, { 13.714 * 0.136,  13.714 * 0.140 }, 4 },
  { { 0xFF }, { 13.714 * 1.660,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 3.187,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 4.714,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 6.240,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 7.767,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 9.294,  13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 10.820, 13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 12.347, 13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 13.874, 13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 15.400, 13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 16.927, 13.714 * 0.000 }, 4 },
  { { 0xFF }, { 13.714 * 18.456, 13.714 * 0.140 }, 4 },
  { { 0xFF }, { 13.714 * 18.594, 13.714 * 1.720 }, 4 },
  { { 0xFF }, { 13.714 * 18.594, 13.714 * 3.300 }, 4 },
  { { 0xFF }, { 13.714 * 18.594, 13.714 * 4.880 }, 4 },
};

#ifdef USB_LED_INDICATOR_ENABLE
void rgb_matrix_indicators_kb(void)
{
  led_matrix_indicators();
}
#endif // USB_LED_INDICATOR_ENABLE

#endif
