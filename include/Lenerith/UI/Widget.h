#include <string>
#include <vector>

#include <Lenerith/DLL.h>
#include <Lenerith/UI/UIElement.h>

namespace Lenerith {
class LENERITH_API Widget {
private:
  std::string name;
  std::vector<UIElement *> elements;
  bool isVisible;

public:
  void update();
  void addElement();
};
}; // namespace Lenerith
