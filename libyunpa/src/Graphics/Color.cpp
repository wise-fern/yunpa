module;
#include <format>
#include <string>
#include <string_view>
module libyunpa;

namespace libyunpa {
std::string Color::apply_values(std::string_view text) {
  return std::format("{};{};{}m{}", _red, _green, _blue, text);
}

std::string Color::apply_foreground(std::string_view text) {
  // TODO implement Color::apply_foreground
  return std::format("{}", text);
}

std::string Color::apply_background(std::string_view text) {
  // TODO implement Color::apply_background
  return std::format("{}", text);
}

Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : _red(red), _green(green), _blue(blue) {}

Color::Color(Builtin color) : Color(0, 0, 0) {
  switch (color) {
  case Color::WHITE:
    _red = 255;
    _green = 255;
    _blue = 255;
    return;
  case Color::BLACK:
  default:
    break;
  }
}

std::string Color::apply(std::string_view text, bool background) {
  auto result{apply_values(text)};
  if (background) {
    return apply_background(result);
  }
  return apply_foreground(result);
}

void Color::red(unsigned char red) {
  _red = red;
}

unsigned char Color::red() const {
  return _red;
}

void Color::green(unsigned char green) {
  _green = green;
}

unsigned char Color::green() const {
  return _green;
}

void Color::blue(unsigned char blue) {
  _blue = blue;
}

unsigned char Color::blue() const {
  return _blue;
}
} // namespace libyunpa
