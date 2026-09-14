#pragma once

#include <SDL3/SDL_rect.h>

#include <Lenerith/Core/Config.h>
#include <Lenerith/DLL.h>
#include <Lenerith/Math/Vector2.h>

namespace Lenerith {
class LENERITH_API Camera {
public:
  float scale = 0;
  SDL_FRect viewport{0, 0, static_cast<float>(Config::instance().screenWidth), static_cast<float>(Config::instance().screenHeight)};
  void update(const Vector2 &target);
};
}; // namespace Lenerith
