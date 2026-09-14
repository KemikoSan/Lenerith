#define LENERITH_EXPORT

#include <Lenerith/UI/Widget.h>

void Lenerith::Widget::update() {
  for (auto &element : elements) {
    element->update();
  }
}
