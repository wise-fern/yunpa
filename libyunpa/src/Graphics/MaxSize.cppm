module;

export module libyunpa:MaxSize;
import :Element;
import :Point2;

namespace libyunpa {
export class MaxSize : public virtual Element {
public:
  struct Options {
    Point2u maxSize;
  };

private:
  Point2u _size;

public:
  MaxSize(Point2u max);
  MaxSize(const Options &options);
  virtual ~MaxSize() = 0;
  void max_size(Point2u size);
  [[nodiscard]]
  Point2u max_size() const;
};
} // namespace libyunpa
