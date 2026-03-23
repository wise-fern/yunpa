module;
#include <memory>
export module libyunpa:Element;
import :Drawable;

namespace libyunpa {
export class Node : public virtual Drawable {
private:
  std::string _output;

protected:
  void output(std::string_view output);
  virtual void calculate_output() = 0;

public:
  virtual ~Node() = 0;
  void draw() const override;
};

export using Element = std::shared_ptr<Node>;
} // namespace libyunpa
