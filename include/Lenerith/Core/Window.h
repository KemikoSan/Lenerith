#pragma once

#include <string_view>

#include "SDL3/SDL_video.h"
#include <SDL3/SDL.h>

#include <Lenerith/Core/Config.h>
#include <Lenerith/Core/Display.h>
#include <Lenerith/DLL.h>

// Create SDL window
namespace Lenerith {
class LENERITH_API Window {
private:
  SDL_Window *SDLwindow = nullptr;
  Display *displays = nullptr;
  int displaysCount;
  int ScreenWidth;
  int ScreenHeight;
  bool isFullScreen;
  bool isBorderless;
  int currentMonitor = 0;
  int currentDisplayMode = 0;

public:
  Window(std::string_view title);
  ~Window();
  void toggleFullScreen();
  void toggleBorderless();
  void setTitle(std::string_view title);
  void resize(int width, int height);
  void getDisplayModes() const;
  SDL_Window *getSDLWindow() const;
};
}; // namespace Lenerith
