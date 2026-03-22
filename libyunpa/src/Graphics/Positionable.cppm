module;

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

public:
  Positionable(Point2u position = {1, 1});
  Positionable(const Options &options);
  virtual ~Positionable() = 0;

  void position(Point2u position);
  [[nodiscard]]
  Point2u position() const;
};
} // namespace libyunpa
