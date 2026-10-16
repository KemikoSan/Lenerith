#pragma once

#include <Lenerith/DLL.hpp>

namespace Lenerith {
class LENERITH_API Vector2 {
public:
  float x;
  float y;

  Vector2 operator+(const Vector2 &vector);
  Vector2 operator-(const Vector2 &vector);
  Vector2 operator*(const Vector2 &vector);
  Vector2 operator*(float scalar);
  Vector2 operator/(const Vector2 &vector);
  Vector2 operator/(float scalar);
  bool operator==(const Vector2 &vector) const;
  Vector2 &operator=(const Vector2 &vector);

  float Lenght() const;
  float Distance(const Vector2 &vector);
  float Dot(const Vector2 &vector);
  Vector2 Normalized();
  Vector2 Lerp(const Vector2 &target, float t);

  Vector2(float x, float y);
};
}; // namespace Lenerith
