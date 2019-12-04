/* Copyright 2019 MechMerlin
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define ___ KC_NO

#define LAYOUT_ansi( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,                 \
    k10, k1d, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1e, k0e,  \
    k20, k2d, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2e,       \
    k30, k3d, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3e,            \
    k40, k4d, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4c, k4e,            \
    k50, k5d, k51, k54, k58, k59, k5a, k5c, k5e                                      \
){ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, ___, k0e },  \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e },  \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e },  \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e },  \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, ___, k4c, k4d, k4e },  \
    { k50, k51, ___, ___, k54, ___, ___, ___, k58, k59, k5a, ___, k5c, k5d, k5e }   \
}

#define LAYOUT_all( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,                 \
    k10, k1d, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1e, k0e,  \
    k20, k2d, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2e,       \
    k30, k3d, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3e,            \
    k40, k52, k4d, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4c, k4e,       \
    k50, k5d, k51, k54, k58, k59, k5a, k5c, k5e                                      \
){ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, ___, k0e },  \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e },  \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e },  \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e },  \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, ___, k4c, k4d, k4e },  \
    { k50, k51, k52, ___, k54, ___, ___, ___, k58, k59, k5a, ___, k5c, k5d, k5e }   \
}

#define LAYOUT_iso( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c,                 \
    k10, k1d, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1e, k0e,  \
    k20, k2d, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2e,            \
    k30, k3d, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k2c, k3b, k3e,       \
    k40, k52, k4d, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4c, k4e,       \
    k50, k5d, k51, k54, k58, k59, k5a, k5c, k5e                                      \
){ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, ___, k0e },  \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e },  \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e },  \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, ___, k3d, k3e },  \
    { k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, ___, k4c, k4d, k4e },  \
    { k50, k51, k52, ___, k54, ___, ___, ___, k58, k59, k5a, ___, k5c, k5d, k5e }   \
}
