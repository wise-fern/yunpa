module;

module libyunpa;

namespace libyunpa {
MaxSize::MaxSize(Point2u max) : _size(max) {}

MaxSize::MaxSize(const Options &options) : _size(options.maxSize) {}

void MaxSize::max_size(Point2u size) {
  _size = size;
}

Point2u MaxSize::max_size() const {
  return _size;
}

MaxSize::~MaxSize() = default;
} // namespace libyunpa
