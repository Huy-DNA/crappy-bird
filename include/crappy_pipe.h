#ifndef _PIPE_H_
#define _PIPE_H_

#include <crappy_bird.h>
#include <crappy_camera.h>
#include <crappy_vector.h>

/*
 *             000
 *             000
 *           ->000
 *           |
 *         lower_left_upper_pipe_pos
 *
 *
 *             000
 *             000
 *             000
 *             000
 * */

typedef struct {
  crappy_vector_t lower_left_upper_pipe_pos;
} crappy_pipe_t;

void draw_pipe(crappy_pipe_t *, crappy_camera_t *);

bool collide_pipe(crappy_bird_t *, crappy_pipe_t *);

#endif // _PIPE_H_
