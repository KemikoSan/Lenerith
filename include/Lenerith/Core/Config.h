#pragma once

#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Config {
public:
  int screenWidth = 800;
  int screenHeight = 600;
  bool fullscreen = false;
  bool borderlessWindow = false;
  bool vsync = true;
  float masterVolume = 1.0f;
  float soundVolume = 1.0f;
  float musicVolume = 1.0f;
  void loadConfig();
  void saveConfig(const Config &config);
  static Config &instance();
};
}; // namespace Lenerith
