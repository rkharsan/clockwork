#pragma once

#include "vec3.h"

struct basis {
  vec3 u, v, w;

  basis(vec3 u_, vec3 v_, vec3 w_);

  static basis fromU(vec3 a);
  static basis fromV(vec3 a);
  static basis fromW(vec3 a);

  static basis fromUV(vec3 a, vec3 b);
  static basis fromVU(vec3 a, vec3 b);
  static basis fromUW(vec3 a, vec3 b);
  static basis fromWU(vec3 a, vec3 b);
  static basis fromVW(vec3 a, vec3 b);
  static basis fromWV(vec3 a, vec3 b);
};
