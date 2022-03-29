# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes     # Use RGB matrix
RGB_MATRIX_DRIVER = IS31FL3731

LTO_ENABLE = yes            # Reducing firmware size

LAYOUTS = 60_ansi 60_hhkb 60_iso 60_ansi_split_bs_rshift 60_tsangan_hhkb
