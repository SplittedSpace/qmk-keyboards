#!/bin/bash

DIST_FOLDER="./.build"
BUILD_FOLDER="$(eval echo ~$USER)/qmk_firmware/.build"
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
DATE_S=$(date +%F)

compress () {
    n=($2)
    zip -j ./.build/$1_$DATE_S.zip "${n[@]/#/$DIST_FOLDER/}"
    rm "${n[@]/#/$DIST_FOLDER/}"
}


rm -rf .build && mkdir .build

# Lea
qmk compile -kb lea/v1 -km base                 && cp $BUILD_FOLDER/lea_v1_base.bin $DIST_FOLDER/LA1-01__$DATE_S.bin
qmk compile -kb lea/v2 -km base                 && cp $BUILD_FOLDER/lea_v2_base.bin $DIST_FOLDER/LA2-01__$DATE_S.bin
qmk compile -kb lea/v3 -km base                 && cp $BUILD_FOLDER/lea_v3_base.bin $DIST_FOLDER/LA3-01__$DATE_S.bin
qmk compile -kb lea/v1 -km oled                 && cp $BUILD_FOLDER/lea_v1_oled.bin $DIST_FOLDER/LA1-02__$DATE_S.bin
qmk compile -kb lea/v1 -km lcd                  && cp $BUILD_FOLDER/lea_v1_lcd.bin $DIST_FOLDER/LA1-03__$DATE_S.bin

qmk compile -kb lea_choc/v1 -km base            && cp $BUILD_FOLDER/lea_choc_v1_base.bin $DIST_FOLDER/LC1-01__$DATE_S.bin

compress "lea" "lea_versions.md LA1-01__$DATE_S.bin LA2-01__$DATE_S.bin LA3-01__$DATE_S.bin LA1-02__$DATE_S.bin LA1-03__$DATE_S.bin"
compress "lea_choc" "lea_choc_versions.md LC1-01__$DATE_S.bin"

# Cleo
qmk compile -kb cleo/v1_01 -km base              && cp $BUILD_FOLDER/cleo_v1_01_base.bin $DIST_FOLDER/CL1-01__$DATE_S.bin
qmk compile -kb cleo/v1_02 -km base              && cp $BUILD_FOLDER/cleo_v1_02_base.bin $DIST_FOLDER/CL1-02__$DATE_S.bin
qmk compile -kb cleo/v2_02 -km base              && cp $BUILD_FOLDER/cleo_v2_02_base.bin $DIST_FOLDER/CL2-02__$DATE_S.bin

qmk compile -kb cleo_ks/v2_01 -km base           && cp $BUILD_FOLDER/cleo_ks_v2_01_base.bin $DIST_FOLDER/CK2-01__$DATE_S.bin

compress "cleo" "cleo_versions.md CL1-01__$DATE_S.bin CL1-02__$DATE_S.bin CL2-02__$DATE_S.bin"
compress "cleo_ks" "cleo_ks_versions.md CK2-01__$DATE_S.bin"

# M1 + 
qmk compile -kb m_one/v1 -km base               && cp $BUILD_FOLDER/m_one_v1_base.bin $DIST_FOLDER/MM1-01__$DATE_S.bin
qmk compile -kb m_one/v1 -km midi               && cp $BUILD_FOLDER/m_one_v1_midi.bin $DIST_FOLDER/MM1-01_midi__$DATE_S.bin
qmk compile -kb m_one/v2 -km base               && cp $BUILD_FOLDER/m_one_v2_base.bin $DIST_FOLDER/MM2-01__$DATE_S.bin
qmk compile -kb m_one/v2 -km midi               && cp $BUILD_FOLDER/m_one_v2_midi.bin $DIST_FOLDER/MM2-01_midi__$DATE_S.bin

compress "m_one" "m_one_versions.md MM1-01__$DATE_S.bin MM1-01_midi__$DATE_S.bin MM2-01__$DATE_S.bin MM2-01_midi__$DATE_S.bin"

# Corne
# qmk compile -kb crkbd/ssp -km ssp_all_leds          && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds.hex              $DIST_FOLDER/corne_vial.hex
# qmk compile -kb crkbd/ssp -km ssp_underglow         && mv $BUILD_FOLDER/crkbd_ssp_ssp_underglow.hex             $DIST_FOLDER/corne_vial_underglow.hex
# qmk compile -kb crkbd/ssp -km ssp_all_leds_no_oled  && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds_no_oled.hex      $DIST_FOLDER/corne_vial_no_oled.hex
# qmk compile -kb crkbd/ssp -km ssp_underglow_no_oled && mv $BUILD_FOLDER/crkbd_ssp_ssp_underglow_no_oled.hex     $DIST_FOLDER/corne_vial_underglow_no_oled.hex

# # Corne Choc
# qmk compile -kb crkbd/ssp -km ssp_all_leds          && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds.hex              $DIST_FOLDER/corne_choc_vial.hex
# qmk compile -kb crkbd/ssp -km ssp_all_leds_no_oled  && mv $BUILD_FOLDER/crkbd_ssp_ssp_all_leds_no_oled.hex      $DIST_FOLDER/corne_choc_vial_no_oled.hex

# cp $SCRIPT_DIR/corne_versions.md $DIST_FOLDER/versions.md
# compress "corne" "versions.md corne_vial.hex corne_vial_underglow.hex corne_vial_no_oled.hex corne_vial_underglow_no_oled.hex corne_choc_vial.hex corne_choc_vial_no_oled.hex"

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