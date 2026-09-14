#include <vector>

#include <Lenerith/DLL.h>
#include <Lenerith/UI/Widget.h>

namespace Lenerith {
class LENERITH_API UI {
private:
  std::vector<Widget> widgets;

public:
  void update();
  void render();
};
}; // namespace Lenerith
