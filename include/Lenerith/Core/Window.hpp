#pragma once

#include <string_view>

#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>

#include <Lenerith/Core/Config.hpp>
#include <Lenerith/Core/Display.hpp>
#include <Lenerith/DLL.hpp>

// Create SDL window
namespace Lenerith {
class LENERITH_API Window {
private:
  SDL_Window *SDLwindow = nullptr;
  Display *displays = nullptr;
  int displaysCount = 0;
  int ScreenWidth = 0;
  int ScreenHeight = 0;
  bool isFullScreen = false;
  bool isBorderless = false;
  int currentMonitor = 0;
  int currentDisplayMode = 0;

public:
  Window();
  ~Window();
  void toggleFullScreen();
  void toggleBorderless();
  void setTitle(std::string_view title);
  void resize(int width, int height);
  void getDisplayModes() const;
  SDL_Window *getSDLWindow() const;
};
}; // namespace Lenerith
