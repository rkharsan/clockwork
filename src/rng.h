#pragma once

#include <cstdint>

struct rng {
  std::uint64_t state;

  rng(std::uint64_t s);
  double random();
};
