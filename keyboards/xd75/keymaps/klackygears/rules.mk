# Copyright 2020 klackygears
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

BOOTLOADER = qmk-dfu
EXTRAFLAGS += -flto

BOOTMAGIC_ENABLE = lite
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = no
