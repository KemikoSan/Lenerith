#pragma once

#include <chrono>
#include <functional>
#include <thread>

using namespace std::chrono_literals;

namespace Lenerith {
class Timer {
private:
public:
  Timer(std::chrono::seconds duration, const std::function<void()> &callback);
  ~Timer();
};
}; // namespace Lenerith
