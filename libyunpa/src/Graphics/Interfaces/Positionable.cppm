module;
#include <string>
export module libyunpa:Positionable;
import :Element;
import :Point2;

namespace libyunpa {
export class Positionable : public virtual Node {
public:
  struct Options {
    Point2u position{1u, 1u};
  };

private:
  Point2u _position{1, 1};

protected:
public:
  Positionable(const Options &options);
  virtual ~Positionable() = 0;
  void position(Point2u position);
  [[nodiscard]]
  Point2u position() const;
  std::string apply(std::string_view text);
};
} // namespace libyunpa
