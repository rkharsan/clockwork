#include "vec3.h"

#include <cmath>
#include <iostream>

// Constructors
vec3::vec3() : vec3(0) {}
vec3::vec3(double v) : vec3(v, v, v) {}
vec3::vec3(double x_, double y_, double z_) : x{x_}, y{y_}, z{z_} {}
vec3::vec3(const vec3& b) : vec3(b.x, b.y, b.z) {}

// Vector products
double vec3::dot(const vec3& b) const { return x * b.x + y * b.y + z * b.z; }
vec3 vec3::cross(const vec3& b) const {
  return vec3{y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x};
}

// Length and normalization
double vec3::len() const { return std::hypot(x, y, z); }
double vec3::len_squared() const { return x * x + y * y + z * z; }
vec3 vec3::norm() const { return *this / len(); }

// In-place modification operators
void vec3::operator+=(const vec3& b) {
  x += b.x;
  y += b.y;
  z += b.z;
}
void vec3::operator-=(const vec3& b) {
  x -= b.x;
  y -= b.y;
  z -= b.z;
}
void vec3::operator*=(double v) {
  x *= v;
  y *= v;
  z *= v;
}
void vec3::operator/=(double v) {
  x /= v;
  y /= v;
  z /= v;
}

// Negation
vec3 vec3::operator-() const { return *this * -1; }

// Componentwise addition and subtraction
vec3 operator+(const vec3& a, const vec3& b) {
  return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
}
vec3 operator-(const vec3& a, const vec3& b) {
  return vec3{a.x - b.x, a.y - b.y, a.z - b.z};
}

// Scaling
vec3 operator*(const vec3& a, double v) {
  return vec3{a.x * v, a.y * v, a.z * v};
}
vec3 operator*(double v, const vec3& a) { return a * v; }

// Division
vec3 operator/(const vec3& a, double v) {
  return vec3{a.x / v, a.y / v, a.z / v};
}

// Output operator for debugging
std::ostream& operator<<(std::ostream& out, const vec3& v) {
  out << "vec3(" << v.x << ", " << v.y << ", " << v.z << ")";
  return out;
}
