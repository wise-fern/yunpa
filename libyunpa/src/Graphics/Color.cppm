module;
#include <cstdint>
#include <string>
#include <string_view>
export module libyunpa:Color;

namespace libyunpa {
export class Color {
public:
  enum Builtin : std::uint8_t {
    AQUA,
    BLACK,
    BLUE,
    FUCHSIA,
    GRAY,
    GREY = GRAY,
    GREEN,
    LIME,
    MAROON,
    NAVY,
    RED,
    SILVER,
    YELLOW,
    WHITE
  };

private:
  unsigned char _red;
  unsigned char _green;
  unsigned char _blue;

  [[nodiscard]]
  std::string apply_foreground(std::string_view text);
  [[nodiscard]]
  std::string apply_background(std::string_view text);
  [[nodiscard]]
  std::string apply_values(std::string_view text);

public:
  Color(unsigned char red, unsigned char green, unsigned char blue);
  Color(Builtin name);
  void red(unsigned char red);
  [[nodiscard]]
  unsigned char red() const;
  void green(unsigned char green);
  [[nodiscard]]
  unsigned char green() const;
  void blue(unsigned char blue);
  [[nodiscard]]
  unsigned char blue() const;
  [[nodiscard]]
  std::string apply(std::string_view text, bool background = false);
};
} // namespace libyunpa
