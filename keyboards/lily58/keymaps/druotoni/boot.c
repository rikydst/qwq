#include QMK_KEYBOARD_H
#include "boot.h"

#include "fast_random.h"
#include "draw_helper.h"

#define ANIM_BOOT_FRAME_DURATION 8
uint32_t anim_boot_timer         = 0;
int      anim_boot_current_frame = 0;

void reset_boot(void) { anim_boot_current_frame = 0; }

static void draw_lily_key(uint8_t x, uint8_t y, uint8_t *key_number, unsigned long key_state, uint8_t color) {
    uint8_t       v    = *key_number;
    unsigned long mask = 1;
    mask               = mask << v;

    if (((key_state & mask) == mask)) {
        color = !color;
    }
    draw_rectangle_fill(x, y, 3, 3, color);
    *key_number = v + 1;
}

static void draw_lily_key_row(uint8_t x, uint8_t y, int w, uint8_t *key_number, unsigned long key_state, uint8_t color) {
    for (uint8_t i = 0; i < w; i++) {
        draw_lily_key(x + (i * 4), y, key_number, key_state, color);
    }
}

static void draw_lily_render(uint8_t x, uint8_t y, unsigned long key_state) {
    uint8_t x_ref        = 10 + x;
    uint8_t y_ref        = 2 + y;
    uint8_t i_key_number = 0;

    for (uint8_t i = 0; i < 4; i++) {
        draw_lily_key_row(x_ref, y_ref + (i * 4), 4, &i_key_number, key_state, true);
        draw_lily_key_row(x_ref - 8, y_ref + 2 + (i * 4), 2, &i_key_number, key_state, true);
    }

    draw_lily_key_row(x_ref + 2, y_ref + (4 * 4), 3, &i_key_number, key_state, true);

    uint8_t x_side = x_ref + (4 * 4);

    draw_lily_key(x_side, y_ref + (2 * 4) + 2, &i_key_number, key_state, true);
    draw_lily_key(x_side, y_ref + (4 * 4), &i_key_number, key_state, true);

    // screen
    draw_rectangle(x_side, y_ref, 4, 8, true);

    // frame
    drawline_hr(x + 1, y + 2, 8, true);
    oled_write_pixel(x + 8, y + 1, true);
    drawline_hr(x + 8, y, 23, true);

    drawline_hr(x + 1, y + 20, 10, true);
    oled_write_pixel(x + 10, y + 21, true);
    drawline_hr(x + 10, y + 22, 16, true);

    drawline_vb(x, y + 3, 17, true);
    drawline_vb(x + 31, y + 1, 20, true);
    oled_write_pixel(x + 30, y + 21, true);
    oled_write_pixel(x + 29, y + 22, true);
    oled_write_pixel(x + 28, y + 23, true);
    oled_write_pixel(x + 27, y + 24, true);
    oled_write_pixel(x + 26, y + 23, true);
}

static void draw_lily(int f) {
    uint8_t tres_stroke = 10;

    uint8_t tres_boom = 30;

    uint8_t y_start = 56;

    if (f == 0 || f == tres_stroke || f == tres_boom) {
        oled_clear();
    }

    if (f < tres_stroke) {
        draw_lily_render(0, y_start, 0);
    }

    if (f >= tres_stroke && f < tres_boom) {
        int inter_f = interpo_pourcent(tres_stroke, tres_boom, f);

        unsigned long key_state = fastrand_long();
        for (int r = 100 - inter_f; r > 0; r = r - 10) {
            key_state &= fastrand_long();
        }
        draw_lily_render(0, y_start, key_state);
    }

    if (f >= tres_boom) {
        oled_clear();
        draw_static(0, y_start - 8, 32, 32, true, (f - tres_boom));
    }
}

