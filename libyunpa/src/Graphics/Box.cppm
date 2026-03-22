module;
#include <string>
#include <vector>
export module libyunpa:Box;
import :Colorable;
import :Drawable;
import :Positionable;
import :Sizable;

namespace libyunpa {
class Box : public Colorable, public Positionable, public Sizable {
public:
  struct Options : public Colorable::Options,
                   public Positionable::Options,
                   public Sizable::Options {
    std::string header;
  };

private:
  std::string _header;
  std::vector<DrawablePtr> _children;

public:
  Box(const Options &options)
      : MinSize(options), MaxSize(options), Colorable(options),
        Positionable(options) {}

  auto header(std::string_view header) {
    _header = header;
  }

  [[nodiscard]]
  auto header() const {
    return std::string_view{_header};
  }

  void draw() const override {
    for (const auto &child : _children) {
      child->draw();
    }
    Node::draw();
  }
};
} // namespace libyunpa
