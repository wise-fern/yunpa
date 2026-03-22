module;

export module libyunpa:Sizable;
import :MaxSize;
import :MinSize;

namespace libyunpa {
export class Sizable : public MinSize, public MaxSize {
public:
  struct Options : public MinSize::Options, public MaxSize::Options {};

private:
public:
  Sizable(const Options &options);
  virtual ~Sizable() = 0;
};
} // namespace libyunpa
