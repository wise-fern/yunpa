module;
#include <string> // IWYU pragma: keep
export module libyunpa:Unicode;

namespace libyunpa {
using namespace std::string_literals;

namespace Chars {
namespace Box {
const auto HORIZONTAL{"─"s};
const auto VERTICAL{"│"s};

namespace Round {
const auto UL{"╭"s};
const auto UR{"╮"s};
const auto LL{"╯"s};
const auto LR{"╰"s};
} // namespace Round

namespace Sharp {
const auto UL{"┌"s};
const auto UR{"┐"s};
const auto LL{"└"s};
const auto LR{"┘"s};

} // namespace Sharp
} // namespace Box
} // namespace Chars
} // namespace libyunpa
