#include "SDL3/SDL_stdinc.h"
#include <Lenerith/Core/Window.h>
#include <SDL3/SDL_video.h>

Lenerith::Window::Window(const std::string &WindowTitle, const Config &config)
    : ScreenWidth(config.screenWidth), ScreenHeight(config.screenHeight),
      isFullScreen(config.fullscreen),
      SDLwindow(SDL_CreateWindow(WindowTitle.c_str(), config.screenWidth,
                                 config.screenHeight, SDL_WINDOW_RESIZABLE)) {
  toggleFullScreen(isFullScreen);
  toggleBorderless(isBorderless);
}

Lenerith::Window::~Window() { SDL_DestroyWindow(SDLwindow); }

void Lenerith::Window::toggleFullScreen(bool isFullscreen) {
  SDL_SetWindowFullscreen(SDLwindow, isFullScreen);
  displayModes = SDL_GetDisplays(&displaysCount);
}

void Lenerith::Window::toggleBorderless(bool isBorderless) {
  SDL_SetWindowBordered(SDLwindow, isBorderless);
  // isBorderless = isBorderless;
}

SDL_Window *Lenerith::Window::getSDLWindow() const { return SDLwindow; }

void Lenerith::Window::resize(Uint32 width, Uint32 height) {
  ScreenWidth = width;
  ScreenHeight = height;
  SDL_SetWindowSize(SDLwindow, width, height);

  // SDL_SetWindowFullscreenMode(SDL_Window,  SDL_DisplayMode*});
}
