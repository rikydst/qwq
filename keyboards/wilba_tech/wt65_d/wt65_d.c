// Copyright 2022 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "wt65_d.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(F1);
    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        writePin(F1, led_state.caps_lock);
    }
    return true;
}