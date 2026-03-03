#include "Lenerith/Core/Config.h"
#include <Lenerith/Camera.h>

void Camera::update(const Vector2 &target) {
  viewport.x = target.x + 450.f / 2 - config.screenWidth / 2.f;
  viewport.y = target.y + 490.f / 2 - config.screenHeight / 2.f;
}
