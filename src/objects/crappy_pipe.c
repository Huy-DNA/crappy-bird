#include <curses.h>
#include <objects/crappy_bird.h>
#include <objects/crappy_camera.h>
#include <objects/crappy_pipe.h>
#include <subsystems/crappy_color.h>
#include <utils/common.h>
#include <utils/crappy_screen.h>
#include <utils/crappy_vector.h>

void draw_pipe(crappy_pipe_t *pipe, crappy_camera_t *camera) {
  attron(COLOR_PAIR(GREEN_FG_IDX));
  for (int i = 0; i <= pipe->lower_left_upper_pipe_pos.y; ++i) {
    for (int w = 0; w < PIPE_X_SIZE; ++w) {
      crappy_vector_t pos;
      pos.y = i - camera->p.y;
      pos.x = pipe->lower_left_upper_pipe_pos.x + w - camera->p.x;
      draw("0", pos);
    }
  }

  crappy_screen_t screen = get_screen_size();
  for (int i = screen.h - 1;
       i >= pipe->lower_left_upper_pipe_pos.y + PIPE_Y_GAP; --i) {
    for (int w = 0; w < PIPE_X_SIZE; ++w) {
      crappy_vector_t pos;
      pos.y = i - camera->p.y;
      pos.x = pipe->lower_left_upper_pipe_pos.x + w - camera->p.x;
      draw("0", pos);
    }
  }
  attroff(COLOR_PAIR(GREEN_FG_IDX));
}

bool collide_pipe(crappy_bird_t *bird, crappy_pipe_t *pipe) {
  if (bird->p.x <= pipe->lower_left_upper_pipe_pos.x) {
    return false;
  }
  if (bird->p.x >= pipe->lower_left_upper_pipe_pos.x + PIPE_X_SIZE) {
    return false;
  }
  if (bird->p.y <= pipe->lower_left_upper_pipe_pos.y) {
    return true;
  }
  if (bird->p.y > pipe->lower_left_upper_pipe_pos.y + PIPE_Y_GAP) {
    return true;
  }
  return false;
}
