module;
#include <string> // IWYU pragma: keep
#include <string_view>
export module libyunpa:Color;

namespace libyunpa {
export class Color {
public:
  enum Builtin { BLACK, BLUE, GREEN, RED, WHITE };

private:
  unsigned char _red;
  unsigned char _green;
  unsigned char _blue;

  std::string apply_values(std::string_view text);
  std::string apply_foreground(std::string_view text);
  std::string apply_background(std::string_view text);

public:
  Color(unsigned char red, unsigned char green, unsigned char blue);
  Color(Builtin color);

  std::string apply(std::string_view text, bool background = false);
  void red(unsigned char red);
  [[nodiscard]]
  unsigned char red() const;
  void green(unsigned char green);
  [[nodiscard]]
  unsigned char green() const;
  void blue(unsigned char blue);
  [[nodiscard]]
  unsigned char blue() const;
};
} // namespace libyunpa
