module;
#include <utility>
#include <variant>
module libyunpa;
import :Scene;

namespace libyunpa {
void Scene::request_exit() {
  _wantsExit = true;
}

Scene::Scene(ScenePtr parent) : _parent(std::move(parent)) {}

ScenePtr Scene::parent() const {
  return _parent;
}

bool Scene::wants_exit() const {
  return _wantsExit;
}

void Scene::on_bury() {}

void Scene::on_reveal() {}

template <class... Ts> struct Overload : Ts... {
  using Ts::operator()...;
};

void Scene::handle_event(const Event &event) {
  auto handler = Overload(
      [&](const Events::KeyEvent &event) {
        handle_event(event);
      },
      [&](const Events::FocusEvent &event) {
        handle_event(event);
      },
      [&](const Events::MouseEvent &event) {
        handle_event(event);
      });
  std::visit(handler, event);
}

void Scene::handle_event(const Events::FocusEvent &event) {
  _hasFocus = event.hasFocus;
}

void Scene::handle_event(const Events::MouseEvent &event) {
  _mousePosition = {.x = event.x, .y = event.y};
}

Point2u Scene::mouse_position() const {
  return _mousePosition;
}

bool Scene::has_focus() const {
  return _hasFocus;
}
} // namespace libyunpa
