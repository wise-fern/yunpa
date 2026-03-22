module;
#include <iostream>
#include <string_view>
module libyunpa;

namespace libyunpa {
Drawable::Drawable(const Options &options)
    : _position(options.position), _color(options.color),
      _bgColor(options.bgColor), _minSize(options.minSize),
      _maxSize(options.maxSize) {}

Drawable::~Drawable() = default;

void Drawable::draw() const {
  std::cout << _output;
}

void Drawable::output(std::string_view output) {
  _output = output;
}

std::string Drawable::output() const {
  return _output;
}
} // namespace libyunpa
