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

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ADJUST 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
 QWERTY = SAFE_RANGE, // Default layer
 LOWER,   // Layer 1
 RAISE,   // Layer 2
 ADJUST,  // Layer 3
};

#ifdef ENCODER_ENABLE
// Potentiometer, Rotary encoder
enum encoder_number {
 _1ST_ENC = 0,
 _2ND_ENC
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [0] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  KC_ESC ,KC_1   ,KC_2   ,   KC_3,   KC_4,   KC_5,                                   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_GRV ,
  KC_TAB ,KC_Q   ,KC_W   ,   KC_E,   KC_R,   KC_T,                                   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_BSPC,
  LCTL_T(KC_TAB),KC_A,KC_S,  KC_D,   KC_F,   KC_G,_______,_______,_______,_______,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,RGUI_T(KC_QUOT),
  KC_LSFT,KC_Z   ,KC_X   ,   KC_C,   KC_V,   KC_B,KC_LBRC,KC_MUTE,KC_HOME,KC_RBRC,   KC_N,   KC_M,KC_COMM, KC_DOT,RAG_T(KC_SLSH),KC_RSFT,
          KC_LALT,LGUI_T(KC_LNG2),  MO(1), KC_SPC,KC_ENT,                         KC_BSPC, KC_SPC,  MO(2),RALT_T(KC_LNG1),KC_RCTL,
                  _______,_______,_______,                                                _______,_______,_______
  ),
  [_LOWER] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                                KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,
  _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                KC_HOME,KC_PGDN,KC_PGUP, KC_END, KC_EQL, KC_DEL,
  _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,_______,_______,_______,KC_LEFT,KC_DOWN,  KC_UP,KC_RIGHT,KC_MINS,RGUI_T(KC_GRV),
  _______,XXXXXXX,XXXXXXX,KC_COMM, KC_DOT,KC_BSPC,_______,_______,_______,_______,XXXXXXX,XXXXXXX,XXXXXXX,S(KC_1),RAG_T(KC_BSLS),RSFT_T(KC_DEL),
          _______,_______,_______, KC_ENT,_______,                                _______,KC_BSPC,LT(2,KC_ENT),_______,_______,
                  _______,_______,_______,                                                _______,_______,_______
   ),
  [_RAISE] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,KC_LABK,KC_LBRC,KC_LCBR,KC_LPRN,KC_LABK,                                S(KC_1),S(KC_2),S(KC_3),S(KC_4),S(KC_5),A(KC_BSPC),
  _______,KC_RABK,KC_RBRC,KC_RCBR,KC_RPRN,KC_RABK,_______,_______,_______,_______,S(KC_6),S(KC_7),S(KC_8),S(KC_9),S(KC_0),XXXXXXX,
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
          _______,_______,LT(1,KC_ENT),KC_ESC,_______,                            _______,_______,_______,_______,_______,
                  _______,_______,_______,                                                _______,_______,_______
  ),
  [_ADJUST] = LAYOUT(
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,_______,
  _______,_______,_______,_______, KC_SPC,_______,_______,_______,_______,_______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,_______,
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_BTN1,KC_BTN3,KC_BTN2,_______,_______,_______,
          _______,_______,_______,_______,_______,                                _______,_______,_______,_______,_______,
                  _______,_______,_______,                                                _______,_______,_______
  ),
};


// Layers and macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
//  switch (keycode) {
//   case QWERTY:
//      if (record->event.pressed) {
//        set_single_persistent_default_layer(_QWERTY);
//      }
//      return false;
//      break;
//    case LOWER:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case RAISE:
//      if (record->event.pressed) {
//        layer_on(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      } else {
//        layer_off(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
//      }
//      return false;
//      break;
//    case ADJUST:
//      if (record->event.pressed) {
//        layer_on(_ADJUST);
//      } else {
//        layer_off(_ADJUST);
//      }
//      return false;
//      break;
//  }
  return true;
}

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
