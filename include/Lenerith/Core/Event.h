enum class EventType {
  QUIT,
  PAUSE,
  INPUT,
};

struct Event {
  EventType type;
};
