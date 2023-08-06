#include "ssp.h"

void housekeeping_task_user() {
    
    #ifdef RGBLIGHT_ENABLE
        int val = rgblight_get_val();
        if (val > RGBLIGHT_LIMIT_VAL) {
            rgblight_decrease_val();
        }
    #endif
}