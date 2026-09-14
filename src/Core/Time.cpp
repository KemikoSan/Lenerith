#define LENERITH_EXPORT

#include "SDL3/SDL_timer.h"

#include <Lenerith/Core/Time.h>

float Lenerith::Time::deltatime = 0.0f;
float Lenerith::Time::unscaledDeltatime = 0.0f;
float Lenerith::Time::timescale = 1.0f;

void Lenerith::Time::update() {
  static Uint64 lastCounter = SDL_GetPerformanceCounter();
  Uint64 currentCounter = SDL_GetPerformanceCounter();
  Uint64 frequency = SDL_GetPerformanceFrequency();
  Time::unscaledDeltatime = ((currentCounter - lastCounter) / static_cast<float>(frequency));
  Time::deltatime = ((currentCounter - lastCounter) / static_cast<float>(frequency)) * timescale;
  lastCounter = currentCounter;
}
