#include <crappy_vector.h>

crappy_vector_t add_vector(crappy_vector_t v1, crappy_vector_t v2) {
  crappy_vector_t res;
  res.x = v1.x + v2.x;
  res.y = v1.y + v2.y;
  return res;
}

crappy_vector_t sub_vector(crappy_vector_t v1, crappy_vector_t v2) {
  crappy_vector_t res;
  res.x = v1.x - v2.x;
  res.y = v1.y - v2.y;
  return res;
}

crappy_vector_t mul_vector(crappy_vector_t v, float c) {
  crappy_vector_t res;
  res.x = v.x * c;
  res.y = v.y * c;
  return res;
}
