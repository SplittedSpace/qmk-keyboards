const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_5x4(
        KC_1,   KC_2,   KC_3,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_2,   KC_3,   KC_NO
    ),
    [1] = LAYOUT_ortho_5x4(
        KC_1,   KC_2,   KC_3,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_2,   KC_3,   KC_NO
    ),
    [2] = LAYOUT_ortho_5x4(
        KC_1,   KC_2,   KC_3,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_2,   KC_3,   KC_NO
    ),
    [3] = LAYOUT_ortho_5x4(
        KC_1,   KC_2,   KC_3,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_1,   KC_1,   KC_1,
        KC_1,   KC_2,   KC_3,   KC_NO
    )
};


#ifdef ENCODER_MAP_ENABLE
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4) },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4) },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_1, KC_2), ENCODER_CCW_CW(KC_3, KC_4) }
	};
#endif