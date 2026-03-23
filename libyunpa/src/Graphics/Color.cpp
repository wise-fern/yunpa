module;
#include <format>
#include <string>
#include <string_view>
module libyunpa;
import :Color;

namespace libyunpa {
void Color::red(unsigned char red) {
  _red = red;
}

void Color::green(unsigned char green) {
  _green = green;
}

void Color::blue(unsigned char blue) {
  _blue = blue;
}

unsigned char Color::red() const {
  return _red;
}

unsigned char Color::green() const {
  return _green;
}

unsigned char Color::blue() const {
  return _blue;
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : _red(red), _green(green), _blue(blue) {}

Color::Color(Builtin name) : Color(0, 0, 0) {
  switch (name) {
  case WHITE:
    _red = _green = _blue = 0xFF;
    break;
  case RED:
    _red = 0xFF;
    break;
  case GREEN:
    _green = 0x80;
    break;
  case LIME:
    _green = 0xFF;
    break;
  case NAVY:
    _blue = 0x80;
    break;
  case BLUE:
    _blue = 0xFF;
    break;
  case YELLOW:
    _red = _green = 0xFF;
    break;
  case AQUA:
    _green = _blue = 0xFF;
    break;
  case FUCHSIA:
    _red = _blue = 0xFF;
    break;
  case SILVER:
    _red = _green = _blue = 0xC0;
    break;
  case GRAY:
    _red = _green = _blue = 0x80;
    break;
  case BLACK:
  default:
    break;
  }
}

std::string Color::apply_foreground(std::string_view text) {
  return std::format("\x1b[38;2;{}\x1b[39m", text);
}

std::string Color::apply_background(std::string_view text) {
  return std::format("\x1b[48;2;{}\x1b[49m", text);
}

std::string Color::apply_values(std::string_view text) {
  return std::format("{};{};{}m{}", _red, _green, _blue, text);
}

std::string Color::apply(std::string_view text, bool background) {
  auto result{apply_values(text)};
  if (background) {
    return apply_background(result);
  }
  return apply_foreground(result);
}
} // namespace libyunpa
