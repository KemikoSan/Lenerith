#include "SDL3/SDL_stdinc.h"
#include <Lenerith/Core/Window.h>
#include <SDL3/SDL_video.h>

Lenerith::Window::Window(const std::string &WindowTitle)
    : ScreenWidth(config.screenWidth), ScreenHeight(config.screenHeight), isFullScreen(config.fullscreen),
      SDLwindow(SDL_CreateWindow(WindowTitle.c_str(), config.screenWidth, config.screenHeight, SDL_WINDOW_RESIZABLE)) {

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

void Lenerith::Window::resize(Uint32 width, Uint32 height) {
  ScreenWidth = width;
  ScreenHeight = height;
  SDL_SetWindowSize(SDLwindow, width, height);
}
