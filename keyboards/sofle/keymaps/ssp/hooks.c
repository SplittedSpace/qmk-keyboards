/**
 * 
 * keyboard_pre_init_* - Happens before most anything is started. Good for hardware setup that you want running very early.
 * matrix_init_* - Happens midway through the firmware’s startup process. Hardware is initialized, but features may not be yet.
 * keyboard_post_init_* - Happens at the end of the firmware’s startup process. This is where you’d want to put “customization” code, for the most part.
 * 
 * 
 * 
 * 
 * 
 * */

void keyboard_post_init_user(void)
{
	#ifdef RGBLIGHT_ENABLE
		// rgblight_layers = my_rgb_layers;// Enable the LED layers
		// rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT+8); //Set to static gradient 9
		// layer_move(0); //start on layer 0 to get the lighting activated
	#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

	#ifdef CONSOLE_ENABLE
		uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
	#endif 

  return true;
}