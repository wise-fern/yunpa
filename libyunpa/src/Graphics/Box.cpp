module;
#include <string_view>
module libyunpa;

namespace libyunpa {
void Box::calculate_output() {}

Box::Box(const Options &options)
    : MinSize(options), MaxSize(options), Colorable(options),
      Positionable(options) {}

void Box::header(std::string_view header) {
  _header = header;
}

std::string_view Box::header() const {
  return _header;
}

void Box::draw() const {
  for (const auto &child : _children) {
    child->draw();
  }
  Node::draw();
}
} // namespace libyunpa
