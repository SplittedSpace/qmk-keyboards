#include QMK_KEYBOARD_H
#include "maps.c"
#include "hooks.c"

#ifdef ENCODER_ENABLE
	#include "encoder.c"
#endif


#ifdef OLED_ENABLE
	#include "oled.c"

	void suspend_power_down_user(void) { //turn off OLEDs when computer is sleeping
		oled_off();
	}
#endif

#ifdef RGBLIGHT_ENABLE
	#include "led.c"
#endif

#ifdef RGB_MATRIX_ENABLE
	#include "led_matrix.c"
#endif


// bool is_alt_tab_active = false; // Super Alt Tab Code
// uint16_t alt_tab_timer = 0;
// bool lshift_held = false;	// LShift Backspace Delete whole Word Code
// bool rshift_held = false;	// RShift Backspace Delete whole Word Code


// #ifdef VIA_ENABLE
// 	enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
// 	  ATABF = USER00, //Alt tab forwards
// 	  ATABR, //Alt tab reverse
// 	  NMR, //Move window to monitor on right
// 	  NML, //Move window to monitor on left
// 	  SBS //Shift backspace to delete whole word (Swap KC_BPSC with this)
// 	};
// #else
// 	enum custom_keycodes { //Use USER 00 instead of SAFE_RANGE for Via. VIA json must include the custom keycode.
// 	  ATABF = SAFE_RANGE, //Alt tab forwards
// 	  ATABR, //Alt tab reverse
// 	  NMR, //Move window to monitor on right
// 	  NML, //Move window to monitor on left
// 	  SBS //Shift backspace to delete whole word (Swap KC_BPSC with this)
// 	};
// #endif



// void matrix_init_user(void) {
// }

// void matrix_scan_user(void) {
//   if (is_alt_tab_active) {
//     if (timer_elapsed(alt_tab_timer) > 1000) {
//       unregister_code(KC_LALT);
//       is_alt_tab_active = false;
//     }
//   }
// }


// static uint16_t held_shift = 0;
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
// 	#ifdef KEYBOARD_PET
// 		if (record->event.pressed) { //Drashna's OLED timeout off code for animations
// 			oled_timer = timer_read32();
// 		}
// 	#endif
	
// 	switch (keycode) { //For keycode overrides
// 		case ATABF:	//Alt tab forwards
// 		  if (record->event.pressed) {
// 			if (!is_alt_tab_active) {
// 			  is_alt_tab_active = true;
// 			  register_code(KC_LALT);
// 			}
// 			alt_tab_timer = timer_read();
// 			register_code(KC_TAB);
// 		  } else {
// 			unregister_code(KC_TAB);
// 		  }
// 		  return true;
// 		case ATABR:	//Alt tab reverse
// 		  if (record->event.pressed) {
// 			if (!is_alt_tab_active) {
// 			  is_alt_tab_active = true;
// 			  register_code(KC_LALT);
// 			}
// 			alt_tab_timer = timer_read();
// 			register_code(KC_LSHIFT);
// 			register_code(KC_TAB);
// 		  } else {
// 			unregister_code(KC_LSHIFT);
// 			unregister_code(KC_TAB);
// 		  }
// 		  return true;
		  
// 		case NMR:	//Move window to next monitor on right
// 		  if (record->event.pressed) {
// 			register_code(KC_LSFT);
// 			register_code(KC_LWIN);
// 			register_code(KC_RIGHT);
// 			unregister_code(KC_RIGHT);
// 			unregister_code(KC_LWIN);
// 			unregister_code(KC_LSFT);
// 		  }
// 		  return true;
// 		case NML:	//Move window to next monitor on left
// 		  if (record->event.pressed) {
// 			register_code(KC_LSFT);
// 			register_code(KC_LWIN);
// 			register_code(KC_LEFT);
// 			unregister_code(KC_LEFT);
// 			unregister_code(KC_LWIN);
// 			unregister_code(KC_LSFT);
// 		  }
// 		  return true;

// 		case KC_RSFT:	//Shift Backspace to Delete Whole Word. Inspired by Hellsingcoder.
// 			rshift_held = record->event.pressed;
// 			held_shift = keycode;
// 			// KEYBOARD PET STATUS
// 			#ifdef KEYBOARD_PET
// 				if (record->event.pressed) {
// 					isBarking = true;
// 				} else {
// 					isBarking = false;
// 				}
// 			#endif
// 			return true;
// 		case KC_LSFT:
// 			lshift_held = record->event.pressed;
// 			held_shift = keycode;
// 			// KEYBOARD PET STATUS
// 			#ifdef KEYBOARD_PET
// 				if (record->event.pressed) {
// 					isBarking = true;
// 				} else {
// 					isBarking = false;
// 				}
// 			#endif
// 			return true;
// 		case SBS:
// 			if (record->event.pressed) {
// 				if (lshift_held) {
// 					unregister_code(held_shift);
// 					register_code(KC_LCTL);
// 					register_code(KC_BSPC);
// 				} else if (rshift_held) {
// 					unregister_code(held_shift);
// 					register_code(KC_LCTL);
// 					register_code(KC_DEL);
// 				} else {
// 					register_code(KC_BSPC);
// 				}
// 			} else {
// 				unregister_code(KC_BSPC);
// 				unregister_code(KC_DEL);
// 				unregister_code(KC_LCTL);
// 				if (lshift_held || rshift_held) {
// 					register_code(held_shift);
// 				}
// 			}
// 			return false;
			
// 		// KEYBOARD PET STATUS
// 		#ifdef KEYBOARD_PET
// 			case KC_LCTL:
// 			case KC_RCTL:
// 				if (record->event.pressed) {
// 					isSneaking = true;
// 				} else {
// 					isSneaking = false;
// 				}
// 				return true;
// 			case KC_SPC:
// 				if (record->event.pressed) {
// 					isJumping = true;
// 					showedJump = false;
// 				} else {
// 					isJumping = false;
// 				}
// 				return true;
// 		#endif
// 		}
// 	return true;
// }
