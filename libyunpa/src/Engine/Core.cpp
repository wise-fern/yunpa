module;
#include <cassert>
#include <memory>
module libyunpa;

namespace libyunpa {
class Core::impl final {
private:
  GameTime _gameTime;
  SceneManager _sceneMan;

  auto game_loop() {
    while (true) {
      _gameTime.update();
      _sceneMan.update(_gameTime);
      if (_sceneMan.empty()) {
        return;
      }
    }
  }

public:
  auto run() {
    _gameTime.reset();
    game_loop();
  }

  auto set_next_scene(ScenePtr scene) {
    _sceneMan.set_next_scene(std::move(scene));
  }

  [[nodiscard]]
  auto get_current_scene() const {
    return _sceneMan.get_current_scene();
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
} // namespace libyunpa
