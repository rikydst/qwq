/* Copyright 2021 Gopolar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "gg86.h"

// OLED animation
#include "lib/logo.c"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 87,     86,     85,     84,     83,     82,     81,     80,     79,     78,     77,     76,     75, NO_LED,     74,     73,     72 },
    { 55,     56,     57,     58,     59,     60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71 },
    { 54,     53,     52,     51,     50,     49,     48,     47,     46,     45,     44,     43,     42,     41,     40,     39,     38 },
    { 25,     26,     27,     28,     29,     30,     31,     32,     33,     34,     35,     36, NO_LED,     37, NO_LED, NO_LED, NO_LED },
    { 24,     23,     22,     21,     20,     19,     18,     17,     16,     15,     14,     13,     12,     11, NO_LED,     10, NO_LED },
    {  0,      1,      2, NO_LED, NO_LED,      3, NO_LED, NO_LED, NO_LED, NO_LED,      4,      5,      6, NO_LED,      7,      8,      9 }
}, {
    // Key matrix (0 -> 87)
    {1  , 64}, {19 , 64}, {37 , 64},            {88 , 64}, {145, 64}, {163, 64},                                             {181, 64},                       {198, 64}, {211, 64}, {224, 64},
               {211, 52},            {185, 50}, {171, 45}, {145, 52}, {132, 52}, {119, 52}, {106, 52}, {93 , 52}, {80 , 52}, {67 , 52}, {54 , 52}, {41 , 52}, {28 , 52}, {18 , 50}, {0  , 50},
                                     {0  , 40},            {21 , 41}, {34 , 41}, {47 , 41}, {60 , 41}, {73 , 41}, {86 , 41}, {99 , 41}, {112, 41}, {125, 41}, {138, 41}, {151, 41}, {176, 42},
    {224, 29}, {211, 29}, {198, 29}, {173, 27}, {162, 29}, {149, 29}, {136, 29}, {123, 29}, {110, 29}, {97 , 29}, {84 , 29}, {71 , 29}, {58 , 29}, {45 , 29}, {32 , 29}, {19 , 29}, {3  , 29},
    {0  , 17}, {13 , 17}, {26 , 17}, {39 , 17}, {52 , 17}, {65 , 17}, {78 , 17}, {91 , 17}, {104, 17}, {117, 17}, {130, 17}, {143, 17}, {156, 17}, {175, 17}, {198, 17}, {211, 17}, {224, 17},
    {224,  0}, {211,  0}, {198,  0},            {182,  0}, {169,  0}, {156,  0}, {143,  0}, {123,  0}, {110,  0}, {97 ,  0}, {84 ,  0}, {65 ,  0}, {52 ,  0}, {39 ,  0}, {26 ,  0}, {0  ,  0},

    // Underglow (88 -> 99)
    {1  ,  6}, {50 ,  6}, {89 ,  6}, {135,  6}, {176,  6}, {198,  6}, {221, 55}, {192, 58}, {138, 59}, {96 , 61}, {42 , 59}, {7  , 60},
}, {
    // Key matrix (0 -> 87)
    1, 1, 1,    4, 1, 1,             1,       4, 4, 4,
       4,    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
             8,    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 4, 4, 4,
    4, 8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,    4, 4, 1,

    // Underglow (88 -> 99)
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
} };
#endif

#ifdef OLED_ENABLE
    uint16_t startup_timer; 

    oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
        startup_timer = timer_read();

        return rotation;
    }

    bool oled_task_kb(void) {
        static bool finished_logo = false;

        if ((timer_elapsed(startup_timer) < 5000) && !finished_logo) {
            render_logo();
        } else {
            finished_logo = true;
			
            if (!oled_task_user()) {
                return false;
            }
        }

        return true;
    }
#endif
