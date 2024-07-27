# Cover65

![Cover65](https://i.imgur.com/m1EFfOUh.png)

Support STM32F103 keyboard.

* Keyboard Maintainer: [TW59420](https://github.com/TW59420)
* Hardware Supported: STM32F103

Make example for this keyboard (after setting up your build environment):

    make mwstudio/cover65:default

Flashing example for this keyboard:

    make mwstudio/cover65:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Physical reset button**: Short press the button on the back of the PCB to enter the Bootloader and flash the firmware
* **Keycode in layout**: Press the key mapped to QK_BOOT if it is available