static void draw_startup_navi(int f) {
    oled_set_cursor(0, 5);
    oled_write("HELL0", false);

    oled_set_cursor(0, 7);
    oled_write("NAVI.", false);

    if ((f % 8) > 4) {
        oled_set_cursor(0, 12);
        oled_write("> ", false);
    } else {
        oled_set_cursor(0, 12);
        oled_write(">_", false);
    }
    uint8_t tres_shell = 15;
    uint8_t tres_load  = 35;
    if (f > tres_shell) {
        int inter_f = interpo_pourcent(tres_shell, tres_load, f);

        draw_random_char(1, 12, 'i', 60 + inter_f, 0);
        draw_random_char(2, 12, 'n', 20 + inter_f, 0);
        draw_random_char(3, 12, 'i', inter_f, 0);
        draw_random_char(4, 12, 't', 20 + inter_f, 0);
    }
    if (f > tres_load) {
        int inter_f = interpo_pourcent(tres_load, 55, f);

        // ease
        float fv = inter_f / 100.00;
        fv       = fv * fv * fv * fv;
        inter_f  = fv * 100;

        draw_rectangle(0, (15 * 8), 32, 8, 1);
        draw_progress(0 + 3, (15 * 8) + 3, 26, 2, inter_f, 0, 1);
    }
}

// static void draw_startup_terminal(int f) {
//     return;
// }

// draw_terminal_line(&ref_line ,  v_brutal, &y_brutal, "LT:", 3, "RT:", 3, 2  );
// draw_terminal_line(&ref_line ,  v_brutal, &y_brutal, "A0:", 3, "cnx:",  4, 1  );
// draw_terminal_line(&ref_line ,  v_brutal, &y_brutal, "B0:", 3, "cnx:",  4, 1  );
// static void draw_terminal_line(int  *ref_line , long v_brutal, uint8_t *y_brutal, char * s1, uint8_t l1, char * s2, uint8_t l2, int style  ) {

//    long ref_value = (*ref_line * 100 * -1) + v_brutal;
//     draw_box(s1,  l1, *y_brutal, ref_value, style);
//     *y_brutal = *y_brutal +1;
//     draw_box(s2, l2, *y_brutal, ref_value, style);
//      *y_brutal = *y_brutal +1;
//     ref_line++;
// }

#define TERMINAL_LINE_NUMBER 19
#define TERMINAL_LINE_MAX 14

static char *boot_ref[TERMINAL_LINE_NUMBER] = {"LT:", "RT:", "M :", "    ", "cnx:", "A0:", "B0:", "    ", "0x40", "0x60", "0x85", "0x0F", "    ", "> run", "x ", "y ", " 100%", "    ", "> key"};

// static void print_font(int y, int index) {

//     if(index % 3 == 0){
// oled_set_cursor(0, y);
//     oled_write("     ", false);
// return;
//     }
//     index             = (index * 4);
//     char scan_font[5] = {'>', 1, 1, 1, 1};
//     scan_font[1]      = index;
//     scan_font[2]      = index + 1;
//     scan_font[3]      = index + 2;
//     scan_font[4]      = index + 3;
//     oled_set_cursor(0, y);
//     oled_write(scan_font, false);
// }

char scan_font[5] = {'>', 1, 1, 1, 1};

static char *get_terminal_line(uint8_t i) {
    if (i < TERMINAL_LINE_NUMBER) return boot_ref[i];
    if (i % 3 == 0) return "     ";

    i = (i - TERMINAL_LINE_NUMBER) * 4;

    scan_font[1] = i;
    scan_font[2] = i + 1;
    scan_font[3] = i + 2;
    scan_font[4] = i + 3;

    return scan_font;
}

static void draw_startup_terminal(int f) {
    //  uint8_t max_size = 14;

    if (f == 0) {
        oled_clear();
    }

    // ease
    f = f * 2;
    f += (f / 5);

    uint8_t i_start   = 0;
    uint8_t i_nb_char = f;

    if (f > TERMINAL_LINE_MAX) {
        // i_start   = 0;
        // i_nb_char = f;

        i_start   = f - TERMINAL_LINE_MAX;
        i_nb_char = TERMINAL_LINE_MAX;
    }

    for (uint8_t i = 0; i < i_nb_char; i++) {
        char *s = get_terminal_line(i + i_start);
        oled_set_cursor(0, i);
        oled_write(s, false);
    }
}


// static void print_font(int y, int index) {

//     if(index % 3 == 0){
// oled_set_cursor(0, y);
//     oled_write("     ", false);
// return;
//     }
//     index             = (index * 4);
//     char scan_font[5] = {'>', 1, 1, 1, 1};
//     scan_font[1]      = index;
//     scan_font[2]      = index + 1;
//     scan_font[3]      = index + 2;
//     scan_font[4]      = index + 3;
//     oled_set_cursor(0, y);
//     oled_write(scan_font, false);
// }

