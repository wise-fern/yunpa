module;

module libyunpa;

namespace libyunpa {
Sizable::~Sizable() = default;

Sizable::Sizable(const Options &options) : MinSize(options), MaxSize(options) {}
} // namespace libyunpa
