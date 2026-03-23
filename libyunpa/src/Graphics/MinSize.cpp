module;

module libyunpa;

namespace libyunpa {
MinSize::MinSize(Point2u min) : _size(min) {}

MinSize::MinSize(const Options &options) : _size(options.minSize) {}

void MinSize::min_size(Point2u size) {
  _size = size;
}

Point2u MinSize::min_size() const {
  return _size;
}

MinSize::~MinSize() = default;
} // namespace libyunpa
