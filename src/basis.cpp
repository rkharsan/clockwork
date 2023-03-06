#include "basis.h"

basis::basis(vec3 u_, vec3 v_, vec3 w_) : u{u_}, v{v_}, w{w_} {}

static constexpr double EPS = 0.01;

basis basis::fromU(vec3 a) {
  vec3 n = {1, 0, 0};
  vec3 m = {0, 1, 0};
  vec3 u = a.norm();
  vec3 v = u.cross(n);
  if (v.len_squared() < EPS) v = u.cross(m);
  vec3 w = u.cross(v);
  return basis{u, v, w};
}

basis basis::fromV(vec3 a) {
  vec3 n = {1, 0, 0};
  vec3 m = {0, 1, 0};
  vec3 v = a.norm();
  vec3 u = v.cross(n);
  if (u.len_squared() < EPS) u = v.cross(m);
  vec3 w = u.cross(v);
  return basis{u, v, w};
}

basis basis::fromW(vec3 a) {
  vec3 n = {1, 0, 0};
  vec3 m = {0, 1, 0};
  vec3 w = a.norm();
  vec3 u = w.cross(n);
  if (u.len_squared() < EPS) u = w.cross(m);
  vec3 v = w.cross(u);
  return basis{u, v, w};
}

basis basis::fromUV(vec3 a, vec3 b) {
  vec3 u = a.norm();
  vec3 w = a.cross(b).norm();
  vec3 v = w.cross(u);
  return basis{u, v, w};
}

basis basis::fromVU(vec3 a, vec3 b) {
  vec3 v = a.norm();
  vec3 w = b.cross(a).norm();
  vec3 u = v.cross(w);
  return basis{u, v, w};
}

basis basis::fromUW(vec3 a, vec3 b) {
  vec3 u = a.norm();
  vec3 v = b.cross(a).norm();
  vec3 w = u.cross(v);
  return basis{u, v, w};
}

basis basis::fromWU(vec3 a, vec3 b) {
  vec3 w = a.norm();
  vec3 v = a.cross(b).norm();
  vec3 u = v.cross(w);
  return basis{u, v, w};
}

basis basis::fromVW(vec3 a, vec3 b) {
  vec3 v = a.norm();
  vec3 u = a.cross(b).norm();
  vec3 w = u.cross(v);
  return basis{u, v, w};
}

basis basis::fromWV(vec3 a, vec3 b) {
  vec3 w = a.norm();
  vec3 u = b.cross(a).norm();
  vec3 v = w.cross(u);
  return basis{u, v, w};
}
