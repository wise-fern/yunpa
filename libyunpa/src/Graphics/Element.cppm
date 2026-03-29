module;
#include <memory>
#include <string>
#include <string_view>
export module libyunpa:Element;
import :Drawable;
import :Point2;

namespace libyunpa {
// NOLINTNEXTLINE(misc-include-cleaner)
export class Node : public virtual IDrawable {
private:
  std::string _output;
  // NOLINTNEXTLINE(misc-include-cleaner)
  Point2u _size;

protected:
  void output(std::string_view output);
  void size(Point2u size);
  void height(unsigned int height);
  void width(unsigned int width);

public:
  virtual void update() = 0;
  void draw() const final;
  [[nodiscard]]
  unsigned int height() const;
  [[nodiscard]]
  unsigned int width() const;
  [[nodiscard]]
  Point2u size() const;
  [[nodiscard]]
  std::string output() const;
};

export using Element = std::shared_ptr<Node>;
} // namespace libyunpa
