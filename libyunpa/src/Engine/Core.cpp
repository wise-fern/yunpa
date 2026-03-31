module;
#include <cassert>
#include <iostream>
#include <memory>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif
module libyunpa;

namespace libyunpa {
class Core::impl final {
private:
  GameTime _gameTime;
  SceneManager _sceneMan;
  EventManager _eventMan;
  ftxui::Screen _screen{ftxui::Screen::Create(ftxui::Dimension::Full())};

  auto game_loop() {
    while (true) {
      _gameTime.update();
      _sceneMan.update(_gameTime);
      if (_sceneMan.empty()) {
        return;
      }
      while (const auto event{_eventMan.poll_event()}) {
        _sceneMan.handle_event(event.value());
      }
      _screen.Clear();
      _sceneMan.draw(_screen);
      std::cout << "\x1b[1;1H" + _screen.ToString();
    }
  }

public:
  auto run() {
    _eventMan.start();
    _gameTime.reset();
    game_loop();
    _eventMan.stop();
  }

  auto set_next_scene(ScenePtr scene) {
    _sceneMan.set_next_scene(std::move(scene));
  }

  [[nodiscard]]
  auto get_current_scene() const {
    return _sceneMan.get_current_scene();
  }

  [[nodiscard]]
  // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
  auto get_size() const {
    Point2u size;
#ifdef WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.x =
        static_cast<unsigned int>(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    size.y =
        static_cast<unsigned int>(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);

#else
    winsize w{};
    const int status = ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if (w.ws_col == 0 or w.ws_row == 0 or status < 0) {
      throw std::runtime_error{"Terminal size is wrong!"};
    }
    size.x = w.ws_col;
    size.y = w.ws_row;
#endif
    return size;
  }
};

std::unique_ptr<Core::impl> Core::_instance{nullptr};
bool Core::_initialized{false};

void Core::Init() {
  if (_initialized) {
    return;
  }
  _instance = std::make_unique<impl>();
  _initialized = true;
}

void Core::Run() {
  assert(_initialized);
  _instance->run();
}

void Core::SetNextScene(ScenePtr scene) {
  assert(_initialized);
  _instance->set_next_scene(std::move(scene));
}

ScenePtr Core::GetCurrentScene() {
  assert(_initialized);
  return _instance->get_current_scene();
}

Point2u Core::GetSize() {
  assert(_initialized);
  return _instance->get_size();
}
} // namespace libyunpa
