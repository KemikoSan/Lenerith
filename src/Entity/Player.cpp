#define LENERITH_EXPORT

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_surface.h"

#include "Lenerith/Animation.h"
#include "Lenerith/Input/InputMap.h"
#include "Lenerith/Math/Vector2.h"
#include <Lenerith/Core/Audio.h>
#include <Lenerith/Core/Time.h>
#include <Lenerith/Entity/Player.h>
#include <Lenerith/Input/Input.h>

Player::Player(SDL_Texture *walk, SDL_Texture *idle, const Vector2 &position, int gamepadId)
    : walk({walk, 450, 490, 12, 15}), idle({idle, 450, 490, 5, 10}), gamepadId(gamepadId), position(position) {
  center = {225, 245};
  sound = MIX_LoadAudio(Lenerith::Audio::instance().getMixer(), "sound.wav", false);
  sound2 = MIX_LoadAudio(Lenerith::Audio::instance().getMixer(), "healthpcikup1.wav", false);
}

void Player::update() {
  Lenerith::Input &input = Lenerith::Input::instance();
  if (input.getAxis(gamepadId, Gamepad::LEFT_AXIS_X) > 0.1f) {
    right = true;
    isWalking = true;
    position.x += 250.f * Lenerith::Time::deltatime;
  }

  if (input.getAxis(gamepadId, Gamepad::LEFT_AXIS_X) < -0.1f) {
    right = false;
    isWalking = true;
    position.x -= 250.f * Lenerith::Time::deltatime;
  }

  if (input.getAxis(gamepadId, Gamepad::LEFT_AXIS_X) > -0.1f && input.getAxis(gamepadId, Gamepad::LEFT_AXIS_X) < 0.1f) {
    isWalking = false;
  }

  if (input.isButtonPressed(gamepadId, Gamepad::FACE_DOWN)) {
    Lenerith::Audio::instance().playSound(sound);
  }

  if (input.isButtonPressed(gamepadId, Gamepad::FACE_RIGHT)) {
    Lenerith::Audio::instance().playSound(sound2);
  }

  if (isWalking) {
    idle.Stop();
    frame = walk.Play(Lenerith::Time::deltatime);
  } else {
    walk.Stop();
    isWalking = false;
    frame = idle.Play(Lenerith::Time::deltatime);
  }
}

void Player::render(SDL_Renderer *renderer, Lenerith::Camera *camera) {
  SDL_FRect dest = {.x = position.x - camera->viewport.x, .y = position.y - camera->viewport.y, .w = 450.f, .h = 490.f};

  if (isWalking) {
    if (right)
      SDL_RenderTextureRotated(renderer, walk.tileSet, &frame, &dest, 0, nullptr, SDL_FLIP_NONE);
    else
      SDL_RenderTextureRotated(renderer, walk.tileSet, &frame, &dest, 0, nullptr, SDL_FLIP_HORIZONTAL);
  } else {
    if (right)
      SDL_RenderTextureRotated(renderer, idle.tileSet, &frame, &dest, 0, nullptr, SDL_FLIP_HORIZONTAL);
    else
      SDL_RenderTextureRotated(renderer, idle.tileSet, &frame, &dest, 0, nullptr, SDL_FLIP_NONE);
  }
}

Vector2 Player::getPosition() const {
  return position;
}
