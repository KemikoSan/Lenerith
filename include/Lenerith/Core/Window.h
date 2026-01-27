#pragma once

#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"
#include <Lenerith/Core/Config.h>
#include <SDL3/SDL.h>
#include <string>

// Create SDL window
namespace Lenerith {
class Window {
private:
  SDL_Window *SDLwindow;
  SDL_DisplayID *displayModes;
  int displaysCount;
  Uint32 ScreenWidth;
  Uint32 ScreenHeight;
  bool isFullScreen;
  bool isBorderless;

public:
  Window(const std::string &windowTitle, const Config &config);
  ~Window();
  void toggleFullScreen(bool isFullScreen);
  void toggleBorderless(bool isBorderless);
  void resize(Uint32 width, Uint32 height);
  SDL_Window *getSDLWindow() const;
};
}; // namespace Lenerith
