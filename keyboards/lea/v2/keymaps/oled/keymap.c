// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "hooks.c"

#ifdef OLED_ENABLE
	#include "oled.c"
#endif

#ifdef QUANTUM_PAINTER_ENABLE
  #include "lcd.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_5x6(
      KC_ESC,   	  KC_1,   KC_2,     KC_3,    	KC_4,    KC_5,                        KC_6,    	KC_7,   	KC_8,    KC_9,    KC_0,  KC_GRV,
      KC_TAB,   	  KC_Q,   KC_W,     KC_E,    	KC_R,    KC_T,                        KC_Y,    	KC_U,    	KC_I,    KC_O,    KC_P,  KC_BSPC,
      KC_CAPS_LOCK, KC_A,   KC_S,     KC_D,    	KC_F,    KC_G,                        KC_H,    	KC_J,    	KC_K,    KC_L, KC_SCLN,  KC_QUOT,
      KC_LSFT,    	KC_Z,   KC_X,     KC_C,    	KC_V,    KC_B, KC_MUTE,   KC_DELETE,  KC_N,    	KC_M, 	 KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                      KC_LCTL, KC_LGUI, KC_LALT,   MO(1), KC_SPC,        KC_ENT,  MO(2), 	   MO(3), KC_HOME,  KC_END
    ),
    [1] = LAYOUT_split_5x6(
      _______,	KC_F1,   	KC_F2,   	KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
      KC_GRV, 	KC_1,    	KC_2,    	KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
      KC_TAB, 	KC_EXLM,  KC_AT, 		KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
      KC_LSFT,  KC_EQL, 	KC_MINS, 	KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                            KC_LCTL, KC_LGUI, KC_LALT,   MO(1), KC_SPC,        KC_ENT,  MO(2), 	   MO(3), KC_HOME,  KC_END
    ),
    [2] = LAYOUT_split_5x6(
      _______, _______ ,  _______ ,  _______ , _______ , _______,                          _______,  _______, _______,  _______ ,  _______ ,_______,
      KC_ESC,  KC_INS,   KC_PSCR,    KC_APP,  _______, _______,                           KC_PGUP,  KC_AMPR,   KC_UP,   KC_LPRN,   KC_RPRN, KC_BSPC,
      KC_TAB,  KC_LALT,  KC_LCTL,    KC_LSFT,  _______, KC_CAPS,                          KC_PGDN,  KC_LEFT, KC_DOWN,   KC_RGHT,    KC_DEL, KC_BSPC,
      KC_LSFT, KC_UNDO,  KC_CUT,     KC_COPY, KC_PASTE, _______, _______,       _______,  _______,  KC_HOME, _______,   KC_END,   _______, _______,
                          KC_LCTL, KC_LGUI, KC_LALT,   MO(1), KC_SPC,           KC_ENT,    MO(2), 	MO(3), KC_HOME,  KC_END
    ),
    [3] = LAYOUT_split_5x6(
      _______, _______ ,  _______ ,  _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  RGB_HUD ,RGB_HUI,
      _______, _______ ,  _______ ,  _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  RGB_RMOD ,RGB_MOD,
      _______, _______ ,  _______ ,  _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  RGB_VAD ,RGB_VAI,
      _______, _______ ,  _______ ,  _______ , _______ , _______, KC_MPLY,    RGB_TOG,      _______,  _______  , _______,  _______ ,  RGB_SPD ,RGB_SPI,
                    KC_LCTL, KC_LGUI, KC_LALT,   MO(1), KC_SPC,  KC_ENT,  MO(2), 	  MO(3), KC_HOME,  KC_END
    ),
};

#ifdef ENCODER_MAP_ENABLE
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [2] = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(KC_MS_D, KC_MS_U) },
    [3] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
	};
#endif

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   31, 30, 22, 21, 12, 11 },
  {   32, 29, 23, 20, 13, 10 },
  {   33, 28, 24, 19, 14, 9 },
  {   34, 27, 25, 18, 15, 8 },
  {   26, 17, 16, 7, 6, NO_LED },

  {   66, 65, 57, 56, 47, 46 },
  {   67, 64, 58, 55, 48, 45 },
  {   68, 63, 59, 54, 49, 44 },
  {   69, 62, 60, 53, 50, 43 },
  {   61, 52, 51, 42, 41, NO_LED }

}, {
  // LED Index to Physical Position
  { 104, 10 },{ 46, 9 },{ 7, 14 },{ 7, 40 },{ 45, 48 },{ 95, 46 },
  { 107, 0 },
  { 92, 4 },  { 92, 14 }, { 92, 28 }, { 92, 45 }, { 92, 62 },
  { 77, 64 }, { 77, 45 }, { 77, 29 }, { 77, 15 }, { 77, 6 },
  { 51, 7 },  { 51, 15 }, { 51, 32 }, { 51, 47 }, { 51, 64 },
  { 35,  64 }, { 35,  45 }, { 35,  29 }, { 35,  14 }, { 35,  6 },
  { 18, 15 }, { 18, 29 }, { 18, 45 }, { 18, 61 },
  { 0, 56 }, { 0, 38 }, { 0, 27 }, { 0, 14 },

  { 120, 10 },{ 178, 9 },{ 217, 14 },{ 217, 40 },{ 179, 48 },{ 129, 46 },
  { 117, 0 },
  { 132, 4 },  { 132, 14 }, { 132, 28 }, { 132, 45 }, { 132, 62 },
  { 147, 64 }, { 147, 45 }, { 147, 29 }, { 147, 15 }, { 147, 6 },
  { 173, 7 },  { 173, 15 }, { 173, 32 }, { 173, 47 }, { 173, 64 },
  { 189,  64 }, { 189,  45 }, { 189,  29 }, { 189,  14 }, { 189,  6 },
  { 206, 15 }, { 206, 29 }, { 206, 45 }, { 206, 61 },
  { 224, 56 }, { 224, 38 }, { 224, 27 }, { 224, 14 }
}, {
  // LED Index to Flag
  2,2,2,2,2,2, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,
  2,2,2,2,2,2, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4
} };
