#include <Lenerith/Core/Config.h>
#include <fstream>

void Lenerith::Config::loadConfig() { std::ifstream file("config.json"); }

void Lenerith::Config::saveConfig() { std::ofstream file("config.json"); }
