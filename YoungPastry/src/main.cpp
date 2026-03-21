import libyunpa;
import YoungPastry;
#include <memory>

int main() {
  using namespace YoungPastry;
  using libyunpa::Core;
  Core::Init();
  auto title{std::make_shared<Scenes::Title>()};
  Core::SetNextScene(title);
  Core::Run();
}
