/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

#define MASTER_LEFT

#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
// #    define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_SNAKE

#    define RGBLED_NUM 12
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT { 6, 6 }
#    define RGBLIGHT_LIMIT_VAL 255
// #    define RGBLIGHT_HUE_STEP  10
// #    define RGBLIGHT_SAT_STEP  17
// #    define RGBLIGHT_VAL_STEP  17
#endif

#define RGBW