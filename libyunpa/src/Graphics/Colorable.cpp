module;

module libyunpa;

namespace libyunpa {
Colorable::Colorable(Color color, Color bgColor)
    : _color(color), _bgColor(bgColor) {}

Colorable::Colorable(const Options &options)
    : _color(options.color), _bgColor(options.bgColor) {}

void Colorable::color(Color color) {
  _color = color;
  calculate_output();
}

Color Colorable::color() const {
  return _color;
}

void Colorable::bgColor(Color color) {
  _bgColor = color;
  calculate_output();
}

Colorable::~Colorable() = default;
} // namespace libyunpa
