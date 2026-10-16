#include <queue>

enum class EventType {
  QUIT,
  PAUSE,
  GAMEPAD_REMOVED,
  GAMEPAD_ADDED
};

inline std::queue<EventType> eventQueue;
