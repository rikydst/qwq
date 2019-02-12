#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(MARIO_MUSHROOM)
  #define UNICODE_SONG_OSX SONG(COIN_SOUND)
  #define UNICODE_SONG_LNX SONG(UNICODE_LINUX)
  #define UNICODE_SONG_WIN SONG(UNICODE_WINDOWS)
  #define UNICODE_SONG_WINC SONG(UNICODE_WINDOWS)
#endif

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4
// Mouse Parameters
#define MOUSEKEY_DELAY             300
#define MOUSEKEY_INTERVAL          50
#define MOUSEKEY_MAX_SPEED         8
#define MOUSEKEY_TIME_TO_MAX       20
