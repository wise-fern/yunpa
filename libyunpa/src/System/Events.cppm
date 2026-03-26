module;
#include <cstdint>
#include <variant>
export module libyunpa:Events;

namespace libyunpa {
export enum class Keys : std::uint8_t {
  KEY_A,
  KEY_B,
  KEY_C,
  KEY_D,
  KEY_E,
  KEY_F,
  KEY_G,
  KEY_H,
  KEY_I,
  KEY_J,
  KEY_K,
  KEY_L,
  KEY_M,
  KEY_N,
  KEY_O,
  KEY_P,
  KEY_Q,
  KEY_R,
  KEY_S,
  KEY_T,
  KEY_U,
  KEY_V,
  KEY_W,
  KEY_X,
  KEY_Y,
  KEY_Z
};

export enum class KeyMods : std::uint8_t {
  NONE = 0 << 0,
  SHIFT = 1 << 0,
  ALT = 1 << 1,
  CTRL = 1 << 2,
  CONTROL = CTRL
};

export enum class Button : std::uint8_t { NONE };

namespace Events {
export struct KeyEvent {
  bool isKeyDown;
  Keys key;
  KeyMods mods;
};

export struct FocusEvent {
  bool hasFocus;
};

export struct MouseEvent {
  unsigned int x;
  unsigned int y;
  Button button;
};
} // namespace Events

export using Event =
    std::variant<Events::KeyEvent, Events::FocusEvent, Events::MouseEvent>;
} // namespace libyunpa
