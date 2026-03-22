module;

export module libyunpa:Positionable;
import :Point2;

namespace libyunpa {
export class Positionable {
private:
  Point2u _position;

public:
  Positionable(Point2u position);
  ~Positionable() = default;

  void position(Point2u position);
  [[nodiscard]]
  Point2u position() const;
};
} // namespace libyunpa
