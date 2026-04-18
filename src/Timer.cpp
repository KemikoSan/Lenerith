#define LENERITH_EXPORT

#include <chrono>
#include <functional>
#include <thread>

#include <Lenerith/Core/Time.h>
#include <Lenerith/Timer.h>

Lenerith::Timer::Timer(std::chrono::seconds duration, const std::function<void()> &callback) {
  std::thread thread([=]() {
    std::this_thread::sleep_for(duration);
    callback();
  });
  thread.detach();
}

Lenerith::Timer::~Timer() {}
