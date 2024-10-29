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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"


// Defines names for use in layer keycodes and the keymap
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _SYMBOL = 3,
    _RGB = 4
};
/*
enum layer_number {
    _BASE = 0,
    _LOWER = 1,
    _RAISE = 2,
    _TRACKBALL = 3,
    _Layer4 = 4,
    _Layer5 = 5,
    _Layer6 = 6
};
*/


#define LW_MHEN LT(1,KC_MHEN)  // lower
#define RS_HENK LT(2,KC_HENK)  // raise
#define DEL_ALT ALT_T(KC_DEL)

/*
#define CPI_SW USER00
#define SCRL_SW USER01
#define ROT_R15 USER02
#define ROT_L15 USER03
#define SCRL_MO USER04
#define SCRL_TO USER05
#define SCRL_IN USER06
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                       KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_MINUS,
      CPI_SW,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                       KC_H,    KC_J,    KC_K,    KC_L, KC_SEMICOLON, KC_QUOTE,
      KC_ESCAPE,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                       KC_N,    KC_M, KC_COMMA,  KC_DOT, KC_SLASH,  KC_ENTER,
    KC_LALT, LT(3, KC_TAB), LT(2,KC_BSPC), KC_DELETE, KC_LEFT_SHIFT,             KC_RIGHT_CTRL,  KC_MS_BTN1, LT(1, KC_SPACE), KC_RIGHT_GUI,  KC_MS_BTN2,
                                                               KC_MS_WH_UP, XXXXXXX,  KC_MS_WH_DOWN, XXXXXXX, XXXXXXX, XXXXXXX),
/* 
 *  tab   [     home    up    end   ]        ||       pgup    7     8     9   PRSCN -
 *  cpi   (     left   down  right  )        ||       pgdn    4     5     6     =    '
 *  esc   {       ]      (     )    } shift  || ctrl    *     1     2     3     \  enter
 *                alt 3/tab   bksp     rcl   || lclk space   super  0     .    
 */
  [_RAISE] = LAYOUT(
      KC_TRNS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_KP_PLUS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PSCR, KC_TRNS,
      KC_TRNS, KC_TILDE, S(KC_TILDE), KC_PIPE, KC_AMPERSAND, KC_CIRCUMFLEX,                       KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_EQUAL, KC_TRNS,
      KC_TRNS,  KC_BACKSLASH, KC_MPRV, KC_MPLY, KC_MNXT, TG(2),                                   KC_KP_ASTERISK, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS,  KC_BSPS,   KC_TRNS,             KC_TRNS,  KC_SPACE,   KC_TRNS, KC_KP_0,  KC_KP_DOT,
                                                           LCTL(KC_EQUAL), XXXXXXX,  LCTL(KC_MINUS), XXXXXXX, XXXXXXX, XXXXXXX),
  [_LOWER] = LAYOUT(
      KC_TRNS,    KC_LBRC,    KC_HOME,    KC_UP,    KC_END,    KC_RBRC,                           KC_PGUP,   KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_TRNS,
      KC_TRNS,   KC_LPRN,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_RPRN,                        KC_PGDN,   KC_F4,  KC_F5,  KC_F6,  KC_F11,  KC_TRNS,
      KC_TRNS, KC_LCBR, KC_KB_VOLUME_DOWN, KC_KB_MUTE, KC_KB_VOLUME_UP,   KC_RCBR,                  TG(1),   KC_F1,  KC_F2,  KC_F3,  KC_F12,  KC_TRNS,
                        KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS,                KC_TRNS,  KC_SPACE, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                 KC_PGUP, KC_MS_BTN3,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX),
  [_SYMBOL] = LAYOUT(
      KC_TRNS,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                                       KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
      KC_TRNS,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_TRNS,
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        CPI_SW, SCRL_SW, ROT_L15, ROT_R15, SCRL_IN, KC_TRNS,
                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,             KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX)

  [_RGB] = LAYOUT(
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                                       SCRL_TO,  CPI_SW, SCRL_SW, ROT_L15, ROT_R15, KC_TRNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD,                                       SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TRNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
      KC_TRNS, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,RGB_RMOD,                                       CPI_SW, SCRL_SW, ROT_L15, ROT_R15, SCRL_IN, KC_TRNS,
  //|-------------------------------------------------------|                                   |-------------------------------------------------------|
                        KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,             KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                              KC_TRNS, KC_TRNS,  KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX
                                                            //`--------------'  `--------------'
    )

};


keyevent_t encoder1_ccw = {
    .key = (keypos_t){.row = 4, .col = 2},
    .pressed = false
};

keyevent_t encoder1_cw = {
    .key = (keypos_t){.row = 4, .col = 5},
    .pressed = false
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            encoder1_cw.pressed = true;
            encoder1_cw.time = (timer_read() | 1);
            action_exec(encoder1_cw);
        } else {
            encoder1_ccw.pressed = true;
            encoder1_ccw.time = (timer_read() | 1);
            action_exec(encoder1_ccw);
        }
    }

    return true;
}


void matrix_scan_user(void) {

    if (IS_PRESSED(encoder1_ccw)) {
        encoder1_ccw.pressed = false;
        encoder1_ccw.time = (timer_read() | 1);
        action_exec(encoder1_ccw);
    }

    if (IS_PRESSED(encoder1_cw)) {
        encoder1_cw.pressed = false;
        encoder1_cw.time = (timer_read() | 1);
        action_exec(encoder1_cw);
    }

}



layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _LOWER:
        rgblight_sethsv_range(HSV_BLUE, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _RAISE:
        rgblight_sethsv_range(HSV_RED, 0, 2);
        cocot_set_scroll_mode(true);
        break;
    case _SYMBOL:
        rgblight_sethsv_range(HSV_GREEN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _RGB:
        rgblight_sethsv_range(HSV_YELLOW, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer5:
        rgblight_sethsv_range(HSV_CYAN, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    case _Layer6:
        rgblight_sethsv_range(HSV_ORANGE, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    default:
        rgblight_sethsv_range( 0, 0, 0, 0, 2);
        cocot_set_scroll_mode(false);
        break;
    }
    rgblight_set_effect_range( 2, 10);
      return state;
};


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    oled_write_layer_state();
    return false;
}
#endif

