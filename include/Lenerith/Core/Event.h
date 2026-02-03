enum class EventType {
  QUIT,
  PAUSE,
  INPUT,
};

struct Event {
  EventType type;
};

struct InputEvent : Event {
  EventType type;
  int KB_button;
  float axis;
};
