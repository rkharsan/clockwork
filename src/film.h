#pragma once

#include <optional>
#include <string>
#include <vector>

#include "spectrum.h"

struct film {
  int width, height;
  std::vector<spectrum> buffer;

  film(int w, int h);
  film(int w, int h, spectrum c);

  std::optional<spectrum> get(int x, int y) const;
  void set(int x, int y, spectrum c);

  void write_ppm(const std::string& path);
};
