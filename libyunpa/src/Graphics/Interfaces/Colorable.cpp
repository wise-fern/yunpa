module;
#include <string>
#include <string_view>
module libyunpa;
import :Colorable;

namespace libyunpa {
Colorable::~Colorable() = default;

Colorable::Colorable(Color color, Color bgColor)
    : _color(color), _bgColor(bgColor) {}

Colorable::Colorable(const Options &options)
    : Colorable(options.color, options.bgColor) {}

std::string Colorable::apply(std::string_view text) {
  return _bgColor.apply(_color.apply(text), true);
}

void Colorable::color(Color color) {
  _color = color;
  update();
}

Color Colorable::color() const {
  return _color;
}

void Colorable::bg_color(Color color) {
  _bgColor = color;
  update();
}

Color Colorable::bg_color() const {
  return _bgColor;
}
} // namespace libyunpa
