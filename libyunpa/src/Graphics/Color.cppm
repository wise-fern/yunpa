module;
#include <format>
#include <string_view>
export module libyunpa:Color;

namespace libyunpa {
export class Color {
public:
  enum Builtin { BLACK, BLUE, GREEN, RED, WHITE };

private:
  unsigned char _red;
  unsigned char _green;
  unsigned char _blue;

  auto apply_values(std::string_view text) {
    return std::format("{};{};{}m{}", _red, _green, _blue, text);
  }

  auto apply_foreground(std::string_view text) {
    // TODO implement Color::apply_foreground
    return std::format("{}", text);
  }

  auto apply_background(std::string_view text) {
    // TODO implement Color::apply_background
    return std::format("{}", text);
  }

public:
  Color(unsigned char red, unsigned char green, unsigned char blue)
      : _red(red), _green(green), _blue(blue) {}

  Color(Builtin color) : Color(0, 0, 0) {
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

  auto apply(std::string_view text, bool background = false) {
    auto result{apply_values(text)};
    if (background) {
      return apply_background(result);
    }
    return apply_foreground(result);
  }

  auto red(unsigned char red) {
    _red = red;
  }

  [[nodiscard]]
  auto red() const {
    return _red;
  }

  auto green(unsigned char green) {
    _green = green;
  }

  [[nodiscard]]
  auto green() const {
    return _green;
  }

  auto blue(unsigned char blue) {
    _blue = blue;
  }

  [[nodiscard]]
  auto blue() const {
    return _blue;
  }
};
} // namespace libyunpa
