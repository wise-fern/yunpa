module;
#include <cstdint>
#include <format>
#include <iostream>
export module libyunpa:Terminal;

namespace libyunpa {
export enum class DecMode : std::uint16_t {
  APPLICATION_CURSOR_KEYS = 1,
  SMOOTH_SCROLL_MODE = 4,
  AUTO_REPEAT_KEYS = 8,
  SHOW_CURSOR = 25,
  APPLICATION_KEYPAD_MODE = 66,
  ALL_MOTION_MOUSE = 1003,
  ENABLE_FOCUS_EVENTS = 1004,
  SGR_MOUSE_MODE = 1006,
  WIN32_INPUT_MODE = 9001
};

export auto DECSET(DecMode mode) {
  std::cout << std::format("\x1b[?{}h", static_cast<int>(mode));
}

export auto DECRST(DecMode mode) {
  std::cout << std::format("\x1b[?{}l", static_cast<int>(mode));
}
} // namespace libyunpa
