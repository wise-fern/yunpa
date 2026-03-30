module;
#include <memory> // IWYU pragma: keep
module libyunpa;
import :SceneManager;

namespace libyunpa {
void SceneManager::pop_scene() {
  if (_scenes.empty()) {
    return;
  }
  _scenes.pop();
  if (_scenes.empty()) {
    return;
  }
  _scenes.top()->on_reveal();
}

void SceneManager::transition_scene() {
  if (_nextScene == nullptr) {
    return;
  }
  if (not _scenes.empty()) {
    _scenes.top()->on_bury();
  }
  _scenes.push(_nextScene);
  _nextScene = nullptr;
}

void SceneManager::update(const GameTime &gameTime) {
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

// NOLINTNEXTLINE(misc-no-recursion)
void SceneManager::draw_parents(ftxui::Screen &screen,
                                const ScenePtr &scene) const {
  if (scene == nullptr) {
    return;
  }
  draw_parents(screen, scene->parent());
  ftxui::Render(screen, scene->draw());
}

void SceneManager::draw(ftxui::Screen &screen) const {
  if (_scenes.empty()) {
    ftxui::Render(screen, ftxui::text("No Scenes") | ftxui::center);
    return;
  }
  draw_parents(screen, _scenes.top());
}

void SceneManager::set_next_scene(ScenePtr scene) {
  _nextScene = std::move(scene);
}

ScenePtr SceneManager::get_current_scene() const {
  if (_scenes.empty()) {
    return {};
  }
  return _scenes.top();
}

bool SceneManager::empty() const {
  return _scenes.empty();
}

void SceneManager::handle_event(const Event &event) {
  if (_scenes.empty()) {
    return;
  }
  _scenes.top()->handle_event(event);
}
} // namespace libyunpa
