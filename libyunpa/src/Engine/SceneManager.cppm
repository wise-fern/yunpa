module;
#include <stack>
export module libyunpa:SceneManager;
import :Events;
import :Scene;
import :Time;

namespace libyunpa {
export class SceneManager {
private:
  ScenePtr _nextScene;
  std::stack<ScenePtr> _scenes;

  void draw(const ScenePtr &scene) const;
  void pop_scene();
  void transition_scene();

public:
  SceneManager() = default;
  void update(const GameTime &gameTime);
  void draw() const;
  void set_next_scene(ScenePtr scene);
  void handle_event(const Event &event);
  [[nodiscard]]
  ScenePtr get_current_scene() const;
  [[nodiscard]]
  bool empty() const;
};
} // namespace libyunpa
