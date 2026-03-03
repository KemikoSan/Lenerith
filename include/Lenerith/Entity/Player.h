#pragma once

// #include "Lenerith/Entity/Entity.h"
#include "SDL3/SDL_rect.h"
#include "SDL3/SDL_render.h"
#include "SDL3_mixer/SDL_mixer.h"
#include <Lenerith/Animation.h>
#include <Lenerith/Camera.h>
#include <Lenerith/Core/Audio.h>
#include <Lenerith/Vector2.h>
// namespace Lenerith {
// class Player : public Lenerith::Entity {
// public:
//   Player(const Vector2 &position, SDL_Texture *texture);
//   virtual void update() = 0;
//   virtual ~Player();
// };
// }; // namespace Lenerith

class Player {
private:
  Animation idle;
  Animation walk;
  bool isWalking = false;
  Vector2 position = {0, 0};
  SDL_FPoint center;
  bool right = false;
  int gamepadId;
  MIX_Audio *sound;
  MIX_Audio *sound2;

public:
  void update(float deltatime);
  void render(SDL_Renderer *renderer, Camera *camera);
  SDL_FRect frame;
  Player(SDL_Texture *idle, SDL_Texture *walk, const Vector2 &position, int gamepadId);
  Vector2 getPosiotion() const;
};
