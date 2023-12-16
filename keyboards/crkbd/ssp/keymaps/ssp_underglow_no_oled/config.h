#pragma once

#ifdef RGBLIGHT_ENABLE

    #undef RGBLED_NUM
    #define RGBLED_NUM 12

    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_SNAKE

    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT { 6, 6 }

    #undef RGBLIGHT_LIMIT_VAL
    #define RGBLIGHT_LIMIT_VAL 255
#endif

#define RGBW