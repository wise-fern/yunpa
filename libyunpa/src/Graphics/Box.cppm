module;
#include <string>
export module libyunpa:Box;
import :Colorable;
import :Positionable;
import :Sizable;

namespace libyunpa {
class Box : public Colorable, public Positionable, public Sizable {
public:
  struct Options : public Colorable::Options,
                   public Positionable::Options,
                   public Sizable::Options {
    std::string header;
  };

private:
  std::string _header;

public:
  Box(const Options &options);

  void header(std::string_view header);
  [[nodiscard]]
  std::string_view header() const;
};
} // namespace libyunpa
