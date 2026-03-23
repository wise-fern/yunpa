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

void Node::size(Point2u size) {
  _size = size;
}

void Node::width(unsigned int width) {
  _size.x = width;
}

void Node::height(unsigned int height) {
  _size.y = height;
}

Point2u Node::size() const {
  return _size;
}

unsigned int Node::height() const {
  return _size.y;
}

unsigned int Node::width() const {
  return _size.x;
}

Node::~Node() = default;
} // namespace libyunpa
