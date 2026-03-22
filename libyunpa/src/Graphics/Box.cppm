module;
#include <string>
#include <string_view>
export module libyunpa:Box;
import :Drawable;

namespace libyunpa {
export class Box : public Drawable {
public:
  struct Options : public Drawable::Options {
    std::string header;
  };

private:
  std::string _header;

protected:
  void calculate_output() override;

public:
  Box(const Options &options);
  ~Box() = default;
  void header(std::string_view header);
  std::string header() const;
  void draw() const override;
};
} // namespace libyunpa
