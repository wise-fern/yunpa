module;
#include <string_view>
export module libyunpa:Colorable;
import :Drawable;
import :Color;

namespace libyunpa {
export class Colorable : public virtual Drawable {
public:
  struct Options {
    Color color{Color::WHITE};
    Color bgColor{Color::BLACK};
  };

private:
  Color _color;
  Color _bgColor;

protected:
  auto apply(std::string_view text) {
    return _color.apply(_bgColor.apply(text, true));
  }

public:
  Colorable(Color color = Color::WHITE, Color bgColor = Color::BLACK)
      : _color(color), _bgColor(bgColor) {}

  Colorable(const Options &options)
      : Colorable(options.color, options.bgColor) {}

  virtual ~Colorable() = 0;

  auto color(Color color) {
    _color = color;
  }

  [[nodiscard]]
  auto color() const {
    return _color;
  }

  auto bgColor(Color color) {
    _bgColor = color;
  }

  [[nodiscard]]
  auto bgColor() const {
    return _bgColor;
  }
};

Colorable::~Colorable() = default;
} // namespace libyunpa
