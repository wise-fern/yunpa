module;
#include <string>
export module libyunpa:Colorable;
import :Drawable;
import :Color;

namespace libyunpa {
export class IColorable : public virtual Drawable {
private:
  Color _color;
  Color _bgColor;

public:
  IColorable(Color color = Color::WHITE, Color bgColor = Color::BLACK);
  virtual ~IColorable() = 0;
  std::string apply(std::string_view text);
};
} // namespace libyunpa
