/* Copyright 2020 zvecr<git@zvecr.com>
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
#pragma once

#include "quantum.h"
#define ____ KC_NO

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_all( \
    K000, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, E001, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K215, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K315, \
    K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K414, \
    K500, K501, K503,             K505,                   K509,       K511, K512, K514, K515 \
) \
{ \
    { K000, ____, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, ____, ____}, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, ____}, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, ____, K215, ____}, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, ____, ____, K315, ____}, \
    { K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, ____, K414, ____, ____}, \
    { K500, K501, K503, ____, ____, K505, ____, ____, ____, K509, ____, K511, K512, ____, K514, K515, ____}, \
    { ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, E001}, \
}
