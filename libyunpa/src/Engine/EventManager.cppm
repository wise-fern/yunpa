module;
#include <atomic>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

export module libyunpa:EventManager;
import :Events;

namespace libyunpa {
export class EventManager final {
private:
  std::thread _monitor;
  std::atomic_flag _running;

  std::mutex _queueMutex;
  std::queue<Event> _eventQueue;

  void enqueue_event(Event event);
  void event_loop();

public:
  void start();
  void stop();
  std::optional<Event> poll_event() ;
};
} // namespace libyunpa
