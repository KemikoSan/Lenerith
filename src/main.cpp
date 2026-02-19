#include "Lenerith/Core/Engine.h"
#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Game.h>

using Lenerith::Engine;
using Lenerith::Game;

int main() {
  config.loadConfig();
  Engine engine;
  Game game(engine);
  game.run();
  return 0;
}
