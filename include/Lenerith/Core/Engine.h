#pragma once

#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Event.h>
#include <Lenerith/Core/Renderer.h>
#include <Lenerith/Core/Window.h>

using Lenerith::Renderer;
using Lenerith::Window;

namespace Lenerith {
class Engine {
private:
  Window window;
  Renderer renderer;

public:
  Engine();
  ~Engine();
  Renderer *getRenderer();
  Window *getWindow();
  void pollEvents();
};
}; // namespace Lenerith
