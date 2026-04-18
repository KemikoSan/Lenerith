#pragma once

#include <Lenerith/export.h>
#include <chrono>
#include <functional>

using namespace std::chrono_literals;

namespace Lenerith {
class LENERITH_API Timer {
private:
public:
  Timer(std::chrono::seconds duration, const std::function<void()> &callback);
  ~Timer();
};
}; // namespace Lenerith
