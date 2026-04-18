#include <functional>
#include <string>

#include <Lenerith/export.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>

class LENERITH_API Button {
private:
  std::string text;
  SDL_FRect shape;      // position and shape of button
  SDL_Texture *texture; // final shape/look of button
  std::function<void()> callback;

public:
  Button(const std::string &text, const SDL_FRect &shape, const std::function<void()> &callback);
  ~Button();
};
