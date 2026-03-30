module;
#include <memory>
export module libyunpa:Scene;
import :Events;
import :Point2;
import :Time;

namespace libyunpa {
export class Scene;
export using ScenePtr = std::shared_ptr<Scene>;

export class Scene {
private:
  ScenePtr _parent;
  Point2u _mousePosition{.x = 1, .y = 1};
  bool _wantsExit{false};
  bool _hasFocus{false};

protected:
  void request_exit();
  [[nodiscard]]
  bool has_focus() const;
  [[nodiscard]]
  Point2u mouse_position() const;

public:
  Scene(ScenePtr parent = nullptr);
  virtual ~Scene() = default;
  [[nodiscard]]
  ScenePtr parent() const;
  [[nodiscard]]
  bool wants_exit() const;
  virtual void on_bury();
  virtual void on_reveal();
  virtual void draw() const = 0;
  virtual void update(const GameTime &gameTime) = 0;
  virtual void handle_event(const libyunpa::Event &event);
  virtual void handle_event(const libyunpa::Events::KeyEvent &event) = 0;
  virtual void handle_event(const libyunpa::Events::FocusEvent &event);
  virtual void handle_event(const libyunpa::Events::MouseEvent &event);
};
} // namespace libyunpa
