module;
#include <atomic>
#include <cstdint>
#include <format>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>
#ifdef WIN32
#include <conio.h>
#else
#include <sys/ioctl.h>
#include <termios.h>
#endif
export module libyunpa:TermManager;
import :Events;

#ifndef WIN32
int _kbhit() {
  static constexpr auto STDIN{0};
  static bool initialized{false};

  if (not initialized) {
    termios term{};
    tcgetattr(STDIN, &term);
    term.c_cflag and_eq static_cast<tcflag_t>(compl ICANON);
    tcsetattr(STDIN, TCSANOW, &term);
    // NOLINTNEXTLINE(bugprone-unsafe-functions)
    setbuf(stdin, nullptr);
    initialized = true;
  }

  auto bytesWaiting{0};
  // NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg)
  ioctl(STDIN, FIONREAD, &bytesWaiting);
  return bytesWaiting;
}
#endif
namespace libyunpa {
export class TermManager final {

public:
  enum Modes : std::uint8_t { APPLICATION_CURSOR_KEYS = 1 };

  static auto DECSET(Modes mode) {
    std::cout << std::format("\x1b[?{}h", static_cast<int>(mode));
  }

  static auto DECRST(Modes mode) {
    std::cout << std::format("\x1b[?{}l", static_cast<int>(mode));
  }

private:
  std::thread _monitor;
  std::atomic_flag _running;

  std::mutex _queueMutex;
  std::queue<Event> _eventQueue;

  auto enqueue_event(Event event) {
    std::lock_guard lock(_queueMutex);
    _eventQueue.push(event);
  }

  auto event_loop() {
    while (_running.test()) {
      std::string working_string;
      while (_kbhit() not_eq 0) {
      }
    }
  }

public:
  auto start() {
    _running.test_and_set();
    _running.notify_all();
    _monitor = std::thread(&TermManager::event_loop, this);
  }

  auto stop() {
    _running.clear();
    _running.notify_all();
    if (_monitor.joinable()) {
      _monitor.join();
    }
  }

  auto poll_event() {
    std::lock_guard lock(_queueMutex);
    if (_eventQueue.empty()) {
      return std::optional<Event>{};
    }
    auto result{_eventQueue.front()};
    _eventQueue.pop();
    return std::optional<Event>{result};
  }
};
} // namespace libyunpa
