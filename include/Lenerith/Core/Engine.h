#pragma once

#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Event.h>
#include <Lenerith/Core/Renderer.h>
#include <Lenerith/Core/Window.h>
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API Engine {
private:
  Window window;
  Renderer renderer;

public:
  Engine();
  ~Engine();
  Lenerith::Renderer *getRenderer();
  Lenerith::Window *getWindow();
  void pollEvents();
};
}; // namespace Lenerith
