module;
#include <string>
#include <string_view>
export module libyunpa:Positionable;
import :Element;
import :Point2;

namespace libyunpa {
export class Positionable : public virtual Element {
public:
  struct Options {
    Point2u position;
  };

private:
  Point2u _position;

protected:
  std::string apply(std::string_view text);

public:
  Positionable(Point2u position = {1, 1});
  Positionable(const Options &options);
  virtual ~Positionable() = 0;
  void position(Point2u position);
  [[nodiscard]]
  Point2u position() const;
};
} // namespace libyunpa
