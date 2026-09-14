#pragma once

#include <Lenerith/Core/Engine.h>
#include <Lenerith/DLL.h>
#include <Lenerith/Entity/Entity.h>

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
