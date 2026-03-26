import libyunpa;
import YoungPastry;
#include <memory>

int main() {
  using libyunpa::Core;
  using namespace YoungPastry;
  auto title{std::make_shared<Scenes::Title>()};
  Core::Init();
  Core::SetNextScene(title);
  Core::Run();
}
