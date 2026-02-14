#include "Lenerith/Core/Engine.h"
#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Game.h>

using Lenerith::Config;
using Lenerith::Engine;
using Lenerith::Game;

int main() {
  Config config;
  config.loadConfig();
  Engine engine(config);
  Game game(engine);
  game.run();
  return 0;
}
