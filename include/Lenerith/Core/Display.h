#include <SDL3/SDL_video.h>
#include <string>

struct Display {
  std::string name;
  int modesCount;
  SDL_DisplayMode **display_modes = nullptr;
};
