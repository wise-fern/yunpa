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
  auto request_exit() {
    _wantsExit = true;
  }

  void calculate_output() override {}

public:
  Scene(ScenePtr parent = nullptr) : _parent(std::move(parent)) {}

  virtual ~Scene() = default;

  [[nodiscard]]
  auto parent() const {
    return _parent;
  }

  [[nodiscard]]
  auto wants_exit() const {
    return _wantsExit;
  }

  virtual void on_bury() {}

  virtual void on_reveal() {}

  virtual void update(const GameTime &gameTime) = 0;
};
} // namespace libyunpa
