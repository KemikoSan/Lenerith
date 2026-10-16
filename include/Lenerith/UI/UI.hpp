#include <vector>

#include <Lenerith/DLL.hpp>
#include <Lenerith/UI/Widget.hpp>

namespace Lenerith {
class LENERITH_API UI {
private:
  std::vector<Widget> widgets;

public:
  void update();
  void render();
};
}; // namespace Lenerith
