#include <string>
#include <vector>

#include <Lenerith/DLL.hpp>
#include <Lenerith/UI/UIElement.hpp>

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
