module;

export module libyunpa:Sizable;
import :MaxSize;
import :MinSize;

namespace libyunpa {
export class Sizable : public virtual MinSize, public virtual MaxSize {
public:
  struct Options : public MinSize::Options, public MaxSize::Options {};

private:
public:
  Sizable() = default;
  virtual ~Sizable() = 0;
};

Sizable::~Sizable() = default;
} // namespace libyunpa
