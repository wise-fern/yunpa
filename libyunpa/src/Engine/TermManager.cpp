module;
#include <format>
#include <iostream>
#include <utility>
module libyunpa;

namespace libyunpa {
void TermManager::DECSET(Modes mode) {
  std::cout << std::format("\x1b[?{}h", static_cast<int>(mode));
}
} // namespace libyunpa
