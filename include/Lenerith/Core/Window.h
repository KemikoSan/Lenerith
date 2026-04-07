#pragma once

#include <string>

#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>

#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Display.h>

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
  int currentMonitor = 0;
  int currentDisplayMode = 0;

public:
  Window(const std::string &windowTitle);
  ~Window();
  void toggleFullScreen();
  void toggleBorderless();
  void resize(Uint32 width, Uint32 height);
  void getDisplayModes();
  SDL_Window *getSDLWindow() const;
};
}; // namespace Lenerith
