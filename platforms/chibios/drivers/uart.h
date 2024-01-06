/* Copyright 2021
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>

#include <hal.h>

#include "gpio.h"
#include "chibios_config.h"

#ifndef UART_DRIVER
#    define UART_DRIVER SD1
#endif

#ifndef UART_TX_PIN
#    define UART_TX_PIN A9
#endif

#ifndef UART_RX_PIN
#    define UART_RX_PIN A10
#endif

#ifndef UART_CTS_PIN
#    define UART_CTS_PIN A11
#endif

#ifndef UART_RTS_PIN
#    define UART_RTS_PIN A12
#endif

#ifdef USE_GPIOV1
#    ifndef UART_TX_PAL_MODE
#        define UART_TX_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#    endif
#    ifndef UART_RX_PAL_MODE
#        define UART_RX_PAL_MODE PAL_MODE_INPUT
#    endif
#    ifndef UART_CTS_PAL_MODE
#        define UART_CTS_PAL_MODE PAL_MODE_INPUT
#    endif
#    ifndef UART_RTS_PAL_MODE
#        define UART_RTS_PAL_MODE PAL_MODE_ALTERNATE_PUSHPULL
#    endif
#else
#    ifndef UART_TX_PAL_MODE
#        define UART_TX_PAL_MODE 7
#    endif

#    ifndef UART_RX_PAL_MODE
#        define UART_RX_PAL_MODE 7
#    endif

#    ifndef UART_CTS_PAL_MODE
#        define UART_CTS_PAL_MODE 7
#    endif

#    ifndef UART_RTS_PAL_MODE
#        define UART_RTS_PAL_MODE 7
#    endif
#endif

#ifndef UART_CR1
#    define UART_CR1 0
#endif

#ifndef UART_CR2
#    define UART_CR2 0
#endif

#ifndef UART_CR3
#    define UART_CR3 0
#endif

#ifndef UART_WRDLEN
#    define UART_WRDLEN 3
#endif

#ifndef UART_STPBIT
#    define UART_STPBIT 0
#endif

#ifndef UART_PARITY
#    define UART_PARITY 0
#endif

#ifndef UART_ATFLCT
#    define UART_ATFLCT 0
#endif

void uart_init(uint32_t baud);

void uart_write(uint8_t data);

uint8_t uart_read(void);

void uart_transmit(const uint8_t *data, uint16_t length);

void uart_receive(uint8_t *data, uint16_t length);

bool uart_available(void);
