module;

export module YoungPastry:Title;
import libyunpa;

namespace YoungPastry::Scenes {
export class Title : public libyunpa::Scene {
private:
public:
  void update(const libyunpa::GameTime &gameTime) override;
  void calculate_output() override;
};
} // namespace YoungPastry::Scenes
