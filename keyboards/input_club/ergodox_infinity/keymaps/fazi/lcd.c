void st7565_lcd_color(uint16_t r, uint16_t g, uint16_t b) {
    if(st7565_is_on()){
        ergodox_infinity_lcd_color(r, g, b);
    }
}

void st7565_draw_logo(void) {
    static const char qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    st7565_write(qmk_logo, false);
}

void st7565_task_user(void) {
    st7565_draw_logo();
    switch (get_highest_layer(layer_state)) {
        case 1:
            st7565_lcd_color(0, UINT16_MAX/2, UINT16_MAX/2);
            st7565_write_ln("Symbol :)", false);
            break;
        case 2:
            break;
        default:
            st7565_lcd_color(UINT16_MAX/2, UINT16_MAX/2, UINT16_MAX/2);
            st7565_write_ln("Normal :)", false);
            break;
    }
}
