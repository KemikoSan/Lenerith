#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Game.h>

using Lenerith::Config;
using Lenerith::Game;

int main() {
  Config config;
  config.loadConfig();
  Engine engine(config);
  Game game(engine);
  game.run();
}
