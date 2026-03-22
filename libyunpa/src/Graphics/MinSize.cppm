module;

export module libyunpa:MinSize;
import :Element;
import :Point2;

namespace libyunpa {
export class MinSize : public virtual Element {
public:
  struct Options {
    Point2u minSize;
  };

private:
  Point2u _size;

public:
  MinSize(Point2u min) : _size(min) {}

  MinSize(const Options &options) : _size(options.minSize) {};
  virtual ~MinSize() = 0;

  auto min_size(Point2u size) {
    _size = size;
  }

  [[nodiscard]]
  auto min_size() const {
    return _size;
  }
};

MinSize::~MinSize() = default;
} // namespace libyunpa
