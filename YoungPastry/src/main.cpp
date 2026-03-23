import libyunpa;
import YoungPastry;
#include <iostream>
#include <memory>

int main() {
  using namespace YoungPastry;
  using libyunpa::Core;
  Core::Init();
  auto title{std::make_shared<Scenes::Title>()};
  Core::SetNextScene(title);
  Core::Run();
  std::cout << "Hello world!\n";
}
