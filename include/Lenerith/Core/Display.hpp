#include <SDL3/SDL_video.h>
#include <string>

struct Display {
  std::string name = "";
  int modesCount = 0;
  SDL_DisplayMode **display_modes = nullptr;
};
