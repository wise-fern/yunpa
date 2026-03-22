module;

module libyunpa;

namespace libyunpa {
MaxSize::MaxSize(Point2u max) : _maxSize(max) {}

MaxSize::MaxSize(const Options &options) : _maxSize(options.maxSize) {}

void MaxSize::max_size(Point2u size) {
  _maxSize = size;
  calculate_output();
}

Point2u MaxSize::max_size() const {
  return _maxSize;
}

MaxSize::~MaxSize() = default;
} // namespace libyunpa
