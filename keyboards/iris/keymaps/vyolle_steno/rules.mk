EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
STENO_ENABLE = yes          # Additional protocols for Stenography(+1700), requires VIRTSER
AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls
NKRO_ENABLE = yes
BOOTMAGIC_ENABLE = yes



ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
