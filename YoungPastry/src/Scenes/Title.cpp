module;

module YoungPastry;

namespace YoungPastry::Scenes {
void Title::update(const libyunpa::GameTime &gameTime) {}

ftxui::Element Title::draw() const {
  constexpr auto SPACER_HEIGHT{5};
  auto youngpastry{ftxui::text("Young Pastry") | ftxui::center |
                   ftxui::color(ftxui::Color::DeepPink3)};
  auto in_{ftxui::text("in") | ftxui::center |
           ftxui::color(ftxui::Color::DeepPink2)};
  auto search{ftxui::text("The Search for a Magical Pet") | ftxui::center |
              ftxui::color(ftxui::Color::DeepPink3)};
  auto text{ftxui::vbox({youngpastry, in_, search}) | ftxui::center};
  auto spacer{ftxui::emptyElement() |
              ftxui::size(ftxui::HEIGHT, ftxui::EQUAL, SPACER_HEIGHT)};
  auto layout{ftxui::vbox({spacer, text})};
  return layout;
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
