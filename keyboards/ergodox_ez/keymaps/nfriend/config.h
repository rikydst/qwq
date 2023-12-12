/* Copyright (C) 2020 Nathan Friend
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#undef DEBOUNCE
#define DEBOUNCE 15

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 1003

#define PERMISSIVE_HOLD

#define RGBLIGHT_SLEEP
