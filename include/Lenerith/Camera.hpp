#pragma once

#include "Lenerith/Core/Engine.hpp"
#include <SDL3/SDL_rect.h>

#include <Lenerith/Core/Config.hpp>
#include <Lenerith/DLL.hpp>
#include <Lenerith/Math/Vector2.hpp>

namespace Lenerith {
class LENERITH_API Camera {
private:
public:
  float scale = 1.0f;
  SDL_FRect viewport{0, 0, static_cast<float>(Engine::instance().config.screenWidth), static_cast<float>(Engine::instance().config.screenHeight)};
  void update(const Vector2 &target);
};
}; // namespace Lenerith
