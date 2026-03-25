module;
#include <memory>
export module libyunpa:Core;
import :Scene;

namespace libyunpa {
export class Core final {
private:
  class impl;
  static std::unique_ptr<impl> _instance;
  static bool _initialized;

public:
  Core() = delete;
  ~Core() = default;
  Core(Core &) = delete;
  Core(Core &&) = delete;
  Core &operator=(const Core &) = delete;
  Core &operator=(Core &&) = delete;

  static void Init();
  static void Run();
  static void SetNextScene(ScenePtr scene);
  static ScenePtr GetCurrentScene();
};
} // namespace libyunpa
