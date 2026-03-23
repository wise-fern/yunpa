module;
#include <string>
module libyunpa;
import :Colorable;

namespace libyunpa {
IColorable::~IColorable() = default;

IColorable::IColorable(Color color, Color bgColor)
    : _color(color), _bgColor(bgColor) {}

std::string IColorable::apply(std::string_view text) {
  return _bgColor.apply(_color.apply(text), true);
}

} // namespace libyunpa
