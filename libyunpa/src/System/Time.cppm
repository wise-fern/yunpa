module;
#include <chrono>
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
  void update();
  void reset();
  [[nodiscard]]
  Duration last_frame() const;
  [[nodiscard]]
  Duration total_time() const;
};
} // namespace libyunpa