// static void draw_startup_terminal(int f) {
//     uint8_t y_brutal = 0;

//     uint8_t i_scroll = 7;
//     if (f == 0) {
//         oled_clear();
//     }

//     if (f > i_scroll) {
//         oled_clear();
//         // y_brutal = i_scroll - 3 - (f);
//         y_brutal = (i_scroll * 2) - (f * 2);
//     }
//     long v_brutal = f * 100;

//     int  ref_line  = 0;
//     long ref_value = 0;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_box("LT:", 3, y_brutal, ref_value, 2);
//     y_brutal++;
//     draw_box("RT:", 3, y_brutal, ref_value, 2);
//     y_brutal++;
//     ref_line++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_box("M :", 3, y_brutal, ref_value, 2);
//     y_brutal++;
//     draw_box("cnx:", 4, y_brutal, ref_value, 2);
//     y_brutal++;
//     ref_line++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_box("A0:", 3, y_brutal, ref_value, 1);
//     y_brutal++;
//     draw_box("B0:", 3, y_brutal, ref_value, 1);
//     y_brutal++;
//     ref_line++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_label(" ", 1, y_brutal, ref_value);
//     y_brutal++;
//     ref_line++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_label("0x40", 4, y_brutal, ref_value);
//     y_brutal++;
//     draw_label("0x60", 4, y_brutal, ref_value);
//     y_brutal++;
//     draw_label("0x85", 4, y_brutal, ref_value);
//     y_brutal++;
//     draw_label("0x0F", 4, y_brutal, ref_value);
//     y_brutal++;
//     ref_line++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_label("> run", 4, y_brutal, ref_value);
//     ref_line++;
//     y_brutal++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_box("x ", 2, y_brutal, ref_value, 2);
//     ref_line++;
//     y_brutal++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_box("y ", 2, y_brutal, ref_value, 2);
//     ref_line++;
//     y_brutal++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_label(" 100%", 5, y_brutal, ref_value);
//     ref_line++;
//     y_brutal++;

//     ref_value = (ref_line * 100 * -1) + v_brutal;
//     draw_label(">key", 4, y_brutal, ref_value);
//     ref_line++;
//     y_brutal++;

//     char scan_font[5] = {'>', 1, 1, 1, 1};
//     for (uint8_t i_font = 0; i_font < 60 + 30; i_font = i_font + 8) {
//         ref_value = (ref_line * 100 * -1) + v_brutal;

//         scan_font[1] = i_font;
//         scan_font[2] = i_font + 1;
//         scan_font[3] = i_font + 2;
//         scan_font[4] = i_font + 3;
//         draw_label(scan_font, 5, y_brutal, ref_value);
//         y_brutal++;

//         scan_font[1] = i_font + 4;
//         scan_font[2] = i_font + 5;
//         scan_font[3] = i_font + 6;
//         scan_font[4] = i_font + 7;
//         draw_label(scan_font, 5, y_brutal, ref_value);

//         y_brutal++;
//         ref_line++;
//     }

//     return;
// }

void render_boot(void) {
    char t_navi     = 55;
    char t_terminal = 25;
    char t_lily     = 50;

    if (anim_boot_current_frame >= t_navi + t_terminal + t_lily) {
        anim_boot_current_frame = 0;
        oled_clear();
    }

    if (timer_elapsed32(anim_boot_timer) > ANIM_BOOT_FRAME_DURATION) {
        anim_boot_timer = timer_read32();
        if (anim_boot_current_frame < t_navi) {
            // 55 frames
            draw_startup_navi(anim_boot_current_frame);
        }

        if (anim_boot_current_frame >= t_navi && anim_boot_current_frame < t_navi + t_terminal) {
            // 25
            draw_startup_terminal(anim_boot_current_frame - t_navi);
        }

        if (anim_boot_current_frame >= t_navi + t_terminal) {
            // 25
            draw_lily(anim_boot_current_frame - t_navi - t_terminal);
        }

        anim_boot_current_frame++;
    }
}
