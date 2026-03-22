module;
#include <memory>
#include <stack>
export module libyunpa:SceneManager;
import :Drawable;
import :Scene;
import :Time;

namespace libyunpa {
export class SceneManager : public Drawable {
private:
  ScenePtr _nextScene;
  std::stack<ScenePtr> _scenes;

  auto draw(ScenePtr scene) const {
    if (scene == nullptr) {
      return;
    }
    draw(scene->parent());
    scene->draw();
  }

  auto pop_scene() {
    if (_scenes.empty()) {
      return;
    }
    _scenes.pop();
    if (_scenes.empty()) {
      return;
    }
    _scenes.top()->on_reveal();
  }

  auto transition_scene() {
    if (_nextScene == nullptr) {
      return;
    }
    if (not _scenes.empty()) {
      _scenes.top()->on_bury();
    }
    _scenes.push(_nextScene);
    _nextScene = nullptr;
  }

public:
  SceneManager() = default;

  auto update(const GameTime &gameTime) {
    if (not _scenes.empty() and _scenes.top()->wants_exit()) {
      pop_scene();
    }
    if (_nextScene not_eq nullptr) {
      transition_scene();
    }
    if (_scenes.empty()) {
      return;
    }
    _scenes.top()->update(gameTime);
  }

  void draw() const override {
    if (_scenes.empty()) {
      return;
    }
    draw(_scenes.top());
  }

  void set_next_scene(ScenePtr scene) {
    _nextScene = std::move(scene);
  }

  [[nodiscard]]
  auto get_current_scene() const {
    if (_scenes.empty()) {
      return ScenePtr{};
    }
    return _scenes.top();
  }

  [[nodiscard]]
  auto empty() const {
    return _scenes.empty();
  }
};
} // namespace libyunpa
