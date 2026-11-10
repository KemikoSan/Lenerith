#define LENERITH_EXPORT

#include <SDL3/SDL_rect.h>

#include <Lenerith/Camera.hpp>
#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Engine.hpp>

void Lenerith::Camera::update(const Vector2 &target) {
  Config &config = Engine::instance().config;
  viewport.x = target.x + 450.f * 0.5f - config.screenWidth * 0.5f;
  viewport.y = target.y + 490.f * 0.5f - config.screenHeight * 0.5f;
}
