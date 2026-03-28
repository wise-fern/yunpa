module;
#include <optional>
#include <queue>
export module libyunpa:EventManager;
import :Events;

namespace libyunpa {
export class EventManager final {
private:
  std::queue<Event> _eventQueue;

public:
  EventManager();
  void update();
  std::optional<Event> poll_event();
};
} // namespace libyunpa
