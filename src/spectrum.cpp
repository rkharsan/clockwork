#include "spectrum.h"

// Constructors
spectrum::spectrum() : spectrum(0) {}
spectrum::spectrum(double v) : spectrum(v, v, v) {}
spectrum::spectrum(double r_, double g_, double b_) : r{r_}, g{g_}, b{b_} {}

// In-place modification operators
void spectrum::operator+=(const spectrum& s) {
  r += s.r;
  g += s.g;
  b += s.b;
}
void spectrum::operator-=(const spectrum& s) {
  r -= s.r;
  g -= s.g;
  b -= s.b;
}
void spectrum::operator*=(const spectrum& s) {
  r *= s.r;
  g *= s.g;
  b *= s.b;
}
void spectrum::operator/=(const spectrum& s) {
  r /= s.r;
  g /= s.g;
  b /= s.b;
}

// Scaling operators
spectrum operator*(const spectrum& s, double v) {
  return spectrum{s.r * v, s.g * v, s.b * v};
}
spectrum operator*(double v, const spectrum& s) { return s * v; }
spectrum operator/(const spectrum& s, double v) {
  return spectrum{s.r / v, s.g / v, s.b / v};
}

// Output operator for debugging
std::ostream& operator<<(std::ostream& out, const spectrum& s) {
  out << "spectrum(" << s.r << ", " << s.g << ", " << s.b << ")";
  return out;
}
