#define LENERITH_EXPORT

#include <Lenerith/UI/Widget.hpp>

void Lenerith::Widget::update() {
  for (auto &element : elements) {
    element->update();
  }
}
