module;
#include <format>
#include <string>
#include <string_view>
module libyunpa;

namespace libyunpa {
Color::Color(unsigned char red, unsigned char green, unsigned char blue)
    : _red(red), _green(green), _blue(blue) {}

Color::Color(Builtin color) : Color(0, 0, 0) {
  switch (color) {
  case BLUE:
    _blue = 255;
    break;
  case GREEN:
    _green = 255;
    break;
  case RED:
    _red = 255;
    break;
  case WHITE:
    _red = 255;
    _green = 255;
    _blue = 255;
    break;
  case BLACK:
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

std::string Color::apply_values(std::string_view text) {
  return std::format("{}", text);
}

std::string Color::apply_foreground(std::string_view text) {
  return std::format("{}", text);
}

std::string Color::apply_background(std::string_view text) {
  return std::format("{}", text);
}
} // namespace libyunpa
