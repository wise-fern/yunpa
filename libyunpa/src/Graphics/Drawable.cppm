module;

export module libyunpa:Drawable;

namespace libyunpa {
export class Drawable {
public:
  Drawable() = default;
  virtual ~Drawable() = 0;
  virtual void draw() const = 0;
};
} // namespace libyunpa
