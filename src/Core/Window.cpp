#define LENERITH_EXPORT

#include <string_view>

#include "SDL3/SDL_stdinc.h"
#include <SDL3/SDL_video.h>

#include <Lenerith/Core/Window.h>

Lenerith::Window::Window(std::string_view WindowTitle)
    : ScreenWidth(Config::instance().screenWidth), ScreenHeight(Config::instance().screenHeight), isFullScreen(Config::instance().fullscreen),
      SDLwindow(SDL_CreateWindow(WindowTitle.data(), Config::instance().screenWidth, Config::instance().screenHeight, SDL_WINDOW_RESIZABLE)) {

  SDL_DisplayID *displayIDs = SDL_GetDisplays(&displaysCount);
  displays = new Display[displaysCount];
  for (int i = 0; i < displaysCount; i++) {
    displays[i].name = SDL_GetDisplayName(displayIDs[i]);
    displays[i].display_modes = SDL_GetFullscreenDisplayModes(displayIDs[i], &displays[i].modesCount);
  }
  SDL_free(displayIDs);

  SDL_SetWindowFullscreen(SDLwindow, isFullScreen);
  SDL_SetWindowBordered(SDLwindow, isBorderless);
}

Lenerith::Window::~Window() {
  SDL_DestroyWindow(SDLwindow);
  for (int i = 0; i < displaysCount; i++) {
    SDL_free(displays[i].display_modes);
  }
  delete[] displays;
}

void Lenerith::Window::toggleFullScreen() {
  isFullScreen = !isFullScreen;
  SDL_SetWindowFullscreenMode(SDLwindow, displays[currentMonitor].display_modes[currentDisplayMode]);
  SDL_SetWindowFullscreen(SDLwindow, isFullScreen);
}

void Lenerith::Window::toggleBorderless() {
  isBorderless = !isBorderless;
  SDL_SetWindowBordered(SDLwindow, isBorderless);
}

SDL_Window *Lenerith::Window::getSDLWindow() const {
  return SDLwindow;
}

void Lenerith::Window::resize(int width, int height) {
  ScreenWidth = width;
  ScreenHeight = height;
  SDL_SetWindowSize(SDLwindow, width, height);
}

void Lenerith::Window::setTitle(std::string_view title) {
  SDL_SetWindowTitle(SDLwindow, title.data());
}
