
// extern rgblight_config_t rgblight_config; // To pull layer status for RGBLIGHT

// // RGB Layer Light Settings - Note that this will fix the key switch LED colour and brightness
// const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 95,255,90}); //Spring green		(Change range for multiple keys with same colour)
// const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 252,255,125}); //Red-orange		(Change range for multiple keys with same colour)
// const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 128,255,100}); //Cyan			(Change range for multiple keys with same colour)
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 0, 215,255,120}); //Magenta		(Change range for multiple keys with same colour)
// const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS({4, 3, 43,100,170}); //White-left caps lock indication (No dedicated LED)
// const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS({28, 3, 43,100,170}); //White-right num lock indication (No dedicated LED). Since this indicator is inverted, it must be on the master side of the keyboard to shut off properly when the computer is sleeping.
// const rgblight_segment_t PROGMEM my_scrollock_layer[] = RGBLIGHT_LAYER_SEGMENTS({55, 3, 43,100,170}); //White-middle-right scroll lock indication (No dedicated LED)
// const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( //Lighting layers
//     my_layer0_layer,
//     my_layer1_layer,
//     my_layer2_layer,
//     my_layer3_layer,
//     my_capslock_layer,    //Highest status indicators override other layers
//     my_numlock_layer,
//     my_scrollock_layer
// );

// layer_state_t layer_state_set_user(layer_state_t state)
// {
//     rgblight_set_layer_state(0, layer_state_cmp(state, 0));    // Multiple layers will light up if both kb layers are active
//     rgblight_set_layer_state(1, layer_state_cmp(state, 1));
//     rgblight_set_layer_state(2, layer_state_cmp(state, 2));
//     rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    
//     switch(biton32(state)){ // Change all other LEDs based on layer state as well
//         case 0:
//             rgblight_sethsv_noeeprom(50,255,80);
//             break;
//         case 1:
//             rgblight_sethsv_noeeprom(252,255,80);
//             break;
//         case 2:
//             rgblight_sethsv_noeeprom(118,255,80);
//             break;
//         case 3:
//             rgblight_sethsv_noeeprom(218,255,80);
//         }
//     return state;
// }


// bool led_update_user(led_t led_state)
// {
//     rgblight_set_layer_state(4, led_state.caps_lock); //Activate capslock lighting layer
//     rgblight_set_layer_state(5, !(led_state.num_lock)); //Invert the indication so numlock does not always appear "on".
//     rgblight_set_layer_state(6, led_state.scroll_lock); //Activate scrollock lighting layer
//     return true;
// }
