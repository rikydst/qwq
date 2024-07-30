// SPDX-FileCopyrightText: 2024 Takahiro Natsume ( @nuovotaka )
// SPDX-License-Identifier: GPL-2.0-or-later

#include <string.h>
#include "quantum.h"
#include "matrix.h"
#include "debounce.h"

#define PINNUM_ROW (MATRIX_ROWS)
#define ROWS_PER_HAND (MATRIX_ROWS)

#define PINNUM_COL (MATRIX_COLS / 2)

#define MATRIXSIZE_PER_HAND (ROWS_PER_HAND * sizeof(matrix_row_t))

static pin_t row_pins[PINNUM_ROW] = MATRIX_ROW_PINS;
static pin_t col_pins[PINNUM_COL] = MATRIX_COL_PINS;

static inline void set_pin_input(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_input_high(pin);
    }
}

static void set_pins_input(pin_t *pins, uint8_t n)
{
    for (uint8_t i = 0; i < n; i++)
    {
        set_pin_input(pins[i]);
    }
}

static inline void set_pin_output(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        gpio_set_pin_output(pin);
        gpio_write_pin_low(pin);
    }
}

static inline bool read_pin(pin_t pin) {
    return gpio_read_pin(pin);
}

__attribute__((weak)) void duplex_scan_post_kb(matrix_row_t out_matrix[]) {}

static void duplex_scan(matrix_row_t out_matrix[]) {
    // scan column to row
    for (uint8_t row = 0; row < PINNUM_ROW; row++)
    {
        set_pin_output(row_pins[row]);
        matrix_output_select_delay();
        for (uint8_t col = 0; col < PINNUM_COL; col++) {
            if (!read_pin(col_pins[col])) {
                out_matrix[row] |= 1 << col;
            }
        }
        set_pin_input(row_pins[row]);
        matrix_output_unselect_delay(row, false);
    }

    // scan row to column.
    for (uint8_t col = 0; col < PINNUM_COL; col++)
    {
        set_pin_output(col_pins[col]);
        matrix_output_select_delay();
        matrix_row_t shifter = ((matrix_row_t)1) << (col + PINNUM_COL);
        for (uint8_t row = 0; row < PINNUM_ROW; row++) {
            if (!read_pin(row_pins[row])) {
                out_matrix[row] |= shifter;
            }
        }
        set_pin_input(col_pins[col]);
        matrix_output_unselect_delay(col, false);
    }

    duplex_scan_post_kb(out_matrix);
}

void matrix_init_custom(void)
{
    set_pins_input(col_pins, PINNUM_COL);
    set_pins_input(row_pins, PINNUM_ROW);
}

// declare matrix buffers which defined in quantum/matrix_common.c
extern matrix_row_t raw_matrix[MATRIX_ROWS];
extern matrix_row_t matrix[MATRIX_ROWS];

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;
    matrix_row_t tmp[MATRIX_ROWS] = {0};

    duplex_scan(tmp);
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        if (tmp[row] != current_matrix[row]) {
            changed = true;
            current_matrix[row] = tmp[row];
        }
    }

    return changed;
}
