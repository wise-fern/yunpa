module;
#include <string_view>
module libyunpa;
import :Text;

namespace libyunpa {
Text::Text(const Options &options) : Colorable(options), _text(options.text) {
  update();
}

std::string_view Text::text() const {
  return _text;
}

void Text::text(std::string_view text) {
  _text = text;
}

void Text::update() {
  output(Colorable::apply(_text));
}
} // namespace libyunpa
