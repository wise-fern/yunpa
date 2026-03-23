module;

export module libyunpa:Screen;
import :Drawable;
import :Point2;

namespace libyunpa {
export class Screen : public Drawable {
private:
  Point2u _size;

  void update_size();

public:
  Screen() = default;
  ~Screen() = default;

  void size(Point2u size);
  [[nodiscard]]
  Point2u size() const;
  void update();
};
} // namespace libyunpa
