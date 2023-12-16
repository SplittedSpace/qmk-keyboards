# Vial-compatible QMK firmware for splitted.space keyboards

This repository provides configuration files for building your own firmware based on QMK. More about QMK itself you can read at the [official page](https://qmk.fm/).
To learn all the intricacies of configuring the firmware, refer to the official [documentation](https://docs.qmk.fm/#/).

By default, we use a slightly modified version of QMK which supports the keyboards configuration over [Vial](https://get.vial.today/) that helps to use all the QMK`s power in customization. But if for some reason, for example, to leave some extra memory space on your keyboard you want to come back to the original QMK firmware you need to change the repository link during setup.

## Use a pre-built firmware

If you want to get pre-built ready for use firmware for your keyboard please refer to our [relases page](https://github.com/splitted.space/qmk-keyboards/releases)

## Make your own firmware

### Preparation

1. Download this repository to your computer
2. Refer to [original docs](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment) to see the instructions how to prepare build environment

### Setup

1. Setup QMK. This will install the QMK to your home directory:
   ```
   % qmk setup -b vial https://github.com/vial-kb/vial-qmk
   ```
   
2. Go to the folder where the current repository was downloaded and replace QMK keyboards folder with the link to the keyboards of us:
   ```
   ## Linux / MacOS

    % rm -rf ~/qmk_firmware/keyboards
    % cd vial-qmk-keyboards
    % ln -s $(pwd)/keyboards ~/qmk_firmware/keyboards

   ## Windows

    % TBC

   ```
3. Ensure keyboards are mapped properly. You should see the list of our keyboards:
   ```
   % qmk list-keyboards
   ``` 

### Build

Now you are ready to build you own firmware. To do this chose needed keyboard/keymap and run:
```
% qmk compile -kb __keyboard__ -km __keymap__
```

For example:
```
% qmk compile -kb lea/v1 -km base
```

## How to flash firmware to a keyboard

For flashing the firmware we recommend using [QMK Toolbox](https://github.com/qmk/qmk_toolbox)

1. Prepare a firmware:
   * `If you're going to use pre-build firmware`:
      1. Go to a [relases page](https://github.com/splitted.space/qmk-keyboards/releases)
      2. Choose the appropriate .hex (or .bin) file; all files are prefixed with the exact keyboard model, also the readme describes the firmware details
      3. Download firmware to your compouter
   * `Otherwise compile firmware as described above`
2. Open QMK Toolbox and choose in "Local file" the previously downloaded firmware
3. Connect your keyboard to USB
4. Find the Reset button on your keyboard and press it.  May need one or two pressing depends on keyboard hardware.
5. Press the "Flash" button and wait until the firmware is flashed
6. If your keyboard is a split and have more than one part, repeat steps 4-5 for each parts
7. Enjoy :)


## Useful information about the hardware

### Arduino
If your keyboard has an Arduino installed on the shield then it is Atmega32u4 controller with Caterina bootloader that should be used for firmware.

### Leds
All the boards have WS2812/SK6812 diodes for RGB lighting. Optionally if your board has only the bottom lighting RGBW setting should be used in QMK configuration.