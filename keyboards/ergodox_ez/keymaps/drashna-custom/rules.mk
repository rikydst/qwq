TAP_DANCE_ENABLE  = yes
<<<<<<< HEAD
<<<<<<< HEAD
SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
COMMAND_ENABLE    = yes  # Commands for debug and configuration
<<<<<<< HEAD
RGBLIGHT_ENABLE   = yes
MIDI_ENABLE       = no
CONSOLE_ENABLE    = no
LEADER_KEYS       = no

EXTRAFLAGS        = -flto
=======
SLEEP_LED_ENABLE  = yes  # Breathing sleep LED during USB suspend
=======
SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
>>>>>>> Finishing up Viterbi keyboard layout, and NKRO tweaks to other layouts
COMMAND_ENABLE    = no  # Commands for debug and configuration
=======
>>>>>>> Clean up and updates of drashna keymaps
RGBLIGHT_ENABLE   = yes
MIDI_ENABLE       = no
<<<<<<< HEAD
<<<<<<< HEAD
CONSOLE_ENABLE    = yes
>>>>>>> Updated RGB Underglow info
=======
CONSOLE_ENABLE    = no
>>>>>>> Cleanup macros

=======
CONSOLE_ENABLE    = no
LEADER_KEYS       = no
>>>>>>> Add Viterbi one handed layout and minor tweaks to others
ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
