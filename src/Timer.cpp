#include <Lenerith/Core/Time.h>
#include <Lenerith/Timer.h>
#include <chrono>
#include <functional>
#include <thread>

Lenerith::Timer::Timer(std::chrono::seconds duration, const std::function<void()> &callback) {
  std::thread thread([duration, callback]() {
    std::this_thread::sleep_for(duration);
    callback();
  });
  thread.detach();
}

Lenerith::Timer::~Timer() {}
