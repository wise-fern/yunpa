module;

export module libyunpa:MinSize;
import :Drawable;
import :Point2;

namespace libyunpa {
export class MinSize : public Drawable {
public:
  struct Options {
    Point2u minSize;
  };

private:
  Point2u _minSize;

public:
  MinSize(Point2u max);
  MinSize(const Options &options);
  virtual ~MinSize() = 0;

  void min_size(Point2u size);
  [[nodiscard]]
  Point2u min_size() const;
};
} // namespace libyunpa
