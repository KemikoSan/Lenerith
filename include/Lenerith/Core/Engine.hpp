#pragma once

#include <Lenerith/Core/Audio.hpp>
#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Event.hpp>
#include <Lenerith/Core/Renderer.hpp>
#include <Lenerith/Core/Window.hpp>
#include <Lenerith/DLL.hpp>
#include <Lenerith/Input/Input.hpp>

namespace Lenerith {
class LENERITH_API Engine {
public:
  Config config;
  Window window;
  Renderer renderer;
  Audio audio;
  Input input;

private:
  Engine();

public:
  static Engine &instance();
  ~Engine();
  void pollEvents();
};
}; // namespace Lenerith
