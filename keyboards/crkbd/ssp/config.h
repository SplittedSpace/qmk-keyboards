#pragma once

#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}

#ifdef OLED_ENABLE
        #define OLED_FONT_H "keyboards/_lib/glcdfont.c"
	#define OLED_TIMEOUT 80000
	#define OLED_BRIGHTNESS 90
	#define SPLIT_WPM_ENABLE
	#define SPLIT_OLED_ENABLE
#endif

#ifdef RGBLIGHT_ENABLE
        #define RGBLIGHT_EFFECT_BREATHING
        #define RGBLIGHT_EFFECT_RAINBOW_MOOD
        #define RGBLIGHT_EFFECT_RAINBOW_SWIRL

        #ifndef OLED_ENABLE
                #define RGBLIGHT_EFFECT_SNAKE
                #define RGBLIGHT_EFFECT_ALTERNATING
                
                #ifndef TAP_DANCE_ENABLE
                        #define RGBLIGHT_EFFECT_CHRISTMAS
                        #define RGBLIGHT_EFFECT_KNIGHT
                        #define RGBLIGHT_EFFECT_TWINKLE
                        #define RGBLIGHT_EFFECT_RGB_TEST
                        #define RGBLIGHT_EFFECT_STATIC_GRADIENT
                #endif
        #endif
#endif

