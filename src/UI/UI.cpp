#include "SDL3/SDL_log.h"
#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_surface.h"
#include "SDL3_ttf/SDL_ttf.h"
#include <Lenerith/UI/UI.h>
#include <string>

UI::UI(const char *file, float ptsize) {
  TTF_Init();
  font = TTF_OpenFont(file, ptsize);
  if (!font) {
    SDL_Log("DUPA");
  }
  std::string text = "󰄛󰜃 Gun Cat 󰌤󰧼";
  surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), SDL_Color{0, 0, 0, 255});
}

UI::~UI() {
  SDL_DestroySurface(surface);
}
