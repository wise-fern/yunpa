module;
#include <concepts>
export module libyunpa:Point2;

namespace libyunpa {
// cppcheck-suppress syntaxError
export template <typename T>
  requires std::integral<T>
struct Point2 {
  T x;
  T y;
};

export using Piont2u = Point2<unsigned int>;
export using Point2i = Point2<int>;
} // namespace libyunpa
