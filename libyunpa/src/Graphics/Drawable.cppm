module;
#include <memory>
export module libyunpa:Drawable;

namespace libyunpa {
export class Drawable {
public:
  Drawable() = default;
  virtual ~Drawable() = default;

  virtual void draw() const = 0;
};

export using DrawablePtr = std::shared_ptr<Drawable>;
} // namespace libyunpa
