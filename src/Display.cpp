#include <SDL3/SDL.h>

int main() {
  int displays;
  int modes;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_DisplayID *display = SDL_GetDisplays(&displays);

  if (!display || displays == 0) {
    SDL_Log("Brak displayów: %s", SDL_GetError());
    return 1;
  }

  SDL_DisplayMode **display_modes =
      SDL_GetFullscreenDisplayModes(display[0], &modes);
  for (int i = 0; i < modes; i++) {
    SDL_Log("%dx%d", display_modes[i]->w, display_modes[i]->h);
  }

  SDL_free(display);
  SDL_free(display_modes);
}
