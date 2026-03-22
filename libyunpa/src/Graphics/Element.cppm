module;
#include <iostream>
#include <memory>
export module libyunpa:Element;
import :Drawable;

namespace libyunpa {
export class Node : public virtual Drawable {
private:
  std::string _output;

protected:
  auto output(std::string_view output) {
    _output = output;
  }

  virtual void calculate_output() = 0;

public:
  virtual ~Node() = 0;

  void draw() const override {
    std::cout << _output;
  }
};

Node::~Node() = default;
export using Element = std::shared_ptr<Node>;
} // namespace libyunpa
