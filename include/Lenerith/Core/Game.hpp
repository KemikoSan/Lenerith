#pragma once

#include <Lenerith/Core/Engine.hpp>
#include <Lenerith/DLL.hpp>
#include <Lenerith/Entity/Entity.hpp>

namespace Lenerith {
class LENERITH_API Game {
private:
  bool isRunning = false;
  bool isPaused = false;

public:
  Game();
  void setGamePaused(bool paused);
  void run();
  void quit();
  void handleEvents();
};
}; // namespace Lenerith
