#pragma once

/*
 * Compatibility header for porting WLED-MM usermods to standard WLED
 * Provides missing features from MoonModules WLED fork
 */

#include "wled.h"

// Audio reactive constants - must have audioreactive usermod enabled
#ifndef NUM_GEQ_CHANNELS
  #define NUM_GEQ_CHANNELS 16  // Matches audioreactive usermod
#endif

// Compatibility shim for suspendPlaylist() - not available in standard WLED
// In standard WLED, we just unload the playlist before changing
inline void suspendPlaylist() {
  // Standard WLED doesn't have suspend, just unload
  unloadPlaylist();
}

// Extended Usermod base class members for compatibility
// In WLED-MM, these are part of the Usermod base class
// In standard WLED, we need to add them to derived classes
#define WLEDMM_USERMOD_COMPAT \
protected: \
  bool enabled = false; \
  const char *_name = nullptr; \
  bool initDone = false; \
  unsigned long lastTime = 0; \
public: \
  void setEnabled(bool en) { enabled = en; } \
  bool isEnabled() const { return enabled; } \
  const char* getName() const { return _name; }
