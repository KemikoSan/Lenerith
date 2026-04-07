#include <SDL3_ttf/SDL_ttf.h>

class UI {
public:
  TTF_Font *font;
  SDL_Surface *surface;
  UI(const char *file, float ptsize);
  ~UI();
};
