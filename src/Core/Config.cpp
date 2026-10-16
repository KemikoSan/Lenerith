#define LENERITH_EXPORT

#include <Lenerith/Core/Config.hpp>
#include <Nlohmann/json.hpp>
#include <fstream>

Lenerith::Config &Lenerith::Config::instance() {
  static Config instance;
  return instance;
}

void Lenerith::Config::loadConfig() {
  std::ifstream file("config.json");
  if (file.good()) {
    nlohmann::json config = config.parse(file);
    screenWidth = config["display"]["width"];
    screenHeight = config["display"]["height"];
    fullscreen = config["display"]["fullscreen"];
    borderlessWindow = config["display"]["borderless"];
    vsync = config["display"]["vsync"];
    masterVolume = config["audio"]["master"];
    soundVolume = config["audio"]["sound"];
    musicVolume = config["audio"]["music"];
  }
}

void Lenerith::Config::saveConfig() {
  std::ofstream file("config.json");
  if (file.good()) {
    nlohmann::json config;
    config["display"]["width"] = screenWidth;
    config["display"]["height"] = screenHeight;
    config["display"]["fullscreen"] = fullscreen;
    config["display"]["borderless"] = borderlessWindow;
    config["display"]["vsync"] = vsync;
    config["audio"]["master"] = masterVolume;
    config["audio"]["sound"] = soundVolume;
    config["audio"]["music"] = musicVolume;
    file << config;
  }
}
