#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x4(
        KC_1,   KC_2,   KC_3,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_2,   KC_3,   KC_NO
    )
};


#ifdef ENCODER_MAP_ENABLE
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4) }
	};
#endif

led_config_t g_led_config = { {
  // Key Matrix to LED Index
  {   5, NO_LED, NO_LED,   0 },
  { NO_LED, NO_LED, NO_LED, NO_LED },
  {   4, NO_LED, NO_LED,   1 },
  {   3, NO_LED, NO_LED,   2 }
}, {
  // LED Index to Physical Position
  { 220,  10 }, { 220,  60 }, { 4,  60 }, { 4,  10 },
  { 0, 0 }, { 75, 0 }, { 150, 0 }, { 224, 0 },
  { 0, 21 }, { 75, 21 }, { 150, 21 }, { 224, 21 },
  { 0, 42 }, { 75, 42 }, { 150, 42 }, { 224, 42 },
  { 0, 64 }, { 75, 64 }, { 150, 64 }, { 224, 64 },
}, {
  // LED Index to Flag
  2, 2, 2, 2, 4,4,4,4, 4,4,4,4, 4,4,4,4, 4,4,4,4
} };