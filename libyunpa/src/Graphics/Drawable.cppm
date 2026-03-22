module;
#include <iostream>
#include <memory>
#include <string>
export module libyunpa:Drawable;
import :Color;
import :Point2;

namespace libyunpa {
export class Drawable {
private:
  std::string _output;

protected:
  virtual void calculate_output() = 0;

  auto output(std::string_view output) {
    _output = output;
  }

  auto output() const {
    return _output;
  }

public:
  Drawable() = default;
  virtual ~Drawable() = default;

  virtual void draw() const {
    std::cout << _output;
  }
};

export using DrawablePtr = std::shared_ptr<Drawable>;
} // namespace libyunpa
