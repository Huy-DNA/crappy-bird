#ifndef _PIPE_RNG_H_
#define _PIPE_RNG_H_

#include <crappy_camera.h>
#include <crappy_vector.h>

bool init_pipe_rng();
void update_pipe_rng(crappy_camera_t *);
void draw_pipes(crappy_camera_t *);
bool destroy_pipe_rng();

#endif // _PIPE_RNG_H_
