#pragma once

#include <iostream>

struct spectrum {
  double r, g, b;

  // Constructors
  spectrum();
  spectrum(double v);
  spectrum(double r_, double g_, double b_);

  // In-place modification operators
  void operator+=(const spectrum& s);
  void operator-=(const spectrum& s);
  void operator*=(const spectrum& s);
  void operator/=(const spectrum& s);
};

// Scaling operators
spectrum operator*(const spectrum& s, double v);
spectrum operator*(double v, const spectrum& s);
spectrum operator/(const spectrum& s, double v);

// Output operator for debugging
std::ostream& operator<<(std::ostream& out, const spectrum& s);
