/*
Copyright 2022 aki27

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

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER aki27
#define PRODUCT      cocot46plus

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { D3, D2, B3, B2, D1 }
#define MATRIX_COL_PINS { D4, C6, D7, F4, F5, F6 }
#define UNUSED_PINS

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Rotary encoder */
#define ENCODERS_PAD_A { F7 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 4

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

/* ws2812 RGB LED */
#define RGB_DI_PIN B6

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    // #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 13
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define ADNS5050_SCLK_PIN         E6
#define ADNS5050_SDIO_PIN         B4
#define ADNS5050_CS_PIN           B5

#define POINTING_DEVICE_ROTATION_180
#define OLED_FONT_H "keyboards/cocot46plus/glcdfont.c"
