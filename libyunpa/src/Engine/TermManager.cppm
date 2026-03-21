module;
#include <atomic>
#include <cstdint>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>
export module libyunpa:TermManager;
import :Events;

namespace libyunpa {
export class TermManager final {

public:
  enum Modes : std::uint8_t { APPLICATION_CURSOR_KEYS = 1 };

  static void DECSET(Modes mode);
  static void DECRST(Modes mode);

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
  std::optional<Event> poll_event();
};
} // namespace libyunpa
