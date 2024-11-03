#pragma once

#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PIN A9
#define SERIAL_USART_TX_PAL_MODE 1
// #define SELECT_SOFT_SERIAL_SPEED 0
// #define FORCED_SYNC_THROTTLE_MS 50

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xC3 }

#define NO_ACTION_ONESHOT
#define NO_RESET

#define DEBOUNCE 5

#define TAP_CODE_DELAY 10
#define TAPPING_TOGGLE 2
#define TAPPING_TERM 160

#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 1

#define I2C1_TIMINGR_PRESC 2U
#define I2C1_TIMINGR_SCLDEL 1U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 9U
#define I2C1_TIMINGR_SCLL 26U

// #define WS2812_PWM_DRIVER PWMD1
// #define WS2812_PWM_CHANNEL 1
// #define WS2812_PWM_PAL_MODE 4
// #define WS2812_DMA_STREAM STM32_DMA1_STREAM3
// #define WS2812_DMA_CHANNEL 14

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#undef SPLIT_TRANSPORT_MIRROR

#ifdef COMBO_ENABLE
    #define VIAL_COMBO_ENTRIES 10
	#define COMBO_TERM 400
#endif

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_ADDRESS 0x3C
    #define OLED_TIMEOUT 180000

    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
#endif

#ifdef QUANTUM_PAINTER_ENABLE
    #define SPI_DRIVER SPID1
    #define SPI_SCK_PIN A5
    #define SPI_SCK_PAL_MODE 0
    #define SPI_MOSI_PIN A7
    #define SPI_MOSI_PAL_MODE 0
    #define SPI_MISO_PIN A6
    #define SPI_MISO_PAL_MODE 0 

    #define LCD_RST_PIN     A1
    #define LCD_CS_PIN      A2
    #define LCD_DC_PIN      A0
    #define LCD_WIDTH       80
    #define LCD_HEIGHT      160
#endif

#ifdef RGB_MATRIX_ENABLE

    #define WS2812_TRST_US 80
    #define WS2812_T0H 300
    #define WS2812_T1H 950

    #define RGBLED_NUM 70
    #define DRIVER_LED_TOTAL RGBLED_NUM
    #define RGB_MATRIX_LED_COUNT RGBLED_NUM
    
    #define ENABLE_RGB_MATRIX_ALPHAS_MODS
    #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_BAND_SAT
    #define ENABLE_RGB_MATRIX_BAND_VAL
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #define ENABLE_RGB_MATRIX_CYCLE_ALL
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL	
    #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #define ENABLE_RGB_MATRIX_DUAL_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #define ENABLE_RGB_MATRIX_RAINDROPS	
    #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS	
    #define ENABLE_RGB_MATRIX_HUE_BREATHING	
    #define ENABLE_RGB_MATRIX_HUE_PENDULUM
    #define ENABLE_RGB_MATRIX_HUE_WAVE
    #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL	
    #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    #define ENABLE_RGB_MATRIX_PIXEL_RAIN
    #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

    // KEYPRESSES EFFECTS
    #define RGB_MATRIX_KEYPRESSES
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #define ENABLE_RGB_MATRIX_MULTISPLASH
    #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

    #define RGB_TRIGGER_ON_KEYDOWN
#endif