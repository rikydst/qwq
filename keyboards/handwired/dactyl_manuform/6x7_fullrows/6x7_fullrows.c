// Copyright 2022 Zoull Danusty (@zoullx)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "6x7_fullrows.h"

#define XX NO_LED

// LED Layout
// Columns
// 0   1   2   3   4   5   6   7   8    |   9   10  11  12  13  14  15  16  17
// Physical (Center: 126)
// 13  26  40  53  66  79  92  105 119  |   132 145 158 171 184 198 211 224 237
//                                      |                                        Rows  Physical (Center: 48)
// 06  05  04  03  02  01  00           |           46  47  48  49  50  51  52   0     11
// 07  08  09  10  11  12  13           |           59  58  57  56  55  54  53   1     21
// 20  19  18  17  16  15  14           |           60  61  62  63  64  65  66   2     32
// 21  22  23  24  25  26  27           |           73  72  71  70  69  68  67   3     43
// 34  33  32  31  30  29  28           |           74  75  76  77  78  79  80   4     53
// 35  36  37  38  39                   |                   85  84  83  82  81   5     64
//                     40  41           |           87  86                       (Count these as row 5 physically)
//                             42  43   |   89  88                               (Count these as row 5 physically)
//                             45  44   |   90  91                               6     75

led_config_t g_led_config = { {
    // Key matrix to LED index
    // Left 1-46
    { 6,  5,  4,  3,  2,  1,  0},
    { 7,  8,  9, 10, 11, 12, 13},
    {20, 19, 18, 17, 16, 15, 14},
    {21, 22, 23, 24, 25, 26, 27},
    {34, 33, 32, 31, 30, 29, 28},
    {35, 36, 37, 38, 39, 40, 41},
    {XX, XX, XX, 45, 44, 42, 43},
    // Right 47-92
    {46, 47, 48, 49, 50, 51, 52},
    {59, 58, 57, 56, 55, 54, 53},
    {60, 61, 62, 63, 64, 65, 66},
    {73, 72, 71, 70, 69, 68, 67},
    {74, 75, 76, 77, 78, 79, 80},
    {87, 86, 85, 84, 83, 82, 81},
    {89, 88, 90, 91, XX, XX, XX}
},
{
    // LED index to physical position
    // Left 1-46
    // 00       01          02          03          04          05          06
    { 92,  11}, { 79,  11}, { 66,  11}, { 53,  11}, { 40,  11}, { 26,  11}, { 13,  11},
    // 07       08          09          10          11          12          13
    { 13,  21}, { 26,  21}, { 40,  21}, { 53,  21}, { 66,  21}, { 79,  21}, { 92,  21},
    // 14       15          16          17          18          19          20
    { 92,  32}, { 79,  32}, { 66,  32}, { 53,  32}, { 40,  32}, { 26,  32}, { 13,  32},
    // 21       22          23          24          25          26          27
    { 13,  43}, { 26,  43}, { 40,  43}, { 53,  43}, { 66,  43}, { 79,  43}, { 92,  43},
    // 28       29          30          31          32          33          34
    { 92,  53}, { 79,  53}, { 66,  53}, { 53,  53}, { 40,  53}, { 26,  53}, { 13,  53},
    // 35       36          37          38          39          40          41
    { 13,  64}, { 26,  64}, { 40,  64}, { 53,  64}, { 66,  64}, { 79,  64}, { 92,  64},
    // 42       43          44          45
    {105,  64}, {119,  64}, {116,  75}, {105,  75},
    // Right 47-92
    // 46       47          48          49          50          51          52
    {158,  11}, {171,  11}, {184,  11}, {198,  11}, {211,  11}, {224,  11}, {237,  11},
    // 53       54          55          56          57          58          59
    {237,  21}, {224,  21}, {211,  21}, {198,  21}, {184,  21}, {171,  21}, {158,  21},
    // 60       61          62          63          64          65          66
    {158,  32}, {171,  32}, {184,  32}, {198,  32}, {211,  32}, {224,  32}, {237,  32},
    // 67       68          69          70          71          72          73
    {237,  43}, {224,  43}, {211,  43}, {198,  43}, {184,  43}, {171,  43}, {158,  43},
    // 74       75          76          77          78          79          80
    {158,  53}, {171,  53}, {184,  53}, {198,  53}, {211,  53}, {224,  53}, {237,  53},
    // 81       82          83          84          85          86          87
    {237,  64}, {224,  64}, {211,  64}, {198,  64}, {184,  64}, {171,  64}, {158,  64},
    // 88       89          90          91
    {145,  64}, {132,  64}, {132,  75}, {145,  75}
},
{
    // LED index to flag
    // Left 1-46
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4,
    // Right 47-92
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4
} };
