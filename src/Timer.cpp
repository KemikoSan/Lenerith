#define LENERITH_EXPORT

#include <chrono>
#include <functional>
#include <thread>

#include <Lenerith/Core/Time.h>
#include <Lenerith/Time/Timer.h>

Lenerith::Timer::Timer(std::chrono::duration<float> duration, const std::function<void()> &callback) {
  std::thread thread([=]() {
    std::this_thread::sleep_for(duration);
    callback();
  });
  thread.detach();
}
