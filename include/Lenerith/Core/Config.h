#pragma once
#include <SDL3/SDL_stdinc.h>

namespace Lenerith {
class Config {
public:
  Uint32 screenWidth;
  Uint32 screenHeight;
  bool fullscreen;
  bool borderlessWindow;
  bool vsync;
  float masterVolume;
  float soundVolume;
  float musicVolume;
  void loadConfig();
  void saveConfig(const Config &config);
};
}; // namespace Lenerith

inline Lenerith::Config config;
