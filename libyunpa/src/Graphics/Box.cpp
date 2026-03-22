module;
#include <string_view>
module libyunpa;

namespace libyunpa {
Box::Box(const Options &options)
    : Colorable(options), Positionable(options), Sizable(options) {}

void Box::header(std::string_view header) {
  _header = header;
}

std::string_view Box::header() const {
  return _header;
}
} // namespace libyunpa
