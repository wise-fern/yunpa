module;
#include <format>
#include <string_view>
export module libyunpa:Positionable;
import :Drawable;
import :Point2;

namespace libyunpa {
export class Positionable : public virtual Drawable {
public:
  struct Options {
    Point2u position;
  };

private:
  Point2u _position;

protected:
  auto apply(std::string_view text) {
    return std::format("{}", text);
  }

public:
  Positionable(Point2u position = {1, 1}) : _position(position) {}

  Positionable(const Options &options) : _position(options.position) {}

  virtual ~Positionable() = 0;

  auto position(Point2u position) {
    _position = position;
  }

  [[nodiscard]]
  auto position() const {
    return _position;
  }
};

Positionable::~Positionable() = default;
} // namespace libyunpa
