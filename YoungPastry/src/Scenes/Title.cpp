module;

module YoungPastry;

namespace YoungPastry::Scenes {
void Title::update(const libyunpa::GameTime &gameTime) {}

void Title::draw() const {}

void Title::handle_event(const libyunpa::Events::KeyEvent &event) {
  if (event.isKeyDown) {
    if (event.key == libyunpa::Keys::KEY_Q) {
      request_exit();
    }
  }
}
} // namespace YoungPastry::Scenes
