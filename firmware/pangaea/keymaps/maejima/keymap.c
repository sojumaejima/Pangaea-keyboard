/** Nov 27, 2022
Pangaea ver.1.2 for QMK 0.18.17
[Quantum Mechanical Keyboard Firmware](https://docs.qmk.fm/#/)

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
#include "maejima.h"

#define LAYOUT_wrapper(...)     LAYOUT(__VA_ARGS__)

#ifdef ENCODER_ENABLE
// Potentiometer, Rotary encoder
enum encoder_number {
 _1ST_ENC = 0,
 _2ND_ENC
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
   KC_ESC, _________________NUMROW_15_________________,                                     _________________NUMROW_60_________________,  KC_GRV,
  _____________________6C_BASE_L1_____________________,                                     _____________________6C_BASE_R1_____________________,
  _____________________6C_BASE_L2_____________________, _______, _______, _______, _______, _____________________6C_BASE_R2_____________________,
  _____________________6C_BASE_L3_____________________, KC_LBRC, KC_MUTE, KC_HOME, KC_RBRC, _____________________6C_BASE_R3_____________________,
          MT(MOD_LALT|MOD_LSFT,KC_NO), _______BASE_LTHUMB_______,   KC_ENT,                 KC_BSPC, _______BASE_RTHUMB_______, KC_RCTL,
                    _______, _______, _______,                                                       _______, _______, _______
  ),
  [_LOWER] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                     KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
  ____________________6C_LOWER_L1_____________________,                                     ____________________6C_LOWER_R1_____________________,
  ____________________6C_LOWER_L2_____________________, _______, _______, _______, _______, ____________________6C_LOWER_R2_____________________,
  ____________________6C_LOWER_L3_____________________, _______, _______, _______, _______, ____________________6C_LOWER_R3_____________________,
           _______, ______LOWER_LTHUMB_______, _______,                                     _______, ______LOWER_RTHUMB_______, _______,
                    _______, _______, _______,                                                       _______, _______, _______
   ),
  [_RAISE] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  ____________________6C_RAISE_L1_____________________,                                     ____________________6C_RAISE_R1_____________________,
  ____________________6C_RAISE_L2_____________________, _______, _______, _______, _______, ____________________6C_RAISE_R2_____________________,
  ____________________6C_RAISE_L3_____________________, _______, _______, _______, _______, ____________________6C_RAISE_R3_____________________,
           _______, ______RAISE_LTHUMB_______, _______,                                     _______, ______RAISE_RTHUMB_______, _______,
                    _______, _______, _______,                                                       _______, _______, _______
  ),
  [_ADJUST] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  ____________________6C_ADJUST_L1____________________,                                     ____________________6C_ADJUST_R1____________________,
  ____________________6C_ADJUST_L2____________________, _______, _______, _______, _______, ____________________6C_ADJUST_R2____________________,
  ____________________6C_ADJUST_L3____________________, _______, _______, _______, _______, ____________________6C_ADJUST_R3____________________,
           _______, ______ADJUST_LTHUMB______, _______,                                     _______, ______ADJUST_RTHUMB______, _______,
                    _______, _______, _______,                                                       _______, _______, _______
  ),
#ifdef LATEX_ENABLE
  [_LATEX] = LAYOUT_wrapper(
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
  _______, _________________LATEX_L1__________________,                                     _________________LATEX_R1__________________, _______,
  _______, _________________LATEX_L2__________________, _______, _______, _______, _______, _________________LATEX_R2__________________,   TX_MU,
  _______, _________________LATEX_L3__________________, _______, _______, _______, _______, _________________LATEX_R3__________________, _______,
           _______, ______LATEX_LTHUMB_______, _______,                                     _______, ______LATEX_RTHUMB_______, _______,
                    _______, _______, _______,                                                       _______, _______, _______
  ),
#endif
};

#ifdef ENCODER_ENABLE
// Rotary encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* first encoder, left side */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
  } else if (index == 1) { /* second encoder, right side */
        if (clockwise) {
            tap_code(KC_PGUP); /* Mouse Wheel Up */
        } else {
            tap_code(KC_PGDN); /* Mouse Wheel Down */
        }
  }
  return 1;
}
#endif
