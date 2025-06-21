#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdbool.h>

typedef struct {
  int x;
  int y;
} crappy_vector_t;

crappy_vector_t add_vector(crappy_vector_t, crappy_vector_t);
crappy_vector_t sub_vector(crappy_vector_t, crappy_vector_t);
crappy_vector_t mul_vector(crappy_vector_t, float);

#endif // _VECTOR_H_
