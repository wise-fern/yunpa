module;

module YoungPastry;

namespace YoungPastry::Scenes {
Title::Title() {
  _title.text("Young Pastry");
  _title.centered(true);
  _title.color(libyunpa::Color::RED);
}

void Title::update(const libyunpa::GameTime &gameTime) {}

void Title::draw() const {
  _title.draw();
}

void Title::handle_event(const libyunpa::Events::KeyEvent &event) {
  if (event.isKeyDown) {
    if (event.key == libyunpa::Keys::KEY_Q) {
      request_exit();
    }
  }
}
} // namespace YoungPastry::Scenes
