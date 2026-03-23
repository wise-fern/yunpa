module;
#include <iostream>
module libyunpa;

namespace libyunpa {
void Node::draw() const {
  std::cout << _output;
}

void Node::output(std::string_view output) {
  _output = output;
}

Node::~Node() = default;
} // namespace libyunpa
