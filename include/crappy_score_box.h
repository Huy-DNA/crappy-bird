#ifndef _SCORE_H_
#define _SCORE_H_

#include <crappy_camera.h>

typedef struct {
  double score;
} crappy_score_t;

bool init_score_box(crappy_score_t *);
void add_score(crappy_score_t *, double);
void draw_score_box(crappy_score_t *, crappy_camera_t *);
bool destroy_score_box(crappy_score_t *);

#endif // _SCORE_H_
