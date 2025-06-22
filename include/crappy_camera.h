#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <crappy_vector.h>
#include <stdbool.h>

typedef struct {
  crappy_vector_t p;
  crappy_vector_t v;
  crappy_vector_t a;
} crappy_camera_t;

bool init_camera(crappy_camera_t *);
void update_camera(crappy_camera_t *, int delta_us);
bool destroy_camera(crappy_camera_t *);

#endif // _CAMERA_H_
