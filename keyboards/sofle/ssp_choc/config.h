
#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }

#define NO_ACTION_ONESHOT
#define NO_RESET

#define VENDOR_ID       0xFC32
#define PRODUCT_ID      0x0287
#define DEVICE_VER      0x0007
#define MANUFACTURER    SplittedSpace
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
    #define RGBLED_NUM 58
    #define RGBLED_SPLIT {29,29}
    #define RGBLIGHT_LIMIT_VAL 140
    #define RGBLIGHT_DEFAULT_VAL 120
    #define RGBLIGHT_VAL_STEP 5
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
    #define RGBLIGHT_DEFAULT_SPD 120
    #define RGBLIGHT_SPLIT
    #define RGBLIGHT_SLEEP

    #define LED_LAYOUT( \
        L00,	L01,	L02,	L03,	L04,	L05,					L08,	L09,	L010,	L011,	L012,	L013, \
        L10,	L11,	L12,	L13,	L14,	L15,					L18,	L19,	L110,	L111,	L112,	L113, \
        L20,	L21,	L22,	L23,	L24,	L25,					L28,	L29,	L210,	L211,	L212,	L213, \
        L30,	L31,	L32,	L33,	L34,	L35,					L38,	L39,	L310,	L311,	L312,	L313, \
                        L42,	L43,	L44,	L45,	L46,	L47,	L48,	L49,	L410,	L411				  \
        )\
        { \
            L05,L15,L25,L35,L46,L45,L44,L34,L24,L14,L04,L03,L13,L23,L33,L43,L42,L32,L22,L12,L02,L01,L11,L21,L31,L30,L20,L10,L00,\
            L08,L18,L28,L38,L47,L48,L49,L39,L29,L19,L09,L010,L110,L210,L310,L410,L411,L311,L211,L111,L011,L012,L112,L212,L312,L313,L213,L113,L013\
        }
    #define RGBLIGHT_LED_MAP LED_LAYOUT( \
        3,  4,  12, 13, 22, 23,          34, 35, 44, 45, 53, 54, \
        2,  5,  11, 14, 21, 24,          33, 36, 43, 46, 52, 55, \
        1,  6,  10, 15, 20, 25,          32, 37, 42, 47, 51, 56, \
        0,  7,  9,  16, 19, 26,          31, 38, 41, 48, 50, 57, \
                8,  17, 18, 27, 28,  29, 30, 39, 40, 49     \
    )
    
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL

    #ifndef OLED_ENABLE
        #ifndef TAP_DANCE_ENABLE
            #define RGBLIGHT_EFFECT_ALTERNATING
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