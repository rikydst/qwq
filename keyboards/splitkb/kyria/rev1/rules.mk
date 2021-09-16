OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no     # Enable keyboard RGB matrix (do not use together with RGBLIGHT_ENABLE)
RGB_MATRIX_DRIVER = WS2812 # RGB matrix driver support

RGB_MATRIX_SUPPORTED = yes

ifeq ($(strip $(CTPC)), yes)
    CONVERT_TO_PROTON_C := yes
endif

ifeq ($(strip $(CONVERT_TO_PROTON_C)), yes)
    WS2812_DRIVER = pwm
    SERIAL_DRIVER = usart
    AUDIO_ENABLE = no
    LTO_ENABLE = no
endif
