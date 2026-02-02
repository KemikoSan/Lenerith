#pragma once

#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"
#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Display.h>
#include <SDL3/SDL.h>
#include <string>

// Create SDL window
namespace Lenerith {
class Window {
private:
  SDL_Window *SDLwindow;
  Display *displays;
  int displaysCount;
  Uint32 ScreenWidth;
  Uint32 ScreenHeight;
  bool isFullScreen;
  bool isBorderless;

public:
  Window(const std::string &windowTitle, const Config &config);
  ~Window();
  void toggleFullScreen();
  void toggleBorderless();
  void resize(Uint32 width, Uint32 height);
  void getDisplayModes();
  SDL_Window *getSDLWindow() const;
};
}; // namespace Lenerith
