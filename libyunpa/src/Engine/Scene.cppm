module;
#include <memory>
export module libyunpa:Scene;
import :Drawable;
import :Time;

namespace libyunpa {
export class Scene;
export using ScenePtr = std::shared_ptr<Scene>;

export class Scene : public Drawable {
private:
  ScenePtr _parent;
  bool _wantsExit{false};

protected:
  void request_exit();

public:
  Scene(ScenePtr parent = nullptr);
  virtual ~Scene() = default;

  [[nodiscard]]
  ScenePtr parent() const;
  [[nodiscard]]
  bool wants_exit() const;

  virtual void on_bury();
  virtual void on_reveal();
  virtual void update(const GameTime &gameTime) = 0;
};
} // namespace libyunpa
