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
  }
}

void Lenerith::Config::saveConfig(const Config &config) {
  std::ofstream file("config.json");
}
