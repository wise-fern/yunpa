module;
#include <string>
#include <vector>
export module libyunpa:Screen;
import :Drawable;
import :Point2;

namespace libyunpa {
export class Screen : public IDrawable {
private:
  Point2u _size;
  std::vector<std::string> _iters;

  void update_size();

public:
  Screen() = default;
  ~Screen() = default;

  void update();
  void draw() const override;
  void size(Point2u size);
  [[nodiscard]]
  Point2u size() const;
  [[nodiscard]]
  unsigned int height() const;
  [[nodiscard]]
  unsigned int width() const;
};
} // namespace libyunpa
