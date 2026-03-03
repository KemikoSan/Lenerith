#include <Lenerith/Core/Config.h>
#include <Nlohmann/json.hpp>
#include <fstream>

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

void Lenerith::Config::saveConfig(const Config &config) {
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
