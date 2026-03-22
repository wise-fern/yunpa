module;
#include <iostream>
module libyunpa;

namespace libyunpa {
Drawable::~Drawable() = default;

void Drawable::draw() const {
  std::cout << _output;
}
} // namespace libyunpa
