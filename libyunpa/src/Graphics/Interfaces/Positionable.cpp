module;
#include <format>
#include <string>
#include <string_view>
module libyunpa;

namespace libyunpa {
Positionable::~Positionable() = default;

Positionable::Positionable(const Options &options)
    : _position(options.position) {}

void Positionable::position(Point2u position) {
  _position = position;
  update();
}

Point2u Positionable::position() const {
  return _position;
}

std::string Positionable::apply(std::string_view text) {
  return std::format("\x1b[{};{}H{}", _position.y, _position.x, text);
}

bool Positionable::centered() const {
  return _centered;
}

void Positionable::centered(bool centered) {
  _centered = centered;
}
} // namespace libyunpa
