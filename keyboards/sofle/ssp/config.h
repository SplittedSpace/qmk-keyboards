
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }

#define NO_ACTION_ONESHOT
#define NO_RESET

#define VENDOR_ID       0xFC32
#define PRODUCT_ID      0x0287
#define DEVICE_VER      0x0007
#define MANUFACTURER    splitted.space
#define PRODUCT         Sofle

#define MASTER_LEFT

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { F5 }
    #define ENCODERS_PAD_B { F4 }
    #define ENCODERS_PAD_A_RIGHT { F4 }
    #define ENCODERS_PAD_B_RIGHT { F5 }
    #define ENCODER_RESOLUTION 2
#endif

#define TAP_CODE_DELAY 10
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 160

#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2

#ifdef OLED_ENABLE
	#define OLED_TIMEOUT 80000
	#define OLED_BRIGHTNESS 90
	#define SPLIT_WPM_ENABLE
	#define SPLIT_OLED_ENABLE
#endif

#ifdef COMBO_ENABLE
    #define VIAL_COMBO_ENTRIES 10
	#define COMBO_TERM 400
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #define RGBLED_NUM 74
    #define RGBLED_SPLIT {36,36}
    #define RGBLIGHT_LIMIT_VAL 130
    #define RGBLIGHT_DEFAULT_VAL 120
    #define RGBLIGHT_VAL_STEP 5
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_DEFAULT_SPD 120
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP

    #define LED_LAYOUT( \
        L00,	L01,	L02,	L03,	L04,	L05,					L08,	L09,	L010,	L011,	L012,	L013, \
        L10,			L12,			L14,									L19,			L111,			L113, \
        L20,	L21,	L22,	L23,	L24,	L25,					L28,	L29,	L210,	L211,	L212,	L213, \
        L30,	L31,	L32,	L33,	L34,	L35,					L38,	L39,	L310,	L311,	L312,	L313, \
        L40,			L42,			L44,									L49,			L411,			L413, \
        L50,	L51,	L52,	L53,	L54,	L55,					L58,	L59,	L510,	L511,	L512,	L513, \
                        L62,	L63,	L64,	L65,	L66,	L67,	L68,	L69,	L610,	L611,				  \
                L71,									L76,	L77,									L712		 )\
        { \
            L71,L10,L12,L14,L44,L42,L40,\
            L62,L50,L30,L20,L00,L01,L21,L31,L51,L63,L64,L52,L32,L22,L02,L03,L23,L33,L53,L66,L76,L54,L34,L24,L04,L05,L25,L35,L55,\
            L712,L113,L111,L19,L49,L411,L413,\
            L611,L513,L313,L213,L013,L012,L212,L312,L512,L610,L69,L511,L311,L211,L011,L010,L210,L310,L510,L67,L77,L59,L39,L29,L09,L08,L28,L38,L58 \
        }
    #define RGBLIGHT_LED_MAP LED_LAYOUT( \
        3,  4,  14, 15, 26, 27,       46, 47, 57, 58, 68, 69, \
            5,      16,     28,       45,     56,     67,     \
        2,  6,  13, 17, 25, 29,       44, 48, 55, 59, 66, 70, \
        1,  7,  12, 18, 24, 30,       43, 49, 54, 60, 65, 71, \
            9,      20,     35,       38,     53,     63,     \
        0,  8,  11, 19, 23, 32,       41, 50, 52, 61, 64, 72, \
            10, 21, 22, 33, 34,       39, 40, 51, 51, 62,     \
            31,                36, 37,                42      )

    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL

    #ifndef OLED_ENABLE
        #ifndef TAP_DANCE_ENABLE
            #define RGBLIGHT_EFFECT_CHRISTMAS
            #define RGBLIGHT_EFFECT_KNIGHT
            #define RGBLIGHT_EFFECT_SNAKE
            #define RGBLIGHT_EFFECT_TWINKLE
            #define RGBLIGHT_EFFECT_RGB_TEST
            #define RGBLIGHT_EFFECT_STATIC_GRADIENT
        #endif
    #endif

#endif

#ifdef RGB_MATRIX_ENABLE
    #define VIALRGB_NO_DIRECT
    #define RGBLED_NUM 72
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
    #define RGB_MATRIX_HUE_STEP 8
    #define RGB_MATRIX_SAT_STEP 8
    #define RGB_MATRIX_VAL_STEP 8
    #define RGB_MATRIX_SPD_STEP 10 
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define RGB_MATRIX_SPLIT {36,36}
    #define SPLIT_TRANSPORT_MIRROR
    
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_VAL
#endif