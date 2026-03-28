module;
#include <chrono>
#include <ratio>

export module libyunpa:Time;

namespace libyunpa {
export using Duration = std::chrono::duration<long double, std::milli>;
export using TimePoint =
    std::chrono::time_point<std::chrono::steady_clock, Duration>;

export class GameTime {
private:
  Duration _lastFrame{Duration::zero()};
  Duration _totalTime{Duration::zero()};
  TimePoint _frameStart{TimePoint::clock::now()};

public:
  auto update() {
    auto now{TimePoint::clock::now()};
    _lastFrame = now - _frameStart;
    _totalTime += _lastFrame;
    _frameStart = now;
  }

  auto reset() {
    _lastFrame = Duration::zero();
    _totalTime = Duration::zero();
    _frameStart = TimePoint::clock::now();
  }

  [[nodiscard]]
  auto last_frame() const {
    return _lastFrame;
  }

  [[nodiscard]]
  auto total_time() const {
    return _totalTime;
  }
};
} // namespace libyunpa
