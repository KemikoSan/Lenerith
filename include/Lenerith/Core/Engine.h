#pragma once

#include <Lenerith/Core/Event.h>
#include <Lenerith/Core/Renderer.h>
#include <Lenerith/Core/Window.h>
#include <queue>

using Lenerith::Renderer;
using Lenerith::Window;

namespace Lenerith {
class Engine {
private:
  Window window;
  Renderer renderer;
  SDL_Gamepad *gamepads;

public:
  Engine();
  ~Engine();
  Renderer *getRenderer();
  void pollEvents();
  std::queue<Event> eventQueue;
};
}; // namespace Lenerith
