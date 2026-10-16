#pragma once

#include <Lenerith/DLL.hpp>

namespace Lenerith {
class LENERITH_API Time {
public:
  static float deltatime;
  static float unscaledDeltatime;
  static float timescale;
  static void update();
};
}; // namespace Lenerith
