// Copyright 2023 contact@vwolf.be
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL

#define WS2812_PWM_DRIVER   PWMD4
#define WS2812_PWM_CHANNEL  4
#define WS2812_DMA_STREAM   STM32_DMA1_STREAM6  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL  2                   // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_PWM_TARGET_PERIOD 800000