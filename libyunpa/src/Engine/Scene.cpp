module;
#include <utility>
module libyunpa;

namespace libyunpa {
void Scene::request_exit() {
  _wantsExit = true;
}

Scene::Scene(ScenePtr parent) : Drawable({}), _parent(std::move(parent)) {}

ScenePtr Scene::parent() const {
  return _parent;
}

bool Scene::wants_exit() const {
  return _wantsExit;
}

void Scene::on_bury() {}

void Scene::on_reveal() {}
} // namespace libyunpa
