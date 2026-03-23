module;
#include <string>
export module libyunpa:Formattable;
import :Element;

namespace libyunpa {
export class Formattable : public virtual Node {
public:
  struct Options {
    bool bold{false};
    bool italic{false};
    bool underline{false};
    bool blink{false};
    bool dim{false};
  };

private:
  bool _bold;
  bool _italic;
  bool _underline;
  bool _blink;
  bool _dim;

protected:
  std::string apply(std::string_view text);

public:
  Formattable(const Options &options);
  virtual ~Formattable() = 0;
  void bold(bool bold);
  [[nodiscard]]
  bool bold() const;
  void italic(bool bold);
  [[nodiscard]]
  bool italic() const;
  void underline(bool underline);
  [[nodiscard]]
  bool underline() const;
  void blink(bool blink);
  [[nodiscard]]
  bool blink() const;
  void dim(bool dim);
  [[nodiscard]]
  bool dim() const;
};
} // namespace libyunpa
