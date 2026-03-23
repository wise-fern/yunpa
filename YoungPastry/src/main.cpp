import libyunpa;
import YoungPastry;
#include <iostream>

int main() {
  libyunpa::Text::Options options{};
  options.text = "Hello, World!";
  options.color = libyunpa::Color::AQUA;
  options.bgColor = libyunpa::Color::MAROON;
  options.position = {31, 10};
  auto test{libyunpa::Text{options}};
  options.blink = true;
  options.position.y = 11;
  auto test2{libyunpa::Text{options}};
  std::cout << "\x1b[?1049h";
  test.draw();
  test2.draw();
  std::cout << '\n';
  std::string input;
  std::cin >> input;
  std::cout << "\x1b[?1049l";
}
