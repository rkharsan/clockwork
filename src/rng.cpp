#include "rng.h"

#include <cstdint>

rng::rng(std::uint64_t s): state{s} {}

double rng::random() {
  state ^= state << 13;
  state ^= state >> 7;
  state ^= state << 17;
  return (state >> 11) * 0x1.0p-53;
}
