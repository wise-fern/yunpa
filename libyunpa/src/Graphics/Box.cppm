module;
#include <string>
#include <vector>
export module libyunpa:Box;
import :Colorable;
import :Drawable;
import :Element;
import :Positionable;
import :Sizable;

namespace libyunpa {
export class Box : public Colorable, public Positionable, public Sizable {
public:
  struct Options : public Colorable::Options,
                   public Positionable::Options,
                   public Sizable::Options {
    std::string header;
  };

private:
  std::string _header;
  std::vector<Element> _children;

  void calculate_dimensions();

protected:
  void calculate_output() override;

public:
  Box(const Options &options);
  void header(std::string_view header);
  [[nodiscard]]
  std::string_view header() const;
  void draw() const override;
};
} // namespace libyunpa
