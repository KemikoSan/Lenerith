#define LENERITH_EXPORT

#include "SDL3/SDL_render.h"
#include <Lenerith/Animation.h>

Animation::Animation(SDL_Texture *tileSet, float tileWidth, float tileHeight, int totalFrames, int fps)
    : tileSet(tileSet), tileWidth(tileWidth), tileHeight(tileHeight), totalFrames(totalFrames), fps(fps) {}

Animation::~Animation() {
  SDL_DestroyTexture(tileSet);
}

SDL_FRect Animation::Play(float deltatime) {
  timer += deltatime;
  if (timer >= (1.0f / fps)) {
    timer = 0.0f;
    currentFrame = (currentFrame + 1) % totalFrames;
  }
  return {.x = currentFrame * tileWidth, .y = 0, .w = tileWidth, .h = tileHeight};
}

void Animation::Stop() {
  timer = 0.0f;
  currentFrame = 0;
}
