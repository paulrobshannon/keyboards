/* Copyright 2020 Nathan Spears
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


enum planck_layers {
  _BL,
  _RSTHD,
  _LOWER,
  _RAISE,
  _DEVSET,
  _MEDIA
};

enum custom_keycodes {
  APW
};


#define _BL     0
#define _LOWER  1
#define _RAISE  2
#define _DEVSET 3
#define _MEDIA  4
#define _NAV    5
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAV)
#define MEDIA MO(_MEDIA)
#define NAV_LFT LT(_NAV, KC_LEFT)
#define SHFT_BS LSFT_T(KC_BSPC)
#define SPC_LYR LT(_RAISE, KC_SPC)
#define BACK LALT(KC_LEFT)
#define FORWRD LALT(KC_RGHT)
#define START LGUI(KC_LEFT)
#define END LGUI(KC_RGHT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer Colemak :D
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |Shift |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |        |  CMD  |  Lwr  | Backspace & Layer | Space & Raise |  NAV  |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_BL] = LAYOUT_ortho_4x12_2x225u(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
        KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
        _______, KC_LGUI, LOWER,            SHFT_BS,          SPC_LYR,                   NAV,     _______, _______
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |  1!  |  2@  |  3£  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |        |       |       |                   |       0       |       |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_ortho_4x12_2x225u(
        MEDIA,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,  KC_9,    KC_0,    KC_BSPC, 
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5, KC_P6,   _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2, KC_P3,   _______, _______, 
        _______, _______, _______,          _______,          KC_P0,                   _______, _______, _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   #  |   !  |   @  |   £  |   $  |   %  |   ^  |   &  |   *  |      |   ;  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |   +  |  =+  |   (  |  [{  |  ]}  |   )  |   -  |   _  |      |  \|  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |  `~  |      |      |      |      |      |      |      |   ,  |   .  |   ?  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |        |       |       |                   |               |       |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_ortho_4x12_2x225u(
        LALT(KC_3), KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, KC_SCLN, KC_BSPC,
        _______,    _______, KC_PLUS, KC_EQL,  KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, KC_MINS, KC_UNDS, _______, KC_BSLS,
        KC_GRV,     _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT,  KC_QUES, _______,
        _______,    _______, _______,          _______,          _______,                   _______, _______, _______
    ),

    /* Dev & Settings (Lower + Raise)
     * 
     * ,-----------------------------------------------------------------------------------.
     * |      |Reset |Debug |      | APW  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |Mus on|Musoff|      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |        |       |       |                   |               |       |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_DEVSET] = LAYOUT_ortho_4x12_2x225u(
        _______, RESET,   DEBUG,   _______, APW,     _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,  MU_ON,  MU_OFF,  _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,          _______,                   _______, _______, _______
    ),


    /* Nav Layer
     * 
     * ,-----------------------------------------------------------------------------------.
     * |      |      |Forwrd|      | End  |      | Down |Right |      |      |Start |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | CTRL | LALT |  CMD |      |      | Left |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      | Back |  Up  |      | Left | Down |  Up  |Right |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |        |       |       |                   |               |       |      |       |
     * `-----------------------------------------------------------------------------------'
     */
    [_NAV] = LAYOUT_ortho_4x12_2x225u(
        _______, _______, FORWRD,  _______, END,     _______, KC_DOWN, KC_RGHT, _______, _______, START,   _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, BACK,    KC_UP,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        _______, _______, _______,          _______,          _______,                   _______, _______, _______
    )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _DEVSET);
  // more layer combos can go here as state = update_tri_...
  return state;
}

