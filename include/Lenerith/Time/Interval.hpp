#pragma once

#include <chrono>
#include <functional>
#include <mutex>

#include <Lenerith/DLL.hpp>

using namespace std::chrono_literals;

namespace Lenerith {
class LENERITH_API Interval {
private:
  std::thread thread;
  std::chrono::duration<float> interval;
  std::function<void()> callback;
  std::condition_variable condition;
  std::mutex mutex;
  bool running = false;

public:
  Interval(std::chrono::duration<float> interval, std::function<void()> callback);
  void stop();
};
}; // namespace Lenerith
