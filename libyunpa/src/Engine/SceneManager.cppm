module;
#include <stack>
export module libyunpa:SceneManager;
import :Drawable;
import :Scene;

namespace libyunpa {
export class SceneManager : public Drawable {
private:
  ScenePtr _nextScene;
  std::stack<ScenePtr> _scenes;

  void draw(ScenePtr scene) const;
  void pop_scene();
  void transition_scene();

public:
  void update(const GameTime &gameTime);
  void draw() const override;
  void set_next_scene(ScenePtr scene);
  [[nodiscard]]
  ScenePtr get_current_scene() const;
  [[nodiscard]]
  bool empty() const;
};
} // namespace libyunpa
