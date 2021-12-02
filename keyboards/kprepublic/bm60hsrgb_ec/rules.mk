# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes             # USB Nkey Rollover
BACKLIGHT_ENABLE = no        # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no             # MIDI support
UNICODE_ENABLE = no          # Unicode
BLUETOOTH_ENABLE = no        # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no            # Audio output on port C6
FAUXCLICKY_ENABLE = no       # Use buzzer to emulate clicky switches
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812
LTO_ENABLE = yes
ENCODER_ENABLE = yes
DYNAMIC_KEYMAP_ENABLE = yes
