module;

module libyunpa;

namespace libyunpa {
Sizable::Sizable(const Options &options) : MinSize(options), MaxSize(options) {}

Sizable::~Sizable() = default;
} // namespace libyunpa
