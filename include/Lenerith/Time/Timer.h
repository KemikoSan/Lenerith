#pragma once

#include <chrono>
#include <functional>

#include <Lenerith/DLL.h>

using namespace std::chrono_literals;

namespace Lenerith {
class LENERITH_API Timer {
public:
  Timer(std::chrono::duration<float> duration, const std::function<void()> &callback);
};
}; // namespace Lenerith
