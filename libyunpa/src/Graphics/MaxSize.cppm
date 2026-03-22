module;

export module libyunpa:MaxSize;
import :Drawable;
import :Point2;

namespace libyunpa {
export class MaxSize : public virtual Drawable {
public:
  struct Options {
    Point2u maxSize;
  };

private:
  Point2u _size;

public:
  MaxSize(Point2u max) : _size(max) {}

  MaxSize(const Options &options) : _size(options.maxSize) {}

  virtual ~MaxSize() = 0;

  auto max_size(Point2u size) {
    _size = size;
  }

  [[nodiscard]]
  auto max_size() const {
    return _size;
  }
};

MaxSize::~MaxSize() = default;
} // namespace libyunpa
