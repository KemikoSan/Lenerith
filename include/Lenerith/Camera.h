#pragma once

#include "Lenerith/Math/Vector2.h"
#include <Lenerith/Core/Config.h>
#include <SDL3/SDL_rect.h>

class Camera {
public:
  float scale = 0;
  SDL_FRect viewport{0, 0, static_cast<float>(config.screenWidth), static_cast<float>(config.screenHeight)};
  void update(const Vector2 &target);
};
