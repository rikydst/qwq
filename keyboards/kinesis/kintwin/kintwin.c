// Copyright 2023 Alex Stepanov (@alvicstep)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

void matrix_init_kb(void) {

  uint8_t led_delay_ms = 80;

  /* LED pins setup */
  setPinOutput(LED_CAPS_LOCK_PIN);
  gpio_write_pin_low(LED_CAPS_LOCK_PIN);

  wait_ms(led_delay_ms);
  setPinOutput(LED_NUM_LOCK_PIN);   
  gpio_write_pin_low(LED_NUM_LOCK_PIN);
  wait_ms(led_delay_ms);

  setPinOutput(LED_SCROLL_LOCK_PIN);   
  gpio_write_pin_low(LED_SCROLL_LOCK_PIN);
  wait_ms(led_delay_ms);

  setPinOutput(LED_COMPOSE_PIN);   
  gpio_write_pin_low(LED_COMPOSE_PIN);
  wait_ms(led_delay_ms);
  gpio_write_pin_high(LED_COMPOSE_PIN);

	matrix_init_user();
}