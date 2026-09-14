#include <string>

#include "SDL3/SDL_pixels.h"
#include "SDL3/SDL_surface.h"
#include <SDL3_ttf/SDL_ttf.h>

#include "Lenerith/Math/Vector2.h"
#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Text {
private:
  std::string text;
  bool textChanged = false;
  TTF_Font *font = nullptr;
  SDL_Surface *surface = nullptr;
  Vector2 position;
  SDL_Color color;

public:
  Text(const std::string &text, const Vector2 &position, TTF_Font *font, const SDL_Color &color);
  ~Text();
  void update();
  void setText(const std::string &text);
  void setColor(const SDL_Color &color);
};
}; // namespace Lenerith
