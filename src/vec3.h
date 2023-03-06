#pragma once

#include <iostream>

struct vec3 {
  double x, y, z;

  // Constructors
  vec3();
  vec3(double v);
  vec3(double x, double y, double z);
  vec3(const vec3& b);

  // Vector products
  double dot(const vec3& b) const;
  vec3 cross(const vec3& b) const;

  // Length and normalization
  double len() const;
  double len_squared() const;
  vec3 norm() const;

  // In-place modification operators
  void operator+=(const vec3& b);
  void operator-=(const vec3& b);
  void operator*=(double v);
  void operator/=(double v);

  // Negation
  vec3 operator-() const;
};

// Componentwise addition and subtraction
vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);

// Scaling
vec3 operator*(const vec3& a, double v);
vec3 operator*(double v, const vec3& a);

// Division
vec3 operator/(const vec3& a, double v);

// Output operator for debugging
std::ostream& operator<<(std::ostream& out, const vec3& v);
