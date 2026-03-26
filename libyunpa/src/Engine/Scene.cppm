module;
#include <memory>
export module libyunpa:Scene;
import :Drawable;
import :Events;
import :Time;

namespace libyunpa {
export class Scene;
export using ScenePtr = std::shared_ptr<Scene>;

export class Scene : public IDrawable {
private:
  ScenePtr _parent;
  bool _wantsExit{false};

protected:
  void request_exit();

public:
  Scene(ScenePtr parent = nullptr);
  ~Scene() override = default;
  [[nodiscard]]
  ScenePtr parent() const;
  [[nodiscard]]
  bool wants_exit() const;
  virtual void on_bury();
  virtual void on_reveal();
  virtual void update(const GameTime &gameTime) = 0;
  virtual void handle_event(const Event &event) = 0;
};
} // namespace libyunpa
