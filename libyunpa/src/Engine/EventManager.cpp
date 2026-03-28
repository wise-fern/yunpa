module;
#include <functional>
#include <optional>
#include <queue>
#include <tao/pegtl.hpp>

#ifdef WIN32
#include <conio.h>
#include <windows.h>
#else
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>
#endif
module libyunpa;
import :EventManager;
import :Terminal;
#ifndef WIN32
// NOLINTNEXTLINE(bugprone-reserved-identifier)
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

libyunpa::Keys ConvertMSVK(int virtualKey) {
  // TODO implement converting MS virtual keys
#ifndef WIN32
  (void)virtualKey;
  return libyunpa::Keys::KEY_A;
#else
  switch (virtualKey) {
    using enum libyunpa::Keys;
  case VK_DELETE:
    return KEY_DELETE;
  case VK_INSERT:
    return KEY_INSERT;
  case VK_HOME:
    return KEY_HOME;
  case VK_END:
    return KEY_END;
  case VK_PRIOR:
    return KEY_PAGE_UP;
  case VK_NEXT:
    return KEY_PAGE_DOWN;
  case VK_UP:
    return KEY_ARROW_UP;
  case VK_RIGHT:
    return KEY_ARROW_RIGHT;
  case VK_DOWN:
    return KEY_ARROW_DOWN;
  case VK_LEFT:
    return KEY_ARROW_LEFT;
  case 'A':
    return KEY_A;
  case 'B':
    return KEY_B;
  case 'C':
    return KEY_C;
  case 'D':
    return KEY_D;
  case 'E':
    return KEY_E;
  case 'F':
    return KEY_F;
  case 'G':
    return KEY_G;
  case 'H':
    return KEY_H;
  case 'I':
    return KEY_I;
  case 'J':
    return KEY_J;
  case 'K':
    return KEY_K;
  case 'L':
    return KEY_L;
  case 'M':
    return KEY_M;
  case 'N':
    return KEY_N;
  case 'O':
    return KEY_O;
  case 'P':
    return KEY_P;
  case 'Q':
    return KEY_Q;
  case 'R':
    return KEY_R;
  case 'S':
    return KEY_S;
  case 'T':
    return KEY_T;
  case 'U':
    return KEY_U;
  case 'V':
    return KEY_V;
  case 'W':
    return KEY_W;
  case 'X':
    return KEY_X;
  case 'Y':
    return KEY_Y;
  case 'Z':
    return KEY_Z;
  default:
    return libyunpa::Keys::KEY_A;
  }
#endif
}

libyunpa::KeyMods ConvertMSCK([[gnu::unused]] int controlKeys) {
  // TODO implement converting MS control keys
#ifndef WIN32
  return libyunpa::KeyMods::NONE;
#else
  return libyunpa::KeyMods::NONE;
#endif
}

using EnqueueCallback = std::function<void(libyunpa::Event)>;

template <typename Rule> struct Action {
  template <typename ActionInput>
  static void apply([[gnu::unused]] const ActionInput &actionInput,
                    [[gnu::unused]] const EnqueueCallback &callback) {}
};

template <> struct Action<Grammar::Win32InputString> {
  template <typename ActionInput>
  static void apply(const ActionInput &actionInput,
                    const EnqueueCallback &callback) {
    std::string input{actionInput.string()};
    input = input.substr(2);
    auto vKeyCode{ConvertAndTrim(input)};
    [[gnu::unused]]
    auto vScanCode{ConvertAndTrim(input)};
    [[gnu::unused]]
    auto uniChar{ConvertAndTrim(input)};
    auto keyDown{ConvertAndTrim(input) == 1};
    auto controlKeys{ConvertAndTrim(input)};
    libyunpa::Events::KeyEvent event{.isKeyDown = keyDown,
                                     .key = ConvertMSVK(vKeyCode),
                                     .mods = ConvertMSCK(controlKeys)};
    callback(event);
  }
};

template <> struct Action<Grammar::FocusEvent> {
  template <typename ActionInput>
  static void apply(const ActionInput &actionInput,
                    const EnqueueCallback &callback) {
    libyunpa::Events::FocusEvent event{};
    std::string input{actionInput.string()};
    event.hasFocus = input.find('O') == std::string::npos;
    callback(event);
  }
};

namespace libyunpa {
EventManager::EventManager() {
#ifdef WIN32
  auto *handle{GetStdHandle(STD_INPUT_HANDLE)};
  DWORD mode = (ENABLE_PROCESSED_INPUT bitor ENABLE_WINDOW_INPUT bitor
                ENABLE_MOUSE_INPUT bitor ENABLE_EXTENDED_FLAGS bitor
                ENABLE_VIRTUAL_TERMINAL_INPUT) bitand
               compl(ENABLE_QUICK_EDIT_MODE bitor ENABLE_ECHO_INPUT);
  SetConsoleMode(handle, mode);
  mode = (ENABLE_PROCESSED_OUTPUT bitor DISABLE_NEWLINE_AUTO_RETURN bitor
          ENABLE_VIRTUAL_TERMINAL_PROCESSING);
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleMode(handle, mode);
#endif
  DECSET(DecMode::WIN32_INPUT_MODE);
  DECRST(DecMode::SHOW_CURSOR);
}

void EventManager::update() {
  std::string working_string;
  while (_kbhit() not_eq 0) {
    auto input{_getch()};
    working_string += static_cast<char>(input);
    tao::pegtl::memory_input parser_input{working_string, ""};
    auto callback = [&](Event event) {
      _eventQueue.push(event);
    };
    if (tao::pegtl::parse<Grammar::Language, Action>(parser_input, callback)) {
      working_string.clear();
    }
  }
}

std::optional<Event> EventManager::poll_event() {
  if (_eventQueue.empty()) {
    return {};
  }
  auto result{_eventQueue.front()};
  _eventQueue.pop();
  return std::optional<Event>{result};
}
} // namespace libyunpa
