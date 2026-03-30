module;

export module YoungPastry:Title;
import libyunpa;

namespace YoungPastry::Scenes {
export class Title : public libyunpa::Scene {
private:
public:
  void update(const libyunpa::GameTime &gameTime) override;
  [[nodiscard]]
  ftxui::Element draw() const override;
  void handle_event(const libyunpa::Events::KeyEvent &event) override;
};
} // namespace YoungPastry::Scenes
