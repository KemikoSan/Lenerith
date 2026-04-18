#include <SDL3/SDL_rect.h>

#include <Lenerith/Math/Vector2.h>
#include <Lenerith/export.h>

namespace Lenerith {
class LENERITH_API ProgressBar {
private:
  Vector2 position;
  float progress;
  float maxWidth;
  SDL_FRect shape;

public:
  void update();
};
}; // namespace Lenerith
