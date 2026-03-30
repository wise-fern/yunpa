module;

module YoungPastry;

namespace YoungPastry::Scenes {
void Title::update(const libyunpa::GameTime &gameTime) {}

ftxui::Element Title::draw() const {
  return ftxui::text("Young Pastry") | ftxui::center;
}

template <class... Ts> struct Overload : Ts... {
  using Ts::operator()...;
};

void Title::handle_event(const libyunpa::Events::KeyEvent &event) {
  if (event.isKeyDown) {
    if (event.key == libyunpa::Keys::KEY_Q) {
      request_exit();
    }
  }
}
} // namespace YoungPastry::Scenes
