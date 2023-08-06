# Vial-compatible QMK firmwares for SplittedSpace keyboards

## How to

```
# Prepare for building
make install

# Build keyboard
make kb=crkbd/rev1 km=vial build

```


### Possible keyboards

```
# Sofle
make kb=sofle/ssp km=ssp_high_encoder build && mv ./.build/sofle_ssp_ssp_high_encoder.hex ../qmk-firmware-releases/sofle/sofle_vial_high_encoder__deprecated.hex
make kb=sofle/ssp km=ssp build && mv ./.build/sofle_ssp_ssp.hex ../qmk-firmware-releases/sofle/sofle_vial.hex
make kb=sofle/ssp km=ssp_no_oled build && mv ./.build/sofle_ssp_ssp_no_oled.hex ../qmk-firmware-releases/sofle/sofle_vial_no_oled.hex
make kb=sofle/ssp km=ssp_full_rgb build && mv ./.build/sofle_ssp_ssp_full_rgb.hex ../qmk-firmware-releases/sofle/sofle_vial_full_rgb.hex

# Sofle Choc
make kb=sofle/ssp_choc km=ssp_full_rgb build && mv ./.build/sofle_ssp_choc_ssp_full_rgb.hex ../qmk-firmware-releases/sofle/sofle_choc_vial_full_rgb.hex
make kb=sofle/ssp_choc km=ssp_no_oled build && mv ./.build/sofle_ssp_choc_ssp_no_oled.hex ../qmk-firmware-releases/sofle/sofle_choc_vial.hex

# Corne
make kb=crkbd/ssp km=ssp_all_leds build && mv ./.build/crkbd_ssp_ssp_all_leds.hex ../qmk-firmware-releases/corne/corne_vial.hex
make kb=crkbd/ssp km=ssp_underglow build && mv ./.build/crkbd_ssp_ssp_underglow.hex ../qmk-firmware-releases/corne/corne_vial_underglow.hex

make kb=crkbd/ssp km=ssp_all_leds_no_oled build && mv ./.build/crkbd_ssp_ssp_all_leds_no_oled.hex ../qmk-firmware-releases/corne/corne_vial_no_oled.hex
make kb=crkbd/ssp km=ssp_underglow_no_oled build && mv ./.build/crkbd_ssp_ssp_underglow_no_oled.hex ../qmk-firmware-releases/corne/corne_vial_underglow_no_oled.hex


# Corne Choc
make kb=crkbd/ssp km=ssp_all_leds build && mv ./.build/crkbd_ssp_ssp_all_leds.hex ../qmk-firmware-releases/corne/corne_choc_vial.hex
make kb=crkbd/ssp km=ssp_all_leds_no_oled build && mv ./.build/crkbd_ssp_ssp_all_leds_no_oled.hex ../qmk-firmware-releases/corne/corne_choc_vial_no_oled.hex

# M1
make kb=m_one km=default build && mv ./.build/m_one_default.hex ../qmk-firmware-releases/m_one/m_one_vial.hex
```




#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, \
    L10, L11, L12, L13, \
    L20, L21, L22, L23, \
    L30, L31, L32, L33 \
    ) \
    { \
        { L00, L01, L02, L03 }, \
        { L10, L11, L12, L13 }, \
        { L20, L21, L22, L23 }, \
        { L30, L31, L32, L33 } \
    }

