module;
#include <iostream>
module libyunpa;

namespace libyunpa {
Box::Box(const Options &options) : Drawable(options), _header(options.header) {}

void Box::draw() const {
  std::cout << output();
}

std::string Box::header() const {
  return _header;
}

void Box::header(std::string_view header) {
  _header = header;
  calculate_output();
}

void Box::calculate_output() {}
} // namespace libyunpa
