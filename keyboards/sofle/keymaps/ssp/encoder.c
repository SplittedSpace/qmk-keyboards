
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {

	#ifdef CONSOLE_ENABLE
		uprintf("Encoder: index: %u, clockwise: %u \n", index, clockwise);
	#endif 

    if (index == 0) {
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 1, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });
		} else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });
        	action_exec((keyevent_t){.key = (keypos_t){.row = 3, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });  
		}
    } else if (index == 1) {
        if (clockwise) {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 6, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });  
        	action_exec((keyevent_t){.key = (keypos_t){.row = 6, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });
		} else {
        	action_exec((keyevent_t){.key = (keypos_t){.row = 8, .col = 6}, .pressed = true, .time = (timer_read() | 1)  });
        	action_exec((keyevent_t){.key = (keypos_t){.row = 8, .col = 6}, .pressed = false, .time = (timer_read() | 1)  });  
		}
    }
	return true;
}
#endif
