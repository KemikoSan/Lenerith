#include "SDL3/SDL_rect.h"
#include <SDL3/SDL_render.h>

class Animation {
private:
  // set of tiles or pointer to set of tiles
  float tileWidth;
  float tileHeight;
  int totalFrames;
  int currentFrame = 0;
  int fps;
  float timer = 0.f;

public:
  SDL_Texture *tileSet;
  SDL_FRect Play(float deltatime);
  void Stop();
  Animation(SDL_Texture *tileSet, float frameWidth, float frameHeight, int totalFrames, int fps);
  ~Animation();
};
