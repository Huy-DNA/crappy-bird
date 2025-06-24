#include <objects/crappy_camera.h>
#include <objects/crappy_pipe.h>
#include <stdlib.h>
#include <utils/common.h>
#include <utils/crappy_screen.h>
#include <utils/crappy_vector.h>

#define PIPE_SIZE 300
static crappy_pipe_t pipes[PIPE_SIZE];

bool init_pipe_rng() {
  int pipe_idx = 0;
  pipes[pipe_idx].lower_left_upper_pipe_pos.x = get_screen_size().w * 4.0 / 5;
  pipes[pipe_idx].lower_left_upper_pipe_pos.y =
      rand() % (get_screen_size().h - PIPE_Y_GAP);

  for (pipe_idx = 1; pipe_idx < PIPE_SIZE; ++pipe_idx) {
    pipes[pipe_idx].lower_left_upper_pipe_pos.x =
        pipes[pipe_idx - 1].lower_left_upper_pipe_pos.x + PIPE_X_GAP +
        PIPE_X_GAP;
    pipes[pipe_idx].lower_left_upper_pipe_pos.y =
        rand() % (get_screen_size().h - PIPE_Y_GAP);
  }

  return true;
}

void update_pipe_rng(crappy_camera_t *camera) {
  if (pipes[0].lower_left_upper_pipe_pos.x + PIPE_X_SIZE < camera->p.x) {
    for (int i = 0; i < PIPE_SIZE - 1; ++i) {
      pipes[i] = pipes[i + 1];
    }
  }
  pipes[PIPE_SIZE - 1].lower_left_upper_pipe_pos.x =
      pipes[PIPE_SIZE - 2].lower_left_upper_pipe_pos.x + PIPE_X_GAP +
      PIPE_X_GAP;
  pipes[PIPE_SIZE - 1].lower_left_upper_pipe_pos.y =
      rand() % (get_screen_size().h - PIPE_Y_GAP);
}

void draw_pipes(crappy_camera_t *camera) {
  for (int i = 0; i < PIPE_SIZE; ++i) {
    draw_pipe(&pipes[i], camera);
  }
}

bool collide_pipes(crappy_bird_t *bird) {
  for (int i = 0; i < PIPE_SIZE; ++i) {
    if (collide_pipe(bird, &pipes[i])) {
      return true;
    }
  }
  return false;
}

bool destroy_pipe_rng() { return true; }
