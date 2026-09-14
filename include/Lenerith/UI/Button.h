#include <functional>
#include <string>

#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <Lenerith/DLL.h>

namespace Lenerith {
class LENERITH_API Button {
private:
  TTF_Font *font;
  SDL_Texture *texture;
  SDL_FRect shape;
  bool enable;
  std::string text;
  std::function<void()> callback;

public:
  Button(const std::string &text, const SDL_FRect &shape, const std::function<void()> &callback);
  ~Button();
  void render();
  void update();
  void press();
  void setEnabled(bool enable);
};
}; // namespace Lenerith
