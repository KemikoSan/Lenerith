enum class EventType {
  QUIT,
  PAUSE,
  INPUT,
  GAMEPAD_REMOVED,
  GAMEPAD_ADDED
};

struct Event {
  EventType type;
  int keyboardKey;
};
