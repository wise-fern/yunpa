module;
#include <string_view>
export module libyunpa:Colorable;
import :Element;
import :Color;

namespace libyunpa {
export class Colorable : public virtual Node {
public:
  struct Options {
    Color color{Color::WHITE};
    Color bgColor{Color::BLACK};
  };

private:
  Color _color;
  Color _bgColor;

protected:
  std::string apply(std::string_view text);

public:
  Colorable(Color color = Color::WHITE, Color bgColor = Color::BLACK);
  Colorable(const Options &options);
  virtual ~Colorable() = 0;
  void color(Color color);
  [[nodiscard]]
  Color color() const;
  void bgColor(Color color);
  [[nodiscard]]
  Color bgColor() const;
};
} // namespace libyunpa
