module;

export module YoungPastry:Title;
import libyunpa;

namespace YoungPastry::Scenes {
export class Title : public libyunpa::Scene {
private:
public:
  void update(const libyunpa::GameTime &gameTime) override;
  void draw() const override;
};
} // namespace YoungPastry::Scenes
