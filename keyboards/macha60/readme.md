# macha60

![macha60](https://i.imgur.com/tTY8uvX.png)

*A short description of the keyboard/project*

* Keyboard Maintainer: [CMM.Studio Freather](https://github.com/CMM.Studio Freather)
* Hardware Supported: Atmega32U4, custom PCB
* Hardware Availability: none

Make example for this keyboard (after setting up your build environment):

    make macha60:default

Flashing example for this keyboard:

    make macha60:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top left key and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
