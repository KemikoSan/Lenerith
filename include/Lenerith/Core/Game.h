#pragma once

#include <Lenerith/Core/Engine.h>
#include <Lenerith/Entity/Entity.h>

namespace Lenerith {
class Game {
private:
  Engine &engine;
  bool isRunning = false;
  bool isPaused = false;

public:
  Game(Engine &engine);
  void run();
  void setGamePaused(bool paused);
  void quit();
  float getDeltaTime();
  void handleEvents();
};
}; // namespace Lenerith
