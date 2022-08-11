#pragma once

typedef HSV (*dx_dy_dist_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint8_t time);

void rgb_matrix_set_color_user_config(int index, uint8_t r, uint8_t g, uint8_t b) {
    if (user_config.top_rgb_signal == false && index < 70) {
        rgb_matrix_set_color(index, r, g, b);
        return;
    }
    else if (user_config.bottom_rgb_signal == false && index >= 70) {
        rgb_matrix_set_color(index, r, g, b);
        return;
    }
    else return;
}

bool effect_runner_dx_dy_dist(effect_params_t* params, dx_dy_dist_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 2);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        int16_t dx   = g_led_config.point[i].x - k_rgb_matrix_center.x;
        int16_t dy   = g_led_config.point[i].y - k_rgb_matrix_center.y;
        uint8_t dist = sqrt16(dx * dx + dy * dy);
        RGB     rgb  = rgb_matrix_hsv_to_rgb(effect_func(rgb_matrix_config.hsv, dx, dy, dist, time));
        rgb_matrix_set_color_user_config(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}
