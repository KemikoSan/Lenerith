#pragma once

#include <Lenerith/DLL.hpp>
#include <random>

namespace Lenerith {
class LENERITH_API RNG {
private:
  std::mt19937 generator;

public:
  RNG();
  bool randomEvent(int probability);
  int diceRoll();
  int rpgDiceRoll(int pips);
  int randomInt(int min, int max);
  float randomFloat(float min, float max);
  double randomDouble(double min, double max);
};
}; // namespace Lenerith
