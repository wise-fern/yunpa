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
  MinSize(Point2u min);
  MinSize(const Options &options);
  virtual ~MinSize() = 0;
  void min_size(Point2u size);
  [[nodiscard]]
  Point2u min_size() const;
};
} // namespace libyunpa
