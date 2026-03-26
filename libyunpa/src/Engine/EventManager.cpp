module;
#include <atomic>
#include <functional>
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

namespace Grammar {
using namespace tao::pegtl;

struct ESC : one<'\x1b'> {};

struct CSI : seq<ESC, one<'['>> {};

struct OSC : seq<ESC, one<']'>> {};

struct ST : seq<ESC, one<'\\'>> {};

template <char... delim>
struct DigitPlusTerm : seq<plus<digit>, one<delim...>> {};

using DigitPlusSemi = DigitPlusTerm<';'>;

struct Win32InputString : seq<CSI,
                              DigitPlusSemi,
                              DigitPlusSemi,
                              DigitPlusSemi,
                              DigitPlusSemi,
                              DigitPlusSemi,
                              DigitPlusTerm<'_'>> {};

struct FocusEvent : seq<CSI, one<'I', 'O'>> {};

struct SGRMouse : seq<CSI,
                      one<'<'>,
                      DigitPlusSemi,
                      DigitPlusSemi,
                      DigitPlusTerm<'M', 'm'>> {};

struct Language : sor<Win32InputString, FocusEvent, SGRMouse> {};
} // namespace Grammar

auto ConvertAndTrim(std::string &input, char delim = ';') {
  auto count{input.find(delim)};
  auto result{std::stoi(input.substr(0, count))};
  input.erase(0, ++count);
  return result;
}

using EnqueueCallback = std::function<void(libyunpa::Event)>;

template <typename Rule> struct Action {
  template <typename ActionInput>
  static void apply([[maybe_unused]] const ActionInput &actionInput,
                    [[maybe_unused]] const EnqueueCallback &callback) {}
};

template <> struct Action<Grammar::Win32InputString> {
  template <typename ActionInput>
  static void apply([[maybe_unused]] const ActionInput &actionInput,
                    [[maybe_unused]] const EnqueueCallback &callback) {
    // TODO Create KeyEvent from Win32 input string
  }
};

template <> struct Action<Grammar::FocusEvent> {
  template <typename ActionInput>
  static void apply([[maybe_unused]] const ActionInput &actionInput,
                    [[maybe_unused]] const EnqueueCallback &callback) {
    // TODO Create FocusEvent from input
  }
};

namespace libyunpa {
void EventManager::event_loop() {
  while (_running.test()) {
    std::string working_string;
    while (_kbhit() not_eq 0) {
      auto input{std::cin.get()};
      working_string += static_cast<char>(input);
      auto parser_input = tao::pegtl::memory_input(working_string, "");
      if (tao::pegtl::parse<Grammar::Language, Action>(parser_input,
                                                       [&](Event event) {
                                                         enqueue_event(event);
                                                       })) {
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
