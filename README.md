# Vial-compatible QMK firmware for splitted.space keyboards

This repository provides configuration files for building your own firmware based on QMK. More about QMK itself you can read at the [official page](https://qmk.fm/).
To learn all the intricacies of configuring the firmware, refer to the official [documentation](https://docs.qmk.fm/#/).

By default, we use a slightly modified version of QMK which supports the keyboards configuration over [Vial](https://get.vial.today/) that helps to use all the QMK`s power in customization. But if for some reason, for example, to leave some extra memory space on your keyboard you want to come back to the original QMK firmware you need to change the repository link during setup.

## Preparation

1. Download this repository to your computer
2. Refer to [original docs](https://docs.qmk.fm/#/newbs_getting_started?id=set-up-your-environment) to see the instructions how to prepare build environment

## Setup

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

## Build

Now you are ready to build you own firmware. To do this chose needed keyboard/keymap and run:
```
% qmk compile -kb __keyboard__ -km __keymap__
```

For example:
```
% qmk compile -kb lea/v1 -km base
```

