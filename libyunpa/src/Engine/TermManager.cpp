module;
#include <format>
#include <iostream>
#include <mutex>
#include <thread>
#ifdef WIN32
#include <conio.h>
#else

#endif
module libyunpa;

namespace libyunpa {
void TermManager::DECSET(Modes mode) {
  std::cout << std::format("\x1b[?{}h", static_cast<int>(mode));
}

void TermManager::DECRST(Modes mode) {
  std::cout << std::format("\x1b[?{}l", static_cast<int>(mode));
}

void TermManager::enqueue_event(Event event) {
  std::lock_guard lock(_queueMutex);
  _eventQueue.push(event);
}

std::optional<Event> TermManager::poll_event() {
  std::lock_guard lock(_queueMutex);
  if (_eventQueue.empty()) {
    return {};
  }
  auto result{_eventQueue.front()};
  _eventQueue.pop();
  return result;
}

void TermManager::stop() {
  _running.clear();
  _running.notify_all();
  if (_monitor.joinable()) {
    _monitor.join();
  }
}

void TermManager::start() {
  _running.test_and_set();
  _running.notify_all();
  _monitor = std::thread(&TermManager::event_loop, this);
}

void TermManager::event_loop() {
  while (_running.test()) {
    std::string working_string;
    while (_kbhit() not_eq 0) {
    }
  }
}
} // namespace libyunpa
