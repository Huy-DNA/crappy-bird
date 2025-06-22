#ifndef _BIRD_H_
#define _BIRD_H_

#include <crappy_camera.h>
#include <crappy_vector.h>
#include <stdbool.h>

typedef struct {
  crappy_vector_t p;
  crappy_vector_t v;
  crappy_vector_t a;
} crappy_bird_t;

bool init_bird(crappy_bird_t *);
void flap_bird(crappy_bird_t *);
void update_bird(crappy_bird_t *, int delta_us);
void draw_bird(crappy_bird_t *, crappy_camera_t *camera);
bool destroy_bird(crappy_bird_t *);

#endif // _BIRD_H_
