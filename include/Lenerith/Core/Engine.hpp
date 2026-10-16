#pragma once

#include <Lenerith/Core/Audio.hpp>
#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Event.hpp>
#include <Lenerith/Core/Renderer.hpp>
#include <Lenerith/Core/Window.hpp>
#include <Lenerith/DLL.hpp>

namespace Lenerith {
class LENERITH_API Engine {
private:
  Config config;
  Window window;
  Renderer renderer;
  Audio audio;

public:
  Engine();
  ~Engine();
  Renderer *getRenderer();
  Window *getWindow();
  void pollEvents();
};
}; // namespace Lenerith
