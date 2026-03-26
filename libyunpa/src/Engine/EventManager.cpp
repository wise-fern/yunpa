module;
#include <atomic>
#include <iostream>
#include <mutex>
#include <optional>
#include <queue>
#include <tao/pegtl.hpp>
#include <thread>

#ifdef WIN32
#include <conio.h>
#else
#include <sys/ioctl.h>
#include <termios.h>
#endif
module libyunpa;
import :EventManager;
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
namespace {
namespace Grammar {
using namespace tao::pegtl;

struct ESC : one<'\x1b'> {};

struct CSI : seq<ESC, one<'['>> {};

struct OSC : seq<ESC, one<']'>> {};

struct ST : seq<ESC, one<'\\'>> {};

template <char... delim>
struct DigitPlusTerm : seq<plus<digit>, one<delim...>> {};

using DigitPlusSemi = DigitPlusTerm<';'>;

struct Language : sor<> {};
} // namespace Grammar

template <typename Rule> struct Action {
  template <typename ActionInput>
  static void apply([[maybe_unused]] const ActionInput &actionInput) {}
};

template <> struct Action<Grammar::Win32InputString> {
  template <typename ActionInput>
  static void apply([[maybe_unused]] const ActionInput &actionInput) {
    // TODO Create KeyEvent from Win32 input string
  }
};
} // namespace

namespace libyunpa {
void EventManager::event_loop() {
  while (_running.test()) {
    std::string working_string;
    while (_kbhit() not_eq 0) {
      auto input{std::cin.get()};
      working_string += static_cast<char>(input);
      auto parser_input = tao::pegtl::memory_input(working_string, "");
      if (tao::pegtl::parse<Grammar::Language>(parser_input)) {
        working_string.clear();
      }
    }
  }
}

void EventManager::enqueue_event(Event event) {
  std::lock_guard lock(_queueMutex);
  _eventQueue.push(event);
}

void EventManager::start() {
  _running.test_and_set();
  _running.notify_all();
  _monitor = std::thread(&EventManager::event_loop, this);
}

void EventManager::stop() {
  _running.clear();
  _running.notify_all();
  if (_monitor.joinable()) {
    _monitor.join();
  }
}

std::optional<Event> EventManager::poll_event() {
  std::lock_guard lock(_queueMutex);
  if (_eventQueue.empty()) {
    return {};
  }
  auto result{_eventQueue.front()};
  _eventQueue.pop();
  return std::optional<Event>{result};
}
} // namespace libyunpa
