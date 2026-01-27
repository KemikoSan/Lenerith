#pragma once
#include <SDL3/SDL_stdinc.h>

namespace Lenerith {
class Config {
public:
  Uint32 screenWidth = 800;
  Uint32 screenHeight = 600;
  bool fullscreen = false;
  bool borderlessWindow = true;
  float masterVolume;
  float soundVolume;
  float musicVolume;
  void loadConfig();
  void saveConfig();
};
}; // namespace Lenerith
