#include "film.h"

#include <cmath>
#include <fstream>
#include <optional>
#include <string>
#include <vector>

#include "spectrum.h"

film::film(int w, int h) : film(w, h, spectrum{}) {}
film::film(int w, int h, spectrum c) : width{w}, height{h}, buffer(w * h, c) {}

std::optional<spectrum> film::get(int x, int y) const {
  if (x < 0 || x >= width) return std::nullopt;
  if (y < 0 || y >= height) return std::nullopt;
  int index = y * width + x;
  return buffer.at(index);
}

void film::set(int x, int y, spectrum c) {
  if (x < 0 || x >= width) return;
  if (y < 0 || y >= height) return;
  int index = y * width + x;
  buffer.at(index) = c;
}

void film::write_ppm(const std::string& path) {
  auto clamp = [](double v, double min, double max) {
    return std::min(std::max(v, min), max);
  };

  auto color_to_pixel = [&](double v) {
    return (int)(255.5 * clamp(pow(v, 2.2), 0, 1));
  };

  std::ofstream file(path);

  // Write header
  file << "P3\n";
  file << width << " " << height << "\n";
  file << "255\n";

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      spectrum c = get(x, y).value();

      // Normalize each component
      int r = color_to_pixel(c.r);
      int g = color_to_pixel(c.g);
      int b = color_to_pixel(c.b);

      file << r << " " << g << " " << b << "\n";
    }
  }
}
