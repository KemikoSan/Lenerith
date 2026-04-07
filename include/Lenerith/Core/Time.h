#pragma once

namespace Lenerith {
class Time {
public:
  static float deltatime;
  static float unscaledDeltatime;
  static float timescale;
  static void update();
};
}; // namespace Lenerith
