#pragma once

#include <Lenerith/Core/Engine.h>
#include <Lenerith/Entity.h>
#include <memory>
#include <vector>

using Lenerith::Engine;

namespace Lenerith {
class Game {
private:
  Engine &engine;
  bool isRunning = false;
  bool isPaused = false;
  std::vector<std::unique_ptr<Entity>>
      entities; // entities to update and render

public:
  Game(Engine &engine);
  void run();
  void setGamePaused(bool paused);
  void quit();
  float getDeltaTime();
  void handleEvents();
};
}; // namespace Lenerith
