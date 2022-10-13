/* Copyright 2020 gtips
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
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FUNC,
    _NUM,
    _ADJUST
};

#define FUNC  LT(_FUNC,KC_BSPC)
#define NUM  MO(_NUM)
#define ADJUST MO(_ADJUST)

///////left-hand-side//////
#define L_GUI LGUI_T(KC_A)
#define L_SHFT LSFT_T(KC_F)
#define L_ALT LALT_T(KC_S)
#define L_CTRL LCTL_T(KC_D)


///////right-hand-side//////
#define R_GUI RGUI_T(KC_SCLN)
#define R_ALT LALT_T(KC_L)
#define R_SHFT RSFT_T(KC_J)
#define R_CTRL RCTL_T(KC_K)

//////////////////////////
/////////keymaps//////////
//////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_reviung41(
    QK_GESC,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,   KC_BSPC,
    XXXXXXX,  L_GUI,   L_ALT,   L_CTRL,    L_SHFT,    KC_G,                KC_H,   R_SHFT,   R_CTRL,    R_ALT,    R_GUI,   KC_QUOT,
    KC_TAB ,   KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,                KC_N,     KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  XXXXXXX,
                                            XXXXXXX,  NUM,      KC_SPC,    FUNC,   KC_ENT
  ),
  
  [_FUNC] = LAYOUT_reviung41(
    _______,  KC_F1,  KC_F2,    KC_F3,  KC_F4,    KC_F5,              	  KC_PGUP,  KC_PSCR,  KC_UP,   KC_LPRN,  KC_RPRN,   KC_DEL,
    _______,  KC_F6,  KC_F7,    KC_F8,  KC_F9,   KC_F10,               	  KC_PGDN,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_GRV,   KC_TILD,
    _______,  KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15,                  KC_HOME,   KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, RSFT_T(KC_SPC),
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
  [_NUM] = LAYOUT_reviung41(
    _______,  KC_1,  KC_2,   KC_3, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX,   XXXXXXX,  KC_DEL,
    _______,  KC_4,  KC_5,   KC_6, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL,    KC_LBRC, KC_RBRC,   KC_BSLS,  KC_GRV,
    _______,  KC_7,  KC_8,   KC_9,    KC_0, XXXXXXX,                      KC_UNDS, KC_PLUS,    KC_LCBR, KC_RCBR,   KC_PIPE, KC_TILD,
                                            _______,   _______,  KC_BSPC,  _______,  _______
  ),
  
  [_ADJUST] = LAYOUT_reviung41(
    RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            QK_BOOT,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FUNC, _NUM, _ADJUST);
}

