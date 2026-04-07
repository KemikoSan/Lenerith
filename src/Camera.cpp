#include "Lenerith/Core/Config.h"
#include <Lenerith/Camera.h>

void Camera::update(const Vector2 &target) {
  viewport.x = target.x + 450.f * 0.5f - config.screenWidth * 0.5f;
  viewport.y = target.y + 490.f * 0.5f - config.screenHeight * 0.5f;
}
