
#ifdef ENCODER_ENABLE
	bool encoder_update_user(uint8_t index, bool clockwise) {

		#ifdef CONSOLE_ENABLE
			uprintf("Encoder: index: %u, clockwise: %u \n", index, clockwise);
		#endif 

		// if (index == 0) {
		//     if (clockwise) {
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });  
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });
		// 	} else {
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });  
		// 	}
		// } else if (index == 1) {
		//     if (clockwise) {
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 6, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });  
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 6, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });
		// 	} else {
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 8, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });
		//     	action_exec((keyevent_t){.key = (keypos_t){.row = 8, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });  
		// 	}
		// }
		return true;
	}
#endif


#ifdef ENCODER_MAP_ENABLE
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),	ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }, // Home
		[1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),	ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }, // Lower
		[2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),	ENCODER_CCW_CW(KC_PGDN, KC_PGUP) }, // Raise
		[3] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT),	ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }, // Special
	};
#endif