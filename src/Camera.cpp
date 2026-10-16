#define LENERITH_EXPORT

#include <SDL3/SDL_rect.h>

#include <Lenerith/Camera.hpp>
#include <Lenerith/Core/Config.hpp>

void Lenerith::Camera::update(const Vector2 &target) {
  viewport.x = target.x + 450.f * 0.5f - Config::instance().screenWidth * 0.5f;
  viewport.y = target.y + 490.f * 0.5f - Config::instance().screenHeight * 0.5f;
}
