# Hackpad Macropad

A 9-key macropad with a rotary encoder and 128x32 OLED, built on the Seeed XIAO RP2040.

* Keyboard Maintainer: [HeII-alt](https://github.com/HeII-alt)
* Hardware Supported: Seeed XIAO RP2040
* Hardware Availability: https://github.com/HeII-alt/Hackpad-Macropad

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb hackpad_macropad -km default

Flashing example for this keyboard:

    qmk flash -kb hackpad_macropad -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the top-left key (SW1) and plug in the keyboard
* **Physical reset button**: Double-tap the reset button on the XIAO RP2040 (or hold BOOT while plugging in USB)
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is defined
