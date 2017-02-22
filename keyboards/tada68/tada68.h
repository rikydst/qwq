#ifndef TADA68_H
#define TADA68_H

#include "quantum.h"

// readability
#define XXX KC_NO

/* TADA68 ANSI layout
   * ,----------------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d    | 0e |
   * |----------------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d | 1e |
   * |----------------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2d    | 2e |
   * |----------------------------------------------------------------|
   * | 30     | 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|    3c| 3d| 3e |
   * |----------------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 49| 4a|  4b| 4c| 4d| 4e |
   * `----------------------------------------------------------------'
 */
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array

#define KEYMAP_ANSI( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, k2e, \
	k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, \
	k40, k41, k42,           k45,                k49, k4a, k4b, k4c, k4d, k4e  \
) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e}, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d, k2e}, \
	{k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e}, \
	{k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d, k4e}  \
}

void matrix_init_user(void);
void matrix_scan_user(void);

#endif
