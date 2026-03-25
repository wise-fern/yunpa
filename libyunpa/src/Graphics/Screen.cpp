module;
#ifdef WIN32
#include <windows.h>
#else
#include <stdexcept>
#include <sys/ioctl.h>
#include <unistd.h>
#endif
#include <iostream>
module libyunpa;
import :Screen;

namespace libyunpa {
void Screen::size(Point2u size) {
  _size = size;
}

Point2u Screen::size() const {
  return _size;
}

void Screen::update() {
  update_size();
}

void Screen::draw() const {
  for (const auto &iter : _iters) {
    std::cout << iter;
  }
}

void Screen::update_size() {
#ifdef WIN32
  // NOLINTBEGIN
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
    _size = {
        static_cast<unsigned int>(csbi.srWindow.Right - csbi.srWindow.Left + 1),
        static_cast<unsigned int>(csbi.srWindow.Bottom - csbi.srWindow.Top +
                                  1)};
  }
  // NOLINTEND
#else
  winsize w{};
  const int status{ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)};
  if (w.ws_col == 0 or w.ws_row == 0 or status < 0) {
    throw std::runtime_error("Couldn't get the dimensions");
  };
  _size = {w.ws_col, w.ws_row};
#endif
}
} // namespace libyunpa
