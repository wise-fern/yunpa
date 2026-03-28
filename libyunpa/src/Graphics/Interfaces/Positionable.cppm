module;
#include <string>
export module libyunpa:Positionable;
import :Element;
import :Point2;

namespace libyunpa {
export class Positionable : public virtual Node {
public:
  struct Options {
    Point2u position{.x = 1U, .y = 1U};
    bool centered{false};
  };

private:
  Point2u _position{.x = 1, .y = 1};
  bool _centered{false};

protected:
public:
  Positionable(const Options &options);
  ~Positionable() override = 0;
  void position(Point2u position);
  [[nodiscard]]
  Point2u position() const;
  void centered(bool centered);
  [[nodiscard]]
  bool centered() const;
  std::string apply(std::string_view text);
};
} // namespace libyunpa
