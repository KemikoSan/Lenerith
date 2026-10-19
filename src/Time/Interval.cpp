#define LENERITH_EXPORT

#include <mutex>
#include <thread>

#include <Lenerith/Time/Interval.hpp>

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
    condition.notify_one();
    if (thread.joinable()) {
      thread.join();
    }
  }
}
