#include "Lenerith/Time/Interval.hpp"
#define LENERITH_EXPORT

#include <Lenerith/Time/Interval.hpp>
#include <mutex>
#include <thread>

Lenerith::Interval::Interval(std::chrono::duration<float> interval, std::function<void()> callback) : interval(interval), callback(callback) {
  thread = std::thread([&] {
    running = true;
    while (running) {
      std::unique_lock<std::mutex> lock(mutex);
      condition.wait_for(lock, interval, [this] { return !running; });
      callback();
    }
  });
}

void Lenerith::Interval::stop() {
  if (running) {
    std::unique_lock<std::mutex> lock(mutex);
    running = false;
    lock.unlock();
    cv.notify_one();
    if (thread.joinable()) {
      thread.join();
    }
  }
}
