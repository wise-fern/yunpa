module;
#include <string>
export module libyunpa:Drawable;

namespace libyunpa {
export class Drawable {
private:
  std::string _output;

protected:
  virtual void calculate_output() = 0;

public:
  Drawable() = default;
  virtual ~Drawable() = 0;
  virtual void draw() const;
};
} // namespace libyunpa
