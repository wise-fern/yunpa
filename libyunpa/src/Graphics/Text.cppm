module;
#include <string>
export module libyunpa:Text;
import :Colorable;
import :Positionable;

namespace libyunpa {
export class Text : public Colorable, public Positionable {
public:
  struct Options : public Colorable::Options, public Positionable::Options {
    std::string text;
  };

private:
  std::string _text;

protected:
  void update() override;

public:
  Text(const Options &options);
  [[nodiscard]]
  std::string_view text() const;
  void text(std::string_view text);
};
} // namespace libyunpa
