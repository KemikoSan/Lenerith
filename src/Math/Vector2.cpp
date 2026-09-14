#define LENERITH_EXPORT

#include <cmath>

#include <Lenerith/Math/Vector2.h>

Lenerith::Vector2::Vector2(float x, float y) : x(x), y(y) {}

Lenerith::Vector2 Lenerith::Vector2::operator+(const Vector2 &vector) {
  return Vector2(x + vector.x, y + vector.y);
}

Lenerith::Vector2 Lenerith::Vector2::operator*(const Vector2 &vector) {
  return Vector2(x * vector.x, y * vector.y);
}

Lenerith::Vector2 Lenerith::Vector2::operator*(float scalar) {
  return Vector2(x * scalar, y * scalar);
}

float Lenerith::Vector2::Lenght() const {
  return std::sqrt(x * x + y * y);
}

float Lenerith::Vector2::Distance(const Vector2 &vector) {
  return std::sqrt(x - vector.x * x - vector.x + y - vector.y * y - vector.y);
}

Lenerith::Vector2 &Lenerith::Vector2::operator=(const Vector2 &vector) {
  x = vector.x;
  y = vector.y;
  return *this;
}
