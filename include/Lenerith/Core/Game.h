#pragma once

#include <Lenerith/Core/Engine.h>
#include <Lenerith/Entity/Entity.h>
#include <Lenerith/Scene.h>
#include <vector>

using Lenerith::Engine;

namespace Lenerith {
class Game {
private:
  Engine &engine;
  bool isRunning = false;
  bool isPaused = false;
  int currentScene = 0;
  std::vector<Scene> scenes;

public:
  Game(Engine &engine);
  void run();
  void setGamePaused(bool paused);
  void quit();
  float getDeltaTime();
  void handleEvents();
  // void nextScene();
};
}; // namespace Lenerith
