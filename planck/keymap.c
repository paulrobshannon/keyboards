#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _BL,
  _LOWER,
  _RAISE
};


#define _BL     0
#define _LOWER  1
#define _RAISE  2
#define _DEVSET 3
#define _MEDIA  4
#define _NAV    5
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV   MO(_NAV)
#define RAISE_ENT LT(_RAISE, KC_ENT)
#define NAV_LFT LT(_NAV, KC_LEFT)
#define SHFT_BS LSFT_T(KC_BSPC)
#define BACK LALT(KC_LEFT)
#define FORWRD LALT(KC_RGHT)
#define START LGUI(KC_LEFT)
#define END LGUI(KC_RGHT)

enum combo_events {
  COMBO_BSPC,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_HASH
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Base Layer Colemak :D (ex outer columns now TODO fix commented layer)
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Lower |BS & S|Space |Raise |  Nav |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BL] = LAYOUT_planck_grid( \
//,-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
       KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,         XXXXXXX,     XXXXXXX,       KC_J,         KC_L,         KC_U,         KC_Y,         KC_SCLN, \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
  LT(_NAV, KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),    KC_D,         XXXXXXX,     XXXXXXX,       KC_H,     RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I),     KC_O,    \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
   LSFT_T(KC_Z),     KC_X,         KC_C,         KC_V,         KC_B,         XXXXXXX,     XXXXXXX,       KC_K,         KC_M,         KC_COMM,      KC_DOT,       KC_SLSH, \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      XXXXXXX,      XXXXXXX,      XXXXXXX,       LOWER,       SHFT_BS,       XXXXXXX,     XXXXXXX,      KC_SPC,        RAISE,        XXXXXXX,      XXXXXXX,      XXXXXXX  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|

),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  1!  |  2@  |  3£  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |      |  0   |  .   |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid( \
//,-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         _______,      _______,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,     \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_4,         KC_5,         KC_6,        KC_QUOT,   \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_1,         KC_2,         KC_3,        KC_ENT,    \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      LOWER,        SHFT_BS,      _______,      _______,      KC_0,         _______,      _______,      _______,     _______    \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
    ),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   !  |   @  |   £  |   $  |   %  |   ^  |   &  |   *  |      |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   +  |  =+  |   (  |  [{  |  ]}  |   )  |   -  |   _  |      |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  `~  |      |      |      |      |      |      |      |   ,  |   .  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_planck_grid( \
//,-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      KC_EXLM,       KC_AT,       KC_HASH,      KC_DLR,       KC_PERC,      _______,      _______,      KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      KC_PLUS,      KC_EQL,       KC_LPRN,      KC_LBRC,      _______,      _______,      KC_RBRC,      KC_RPRN,      KC_MINS,      KC_UNDS,      KC_BSLS,  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      KC_GRV,       _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_COMM,      KC_DOT,       KC_QUES,  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      LOWER,        SHFT_BS,      _______,      _______,      KC_SPC,       _______,      _______,      _______,      _______   \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
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
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid( \
//,-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      FORWRD,       _______,      END,          _______,      _______,      _______,      _______,      _______,      _______,      _______,      START,    \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      _______,      _______,      _______,      _______,      _______,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      RESET,        _______,      _______,      _______,      BACK,         _______,      _______,      _______,      _______,      _______,      _______,      _______,  \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
      _______,      _______,      _______,      LOWER,        SHFT_BS,      _______,      _______,      KC_SPC,       _______,      _______,      _______,      _______   \
//|-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------+-------------|
  )

};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_tab[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_EXLM, KC_AT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc, KC_BSPC),
  [COMBO_TAB]  = COMBO(combo_tab,  KC_TAB),
  [COMBO_ESC]  = COMBO(combo_esc,  KC_ESC),
  [COMBO_HASH] = COMBO(combo_hash, LALT(KC_3))

};
#endif

