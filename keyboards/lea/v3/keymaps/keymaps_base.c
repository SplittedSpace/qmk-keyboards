#include QMK_KEYBOARD_H

#include "hooks_base.c"

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
  {   25, 24, 16, 15, 6, 5 },
  {   26, 23, 17, 14, 7, 4 },
  {   27, 22, 18, 13, 8, 3 },
  {   28, 21, 19, 12, 9, 2 },
  {   20, 11, 10, 1, 0, NO_LED },

  {   68, 67, 59, 58, 49, 48 },
  {   69, 66, 60, 57, 50, 47 },
  {   70, 65, 61, 56, 51, 46 },
  {   71, 64, 62, 55, 52, 45 },
  {   63, 54, 53, 44, 43, NO_LED }
}, {
  // LED Index to Physical Position
  { 110, 63 }, { 100, 60 }, { 100, 45 }, { 100, 30 }, { 100, 15 }, { 100, 0 }, // col 5 -
  { 80, 0 },  { 80, 15 },  { 80, 30 },  { 80, 45 },  { 80, 60 }, // col 4 +
  { 60, 60 },  { 60, 45 },  { 60, 30 },  { 60, 15 },  { 60, 0 }, // col 3 -
  { 40, 0 },  { 40, 15 },  { 40, 30 },  { 40, 45 },  { 40, 60 }, // col 2 +
  { 20, 45 },  { 20, 30 },  { 20, 15 },  { 20, 0 }, // col 1 -
  { 0,  0 },  { 0,  15 },  { 0, 30 },   { 0, 45 },  // col 0 +
  
  { 100, 63 }, { 93, 61 }, { 50, 60 }, { 20, 60 },
  { 0, 45 },   { 0, 30 },  { 0, 15 },
  { 15, 0 },   { 50, 0 },  { 70, 0 },  { 95, 0 },
  { 110, 20 }, { 110, 40 },{ 110, 50 },


  { 110, 63 }, { 120, 60 }, { 120, 45 }, { 120, 30 }, { 120, 15 }, { 120, 0 }, // Col 0 -
  { 137, 0 },  { 137, 15 }, { 137, 30 }, { 137, 45 }, { 137, 60 }, // Col 1 +
  { 154, 60 }, { 154, 45 }, { 154, 30 }, { 154, 15 }, { 154, 0 }, // Col 2 -
  { 171, 0 },  { 171, 15 }, { 171, 30 }, { 171, 45 }, { 171, 60 }, // Col 3 +
  { 188, 45 }, { 188, 30 }, { 188, 15 }, { 188, 0 }, // Col 4 -
  { 223, 0 }, { 223,  15 }, { 223, 30 }, { 223, 45 }, // Col 5 +
  
  { 110, 63 }, { 120, 61 }, { 185, 60 }, { 220, 60 },
  { 223, 45 }, { 223, 30 }, { 223, 15 },
  { 205, 0 },{ 175, 0 },{ 150, 0 },{ 120, 0 },
  { 110, 20 },{ 110, 40 },{ 110, 50 }
}, {
  // LED Index to Flag
  4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,
  4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4,4, 4,4,4,4,4, 2,2,2,2,2,2,2,2,2,2,2,2,2,2
} };


void housekeeping_task_user() {
    hooks_housekeeping_task_user();
}