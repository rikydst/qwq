# Proton C MCU settings for converting AVR projects
MCU = STM32F303xC

# These are defaults based on what has been implemented for ARM boards
AUDIO_ENABLE = yes
WS2812_DRIVER = bitbang

# Force task driven PWM until ARM can provide automatic configuration
BACKLIGHT_DRIVER = software
