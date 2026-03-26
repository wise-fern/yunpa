module;
#include <variant>
module YoungPastry;

namespace YoungPastry::Scenes {
void Title::update(const libyunpa::GameTime &gameTime) {}

void Title::draw() const {}

template <class... Ts> struct Overload : Ts... {
  using Ts::operator()...;
};

void Title::handle_event(const libyunpa::Event &event) {
  auto handler = Overload{[&](const libyunpa::Events::KeyEvent &event) {
                            if (event.isKeyDown) {
                              if (event.key == libyunpa::Keys::KEY_Q) {
                                request_exit();
                              }
                            }
                          },
                          [](const libyunpa::Events::FocusEvent &event) {},
                          [](const libyunpa::Events::MouseEvent &event) {}};
  std::visit(handler, event);
}
} // namespace YoungPastry::Scenes
