module;

module libyunpa;

namespace libyunpa {
Positionable::Positionable(Point2u position) : _position(position) {}

Positionable::Positionable(const Options &options)
    : _position(options.position) {}

void Positionable::position(Point2u position) {
  _position = position;
}

Point2u Positionable::position() const {
  return _position;
}

Positionable::~Positionable() = default;
} // namespace libyunpa
