#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NAV 4
#define NAV MO(_NAV)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)
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

enum custom_keycodes {
  RGBRST = SAFE_RANGE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT( \
  //,-------------+-------------+-------------+-------------+-------------+-------------.                    ,-------------+-------------+-------------+-------------+-------------+-------------|
         XXXXXXX,      KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,                             KC_J,          KC_L,         KC_U,         KC_Y,         KC_SCLN,     XXXXXXX,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
         XXXXXXX, LT(_NAV, KC_A),LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T),     KC_D,                             KC_H,      RGUI_T(KC_N), RALT_T(KC_E), RCTL_T(KC_I),     KC_O,        XXXXXXX,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
         XXXXXXX,  LSFT_T(KC_Z),     KC_X,         KC_C,         KC_V,         KC_B,                             KC_K,          KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,     XXXXXXX,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
                                                                 XXXXXXX,      LOWER,    SHFT_BS,     KC_SPC,    RAISE,         XXXXXXX  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|

  ),

  [_LOWER] = LAYOUT( \
  //,-------------+-------------+-------------+-------------+-------------+-------------.                    ,-------------+-------------+-------------+-------------+-------------+-------------|
         _______,     KC_1,         KC_2,         KC_3,         KC_4,         KC_5,                              KC_6,         KC_7,         KC_8,         KC_9,         KC_0,        _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
         _______,     _______,      _______,      _______,      _______,      _______,                           _______,       KC_4,         KC_5,         KC_6,        KC_QUOT,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
         _______,     _______,      _______,      _______,      _______,      _______,                           _______,       KC_1,         KC_2,         KC_3,        KC_ENT,       _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
                                                                _______,      LOWER,     SHFT_BS,      KC_0,     _______,       _______  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
    ),

  [_RAISE] = LAYOUT( \
  //,-------------+-------------+-------------+-------------+-------------+-------------.                    ,-------------+-------------+-------------+-------------+-------------+-------------|
       _______,       KC_EXLM,       KC_AT,       KC_HASH,      KC_DLR,       KC_PERC,                           KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
       _______,       _______,      KC_PLUS,      KC_EQL,       KC_LPRN,      KC_LBRC,                           KC_RBRC,      KC_RPRN,      KC_MINS,      KC_UNDS,      KC_BSLS,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
       _______,       KC_GRV,       _______,      _______,      _______,      _______,                           _______,      _______,      KC_COMM,      KC_DOT,       KC_QUES,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
                                                                _______,      LOWER,     SHFT_BS,     KC_SPC,    _______,      _______   \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
  ),

  [_NAV] = LAYOUT( \
  //,-------------+-------------+-------------+-------------+-------------+-------------.                    ,-------------+-------------+-------------+-------------+-------------+-------------|
        _______,      _______,      FORWRD,       _______,      END,          _______,                           _______,      _______,      _______,      _______,      START,        _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
        _______,      _______,      _______,      _______,      _______,      _______,                           _______,      KC_LEFT,      KC_DOWN,      KC_UP,        KC_RGHT,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
        _______,      RESET,        _______,      _______,      _______,      BACK,                              _______,      _______,      _______,      _______,      _______,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
                                                                ADJUST,       LOWER,     SHFT_BS,     KC_SPC,    _______,      _______   \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
  ),

    [_ADJUST] = LAYOUT( \
  //,-------------+-------------+-------------+-------------+-------------+-------------.                    ,-------------+-------------+-------------+-------------+-------------+-------------|
        RESET,        RGBRST,       _______,      _______,     _______,      _______,                            _______,      _______,      _______,      _______,      _______,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
        RGB_TOG,      _______,      RGB_SAI,      RGB_VAI,     RGB_HUI,      _______,                            _______,      _______,      _______,      _______,      _______,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+                    +-------------+-------------+-------------+-------------+-------------+-------------|
        RGB_MOD,      _______,      RGB_SAD,      RGB_VAD,     RGB_HUD,      _______,                            _______,      _______,      _______,      _______,      _______,      _______,  \
  //|-------------+-------------+-------------+-------------+-------------+-------------+--------|  |--------+-------------+-------------+-------------+-------------+-------------+-------------|
                                                               KC_LGUI,      LOWER,      SHFT_BS,     KC_SPC,    RAISE,        _______   \
  //                                                        |-------------+-------------+--------|  |--------+-------------+-------------|
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

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     persistent_default_layer_set(1UL<<_BL);
    //   }
    //   return false;
    // case LOWER:
    //   if (record->event.pressed) {
    //     layer_on(_LOWER);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_LOWER);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    // case RAISE:
    //   if (record->event.pressed) {
    //     layer_on(_RAISE);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   } else {
    //     layer_off(_RAISE);
    //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
    //   }
    //   return false;
    // case ADJUST:
    //     if (record->event.pressed) {
    //       layer_on(_ADJUST);
    //     } else {
    //       layer_off(_ADJUST);
    //     }
    //     return false;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}
