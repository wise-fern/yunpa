module;
#include <memory>
#include <string>
#include <string_view>
export module libyunpa:Element;
import :Drawable;
import :Point2;

namespace libyunpa {
export class Node : public virtual Drawable {
private:
  std::string _output;
  Point2u _size;

protected:
  void output(std::string_view output);
  virtual void calculate_output() = 0;
  void size(Point2u size);
  void width(unsigned int width);
  void height(unsigned int height);

public:
  virtual ~Node() = 0;
  void draw() const override;
  [[nodiscard]]
  Point2u size() const;
  [[nodiscard]]
  unsigned int height() const;
  [[nodiscard]]
  unsigned int width() const;
};

export using Element = std::shared_ptr<Node>;
} // namespace libyunpa
