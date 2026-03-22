module;

module libyunpa;

namespace libyunpa {
MinSize::MinSize(Point2u max) : _minSize(max) {}

MinSize::MinSize(const Options &options) : _minSize(options.minSize) {}

void MinSize::min_size(Point2u size) {
  _minSize = size;
  calculate_output();
}

Point2u MinSize::min_size() const {
  return _minSize;
}

MinSize::~MinSize() = default;
} // namespace libyunpa
