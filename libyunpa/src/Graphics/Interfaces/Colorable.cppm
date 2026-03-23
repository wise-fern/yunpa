module;
#include <string>
export module libyunpa:Colorable;
import :Element;
import :Color;

namespace libyunpa {
export class Colorable : public virtual Node {
private:
  Color _color;
  Color _bgColor;

public:
  Colorable(Color color = Color::WHITE, Color bgColor = Color::BLACK);
  virtual ~Colorable() = 0;
  std::string apply(std::string_view text);
  void color(Color color);
  [[nodiscard]]
  Color color() const;
  void bg_color(Color color);
  [[nodiscard]]
  Color bg_color() const;
};
} // namespace libyunpa
