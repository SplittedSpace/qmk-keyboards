
#pragma once

#define VENDOR_ID       0xFC32
#define PRODUCT_ID      0x0287
#define DEVICE_VER      0x0007
#define MANUFACTURER    SplittedSpace
#define PRODUCT         Sofle

//#define EE_HANDS //Use this instead for EEPROM setting
#define MASTER_LEFT

#define MATRIX_ROWS 10
#define MATRIX_COLS 6

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#ifdef ENCODER_ENABLE
    #define ENCODERS_PAD_A { F4 }
    #define ENCODERS_PAD_B { F5 }
    #define ENCODERS_PAD_A_RIGHT { F5 }
    #define ENCODERS_PAD_B_RIGHT { F4 }
    #define ENCODER_RESOLUTION 4
#endif

#define TAP_CODE_DELAY 10
#define TAPPING_TOGGLE 2 //Tap TT twice to toggle layer
#define TAPPING_TERM 160 //Tapping duration in ms

// Communication between sides
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2


#ifdef OLED_ENABLE
	#define OLED_TIMEOUT 80000 //120000 = 2 minutes in ms.
	#define OLED_BRIGHTNESS 90 // Default 100.
	#define SPLIT_WPM_ENABLE //Enable WPM across split keyboards (+268).
	#define SPLIT_OLED_ENABLE //Synx on/off OLED state between halves (+100).
#endif

#ifdef COMBO_ENABLE
	#define COMBO_COUNT 1 //Number of tap combos used
	#define COMBO_TERM 400 //Default combo time is 200ms. This is the time delay allowed between deleting each whole word with shift-backspace.
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #define RGBLED_NUM 72
    #define RGBLED_SPLIT {36,36}
    //#define RGBLIGHT_ANIMATIONS // Very memory intensive
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT //Firmware size (+262)
    #define RGBLIGHT_LIMIT_VAL 150 //Power draw may exceed 0.6A at max brightness with white colour.
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
    #define RGBLIGHT_SLEEP

    //RGB LED Conversion macro from physical array to electric array (+146 to firmware size)
    //First section is the LED matrix, second section is the electrical wiring order, and the third section is the desired mapping
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
            L14,L12,L10,L40,L42,L44,L71,L76,L66,L65,L55,L35,L25,L05,L04,L24,L34,L54,L64,L63,L53,L33,L23,L03,L02,L22,L32,L52,L62,L51,L31,L21,L01,L00,L20,L30,L50,L19,L111,L113,L413,L411,L49,L712,L77,L67,L68,L58,L38,L28,L08,L09,L29,L39,L59,L69,L610,L510,L310,L210,L010,L011,L211,L311,L511,L611,L512,L312,L212,L012,L013,L213,L313,L513, \
        }
    //RGB LED logical order map
    #define RGBLIGHT_LED_MAP LED_LAYOUT( \
        5,	6,	17,	18,	29,	30,			43,	44,	55,	56,	67,	68, \
        4,		16,		28,					45,		57,		69, \
        3,	7,	15,	19,	27,	31,			42,	46,	54,	58,	66,	70, \
        2,	8,	14,	20,	26,	32,			41,	47,	53,	59,	65,	71, \
        1,		13,		25,					48,		60,		72, \
        0,	9,	12,	21,	24,	33,			40,	49,	52,	61,	64,	73, \
                11,	22,	23,	34,	35,	38,	39,	50,	51,	62,		    \
                10,				36,	37,				63		    )
#endif

#ifdef RGB_MATRIX_ENABLE
    #define VIALRGB_NO_DIRECT
    #define RGBLED_NUM 72
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 220
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
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON    
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    // #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    // #define ENABLE_RGB_MATRIX_CYCLE_ALL	Enables
    // #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    // #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    // #define ENABLE_RGB_MATRIX_RAINDROPS
    // #define ENABLE_RGB_MATRIX_HUE_WAVE
    // #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    // #define ENABLE_RGB_MATRIX_PIXEL_RAIN



    // #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    // #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    // #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    // #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    // #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    // #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    // #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    // #define ENABLE_RGB_MATRIX_BAND_SAT
    // #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    // #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    // #define ENABLE_RGB_MATRIX_DUAL_BEACON
    // #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    // #define ENABLE_RGB_MATRIX_HUE_BREATHING
    // #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    // #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL

#endif