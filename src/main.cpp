#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Game.h>

using Lenerith::Config;
using Lenerith::Game;

int main() {
  Config config;
  Engine engine;
  Game game(engine);
  game.run();
}
