module;
#include <string>
#include <string_view>
module libyunpa;

namespace libyunpa {
std::string Colorable::apply(std::string_view text) {
  return _color.apply(_bgColor.apply(text, true));
}

Colorable::Colorable(Color color, Color bgColor)
    : _color(color), _bgColor(bgColor) {}

Colorable::Colorable(const Options &options)
    : _color(options.color), _bgColor(options.bgColor) {}

void Colorable::color(Color color) {
  _color = color;
}

Color Colorable::color() const {
  return _color;
}

void Colorable::bgColor(Color color) {
  _bgColor = color;
}

Color Colorable::bgColor() const {
  return _bgColor;
}

Colorable::~Colorable() = default;
} // namespace libyunpa
