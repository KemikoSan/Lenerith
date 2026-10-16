#define LENERITH_EXPORT

#include <chrono>
#include <functional>
#include <thread>

#include <Lenerith/Core/Time.hpp>
#include <Lenerith/Time/Timer.hpp>

Lenerith::Timer::Timer(std::chrono::duration<float> duration, const std::function<void()> &callback) {
  std::thread thread([=]() {
    std::this_thread::sleep_for(duration);
    callback();
  });
  thread.detach();
}
