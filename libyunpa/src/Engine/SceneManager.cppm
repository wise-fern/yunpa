module;
#include <stack>
export module libyunpa:SceneManager;
import :Events;
import :Scene;
import :Time;
import ftxui;

namespace libyunpa {
export class SceneManager {
private:
  ScenePtr _nextScene;
  std::stack<ScenePtr> _scenes;

  void pop_scene();
  void transition_scene();
  void draw_parents(ftxui::Screen &screen, const ScenePtr &scene) const;

public:
  SceneManager() = default;
  void update(const GameTime &gameTime);
  void draw(ftxui::Screen &screen) const;
  void set_next_scene(ScenePtr scene);
  void handle_event(const Event &event);
  [[nodiscard]]
  ScenePtr get_current_scene() const;
  [[nodiscard]]
  bool empty() const;
};
} // namespace libyunpa
