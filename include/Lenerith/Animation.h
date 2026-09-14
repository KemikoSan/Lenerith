#pragma once

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Animation {
private:
  SDL_Texture *tileSet;
  float tileWidth;
  float tileHeight;
  int totalFrames;
  int currentFrame = 0;
  int fps;
  float timer = 0.f;

public:
  SDL_FRect Play(float deltatime);
  void Stop();
  Animation(SDL_Texture *tileSet, float frameWidth, float frameHeight, int totalFrames, int fps);
  ~Animation();
};
}; // namespace Lenerith
