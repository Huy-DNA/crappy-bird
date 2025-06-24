#include <curses.h>
#include <objects/crappy_camera.h>
#include <objects/crappy_score_box.h>
#include <stdio.h>
#include <utils/common.h>
#include <utils/crappy_screen.h>
#include <utils/crappy_vector.h>

bool init_score_box(crappy_score_t *score) {
  score->score = 0;
  return true;
}

void add_score(crappy_score_t *score, double inc) { score->score += inc; }

void draw_score_box(crappy_score_t *score, crappy_camera_t *camera) {
  char score_line[512];
  sprintf(score_line, "|Score: %-5d|", (int)score->score);
  draw(score_line, create_vector(3, 2));
  draw("==============", create_vector(3, 1));
  draw("==============", create_vector(3, 3));
}

bool destroy_score_box(crappy_score_t *score) { return true; }
