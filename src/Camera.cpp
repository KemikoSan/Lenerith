#define LENERITH_EXPORT

#include "Lenerith/Core/Config.h"
#include <Lenerith/Camera.h>

void Lenerith::Camera::update(const Vector2 &target) {
  viewport.x = target.x + 450.f * 0.5f - Config::instance().screenWidth * 0.5f;
  viewport.y = target.y + 490.f * 0.5f - Config::instance().screenHeight * 0.5f;
}
