# Default keymap does not have any overridden options from the rev1 / rev2 rules.mk files.
# Example:
#     if you wanted to disable EXTRAKEY_ENABLE, you would copy the line from the rev1/rules.mk file
#     and paste it in to this file, changing the yes to no. Like so:
# EXTRAKEY_ENABLE         = no       # Audio control and System control(+450)
#
# To keep things clean and tidy, as well as make upgrades easier, only place overrides from the defaults in this file.





# Do not edit past here

ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
    OPT_DEFS += -DIOS_DEVICE_ENABLE
else ifeq ($(strip $(RGBLIGHT_FULL_POWER)), yes)
    OPT_DEFS += -DRGBLIGHT_FULL_POWER
endif

ifeq ($(strip $(RGB_MATRIX_KEYPRESSES)), yes)
    OPT_DEFS += -DRGB_MATRIX_KEYPRESSES
endif

ifeq ($(strip $(RGB_MATRIX_FRAMEBUFFER)), yes)
    OPT_DEFS += -RGB_MATRIX_FRAMEBUFFER_EFFECTS
endif

ifeq ($(strip $(LED_MIRRORED)), yes)
    OPT_DEFS += -DLED_MIRRORED
endif

ifeq ($(strip $(FULLHAND_ENABLE)), yes)
    OPT_DEFS += -DFULLHAND_ENABLE
endif

ifeq ($(strip $(EXTRA_ENCODERS_ENABLE)), yes)
    OPT_DEFS += -DEXTRA_ENCODERS_ENABLE
endif

