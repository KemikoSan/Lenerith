#pragma once

#include <Lenerith/Core/Audio.h>
#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Event.h>
#include <Lenerith/Core/Renderer.h>
#include <Lenerith/Core/Window.h>
#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Engine {
private:
  Window window;
  Renderer renderer;
  Audio audio;
  Config config;

public:
  Engine();
  ~Engine();
  Renderer *getRenderer();
  Window *getWindow();
  void pollEvents();
};
}; // namespace Lenerith
