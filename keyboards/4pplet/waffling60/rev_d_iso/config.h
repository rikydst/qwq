#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14
// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS {B14,A9,B6,B5,B4}
#define MATRIX_COL_PINS {B2,A4,A3,A2,F1,F0,C15,C14,C13,B9,B8,B7,A15,B3}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define QMK_ESC_OUTPUT B2 // usually COL
#define QMK_ESC_INPUT B14 // usually ROW
