module;
#include <algorithm>
#include <format>
#include <string>
#include <string_view>
module libyunpa;
import :Unicode;

namespace libyunpa {
void Box::calculate_output() {
  calculate_dimensions();
  auto width{Box::width()};
  [[maybe_unused]]
  auto height{Box::height()};
  auto output_string{Positionable::apply("")};
  output_string += Chars::Box::Round::UL;
  if (_header.size() <= width - 2) {
    output_string += _header;
    for (unsigned int i = 0; i < width - 2; ++i) {
      output_string += Chars::Box::HORIZONTAL;
    }
  } else {
    output_string += _header.substr(0, width - 2);
  }
  output_string += Chars::Box::Round::UR;
  auto pos{position()};
  for (unsigned int i = 1; i < height - 1; ++i) {
    output_string += std::format("\x1b[{0};{1}H{3}\x1b[{0};{2}H{3}",
                                 pos.y + i,
                                 pos.x,
                                 pos.x + Box::width() - 1,
                                 Chars::Box::VERTICAL);
  }
  output_string += std::format("\x1b[{0};{1}H{2}",
                               pos.y + Box::height() - 1,
                               pos.x,
                               Chars::Box::Round::LL);
  for (unsigned int i = 0; i < Box::width() - 2; ++i) {
    output_string += Chars::Box::HORIZONTAL;
  }
  output_string += Chars::Box::Round::LR;
  output(Colorable::apply(output_string));
}

void Box::calculate_dimensions() {
  auto calcHeight{2u};
  auto calcWidth{0u};
  for (const auto &child : _children) {
    calcHeight += child->height();
    calcWidth = std::max(calcWidth, child->width());
  }
  calcHeight += 2;
  calcHeight = std::max(min_size().y, calcHeight);
  calcHeight = std::min(max_size().y, calcHeight);
  height(calcHeight);
  calcWidth += 2;
  calcWidth =
      std::max(static_cast<unsigned int>(_header.size()) + 2, calcWidth);
  calcWidth = std::max(min_size().x, calcWidth);
  calcWidth = std::min(max_size().x, calcWidth);
  width(calcWidth);
}

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
