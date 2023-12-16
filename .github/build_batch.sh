#!/bin/bash

DIST_FOLDER="./.build"
BUILD_FOLDER="$(eval echo ~$USER)/qmk_firmware/.build"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
DATE_S=$(date +%F)

compress () {
    n=($2)
    zip -j ./.build/$1_$(date +%F).zip "${n[@]/#/$DIST_FOLDER/}"
    rm "${n[@]/#/$DIST_FOLDER/}"
}


rm -rf .build && mkdir .build

# Lea
qmk compile -kb lea/v1 -km base                 && cp $BUILD_FOLDER/lea_v1_base.bin $DIST_FOLDER/LA1-01__$(date +%F).bin
qmk compile -kb lea/v1 -km oled                 && cp $BUILD_FOLDER/lea_v1_oled.bin $DIST_FOLDER/LA1-02__$(date +%F).bin
qmk compile -kb lea/v1 -km lcd                  && cp $BUILD_FOLDER/lea_v1_lcd.bin $DIST_FOLDER/LA1-03__$(date +%F).bin

# M1 + 
qmk compile -kb m_one/v1 -km base               && cp $BUILD_FOLDER/m_one_v1_base.bin $DIST_FOLDER/MM1-01__$(date +%F).bin
qmk compile -kb m_one/v1 -km midi               && cp $BUILD_FOLDER/m_one_v1_midi.bin $DIST_FOLDER/MM1-01_midi__$(date +%F).bin
qmk compile -kb m_one/v2 -km base               && cp $BUILD_FOLDER/m_one_v2_base.bin $DIST_FOLDER/MM2-01__$(date +%F).bin
qmk compile -kb m_one/v2 -km midi               && cp $BUILD_FOLDER/m_one_v2_midi.bin $DIST_FOLDER/MM2-01_midi__$(date +%F).bin

# Corne
qmk compile -kb crkbd/ssp -km ssp_all_leds          && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds.hex              $DIST_FOLDER/corne_vial.hex
qmk compile -kb crkbd/ssp -km ssp_underglow         && mv $BUILD_FOLDER/crkbd_ssp_ssp_underglow.hex             $DIST_FOLDER/corne_vial_underglow.hex
qmk compile -kb crkbd/ssp -km ssp_all_leds_no_oled  && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds_no_oled.hex      $DIST_FOLDER/corne_vial_no_oled.hex
qmk compile -kb crkbd/ssp -km ssp_underglow_no_oled && mv $BUILD_FOLDER/crkbd_ssp_ssp_underglow_no_oled.hex     $DIST_FOLDER/corne_vial_underglow_no_oled.hex

# Corne Choc
qmk compile -kb crkbd/ssp -km ssp_all_leds          && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds.hex              $DIST_FOLDER/corne_choc_vial.hex
qmk compile -kb crkbd/ssp -km ssp_all_leds_no_oled  && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds_no_oled.hex      $DIST_FOLDER/corne_choc_vial_no_oled.hex

cp $SCRIPT_DIR/corne_versions.md $DIST_FOLDER/versions.md
compress "corne" "versions.md corne_vial.hex corne_vial_underglow.hex corne_vial_no_oled.hex corne_vial_underglow_no_oled.hex corne_choc_vial.hex corne_choc_vial_no_oled.hex"

# Sofle
# qmk compile -kb sofle/ssp -km ssp_high_encoder          && mv $BUILD_FOLDER/sofle_ssp_ssp_high_encoder.hex      $DIST_FOLDER/sofle_vial_high_encoder__deprecated.hex
# qmk compile -kb sofle/ssp -km ssp                       && mv $BUILD_FOLDER/sofle_ssp_ssp.hex                   $DIST_FOLDER/sofle_vial.hex
# qmk compile -kb sofle/ssp -km ssp_no_oled               && mv $BUILD_FOLDER/sofle_ssp_ssp_no_oled.hex           $DIST_FOLDER/sofle_vial_no_oled.hex
# qmk compile -kb sofle/ssp -km ssp_full_rgb              && mv $BUILD_FOLDER/sofle_ssp_ssp_full_rgb.hex          $DIST_FOLDER/sofle_vial_full_rgb.hex

# # Sofle Choc 
# qmk compile -kb sofle/ssp_choc -km ssp_full_rgb        && mv $BUILD_FOLDER/sofle_ssp_choc_ssp_full_rgb.hex      $DIST_FOLDER/sofle_choc_vial_full_rgb.hex
# qmk compile -kb sofle/ssp_choc -km ssp_no_oled         && mv $BUILD_FOLDER/sofle_ssp_choc_ssp_no_oled.hex       $DIST_FOLDER/sofle_choc_vial.hex

# cp $SCRIPT_DIR/sofle_versions.md $BUILD_FOLDER/versions.md
# compress "sofle" "versions.md sofle_vial_high_encoder__deprecated.hex sofle_vial.hex sofle_vial_no_oled.hex sofle_vial_full_rgb.hex sofle_choc_vial_full_rgb.hex sofle_choc_vial.hex"