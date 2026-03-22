module;
#include <string>
export module libyunpa:Drawable;
import :Color;
import :Point2;

namespace libyunpa {
export class Drawable {
public:
  struct Options {
    Point2u position{1, 1};
    Color color{Color::WHITE};
    Color bgColor{Color::BLACK};
    Point2u minSize{1, 1};
    Point2u maxSize{0, 0};
  };

private:
  std::string _output;
  Point2u _position;
  Color _color;
  Color _bgColor;
  Point2u _minSize;
  Point2u _maxSize;

protected:
  virtual void calculate_output() = 0;
  void output(std::string_view output);
  std::string output() const;

public:
  Drawable(const Options &options);
  virtual ~Drawable() = 0;
  virtual void draw() const;
};
} // namespace libyunpa
