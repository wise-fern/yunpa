module;
#include <memory>
#include <string>
export module libyunpa:Element;
import :Drawable;
import :Point2;

namespace libyunpa {
class Node : public virtual IDrawable {
private:
  std::string _output;
  Point2u _size;

protected:
  void output(std::string_view output);
  void size(Point2u size);
  void height(unsigned int height);
  void width(unsigned int width);

public:
  void draw() const override final;
  [[nodiscard]]
  unsigned int height() const;
  [[nodiscard]]
  unsigned int width() const;
  [[nodiscard]]
  Point2u size() const;
};

export using Element = std::shared_ptr<Node>;
} // namespace libyunpa
