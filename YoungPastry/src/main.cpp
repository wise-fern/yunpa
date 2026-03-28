import libyunpa;
import YoungPastry;
#include <memory>

int main() {
  using libyunpa::Core;
  using namespace YoungPastry;
  Core::Init();
  auto title{std::make_shared<Scenes::Title>()};
  Core::SetNextScene(title);
  Core::Run();
}
