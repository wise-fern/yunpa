module;
#include <format>
#include <string>
#include <string_view>
module libyunpa;

namespace libyunpa {
Formattable::Formattable(const Options &options)
    : _bold(options.bold), _italic(options.italic),
      _underline(options.underline), _blink(options.blink), _dim(options.dim) {}

Formattable::~Formattable() = default;

void Formattable::bold(bool bold) {
  _bold = bold;
  update();
}

bool Formattable::bold() const {
  return _bold;
}

void Formattable::italic(bool italic) {
  _italic = italic;
  update();
}

bool Formattable::italic() const {
  return _italic;
}

void Formattable::underline(bool underline) {
  _underline = underline;
  update();
}

bool Formattable::underline() const {
  return _underline;
}

void Formattable::blink(bool blink) {
  _blink = blink;
  update();
}

bool Formattable::blink() const {
  return _blink;
}

void Formattable::dim(bool dim) {
  _dim = dim;
  update();
}

bool Formattable::dim() const {
  return _dim;
}

std::string Formattable::apply(std::string_view text) {
  std::string result{text};
  if (_bold) {
    result = std::format("\x1b[1m{}\x1b[22m", result);
  }
  if (_italic) {
    result = std::format("\x1b[3m{}\x1b[23m", result);
  }
  if (_underline) {
    result = std::format("\x1b[4m{}\x1b[24m", result);
  }
  if (_blink) {
    result = std::format("\x1b[5m{}\x1b[25m", result);
  }
  if (_dim) {
    result = std::format("\x1b[2m{}\x1b[22m", result);
  }
  return result;
}
} // namespace libyunpa
