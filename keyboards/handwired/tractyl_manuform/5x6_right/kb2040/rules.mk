# MCU name
MCU = RP2040
BOOTLOADER = rp2040

OPT_DEFS += -DHAL_USE_I2C=TRUE

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
RGBLIGHT_ENABLE = yes

KEYBOARD_SHARED_EP = yes
CONSOLE_ENABLE     = yes
MOUSE_SHARED_EP    = yes

WS2812_DRIVER = vendor
SERIAL_DRIVER = vendor
