module;
#include <chrono>
module libyunpa;
import :Time;

namespace libyunpa {
void GameTime::reset() {
  _lastFrame = Duration::zero();
  _totalTime = Duration::zero();
  _frameStart = TimePoint::clock::now();
}

void GameTime::update() {
  auto now{TimePoint::clock::now()};
  _lastFrame = now - _frameStart;
  _totalTime += _lastFrame;
  _frameStart = now;
}

Duration GameTime::last_frame() const {
  return _lastFrame;
}

Duration GameTime::total_time() const {
  return _totalTime;
}
} // namespace libyunpa
