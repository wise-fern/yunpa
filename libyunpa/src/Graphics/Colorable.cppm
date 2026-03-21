module;

export module libyunpa:Colorable;
import :Color;

namespace libyunpa {
export class Colorable {
private:
  Color _color;
  Color _bgColor;

public:
  Colorable(Color color = Color::WHITE, Color bgColor = Color::BLACK);
  virtual ~Colorable() = 0;

  void color(Color color);
  [[nodiscard]]
  Color color() const;
  void bgColor(Color color);
  [[nodiscard]]
  Color bgColor() const;
};
} // namespace libyunpa
