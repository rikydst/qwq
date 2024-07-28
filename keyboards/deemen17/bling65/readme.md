# Bling65

![Bling65](https://i.imgur.com/qhlkSde.png)

65% Keyboard PCB

* Keyboard Maintainer: [Deemen17](https://github.com/Deemen17)
* Hardware Supported: Bling65 PCB
* Hardware Availability: [Deemen17 Works](https://www.facebook.com/deemen17)

Make example for this keyboard (after setting up your build environment):

    make deemen17/bling65:default

Flashing example for this keyboard:

    make deemen17/bling65:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly double press the button RESET on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
