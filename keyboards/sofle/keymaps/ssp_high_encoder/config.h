#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }

#define NO_ACTION_ONESHOT //Save 244 bytes
#define NO_RESET //Save 40 bytes


#ifdef ENCODER_ENABLE
    #ifdef ENCODER_RESOLUTION
        #undef ENCODER_RESOLUTION
        #define ENCODER_RESOLUTION 4
    #endif
#endif