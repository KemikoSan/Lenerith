#define LENERITH_EXPORT

#include <random>

#include <Lenerith/Math/RNG.h>

Lenerith::RNG::RNG() : generator(std::random_device{}()) {}

bool Lenerith::RNG::randomEvent(int percentage) {
  std::uniform_int_distribution<int> distribution(1, 100);
  return distribution(generator) <= percentage;
}

int Lenerith::RNG::diceRoll() {
  std::uniform_int_distribution<int> distribution(1, 6);
  return distribution(generator);
}

int Lenerith::RNG::rpgDiceRoll(int pips) {
  std::uniform_int_distribution<int> distribution(1, pips);
  return distribution(generator);
}

int Lenerith::RNG::randomInt(int min, int max) {
  std::uniform_int_distribution<int> distribution(min, max);
  return distribution(generator);
}

float Lenerith::RNG::randomFloat(float min, float max) {
  std::uniform_real_distribution<float> distribution(min, max);
  return distribution(generator);
}
