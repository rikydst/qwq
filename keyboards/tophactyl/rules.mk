MCU = atmega32u4

BOOTLOADER = atmel-dfu

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
BACKLIGHT_ENABLE = no       
RGBLIGHT_ENABLE = no        
AUDIO_ENABLE = no           
TAP_DANCE_ENABLE = yes
EXTRAFLAGS += -flto
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes