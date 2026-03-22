module;

export module libyunpa:Colorable;
import :Drawable;
import :Color;

namespace libyunpa {
export class Colorable : public Drawable {
public:
  struct Options {
    Color color{Color::WHITE};
    Color bgColor{Color::BLACK};
  };

private:
  Color _color;
  Color _bgColor;

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
