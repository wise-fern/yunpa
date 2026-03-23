module;
#include <memory>
export module libyunpa:Drawable;

namespace libyunpa {
export class IDrawable {
public:
  IDrawable() = default;
  virtual ~IDrawable() = default;

  virtual void draw() const = 0;
};

export using Drawable = std::shared_ptr<IDrawable>;
} // namespace libyunpa
