#include <crappy_bird.h>
#include <crappy_vector.h>
#include <curses.h>

bool init_bird(crappy_bird_t *bird) {
  bird->p.x = 0;
  bird->p.y = 0;

  bird->v.x = 0;
  bird->v.y = 0;

  bird->a.x = 0;
  bird->a.y = 5e-11;

  return true;
}

void update_bird(crappy_bird_t *bird, int delta_us) {
  bird->p = add_vector(bird->p, mul_vector(bird->v, delta_us));
  bird->v = add_vector(bird->v, mul_vector(bird->a, delta_us));
}

void draw_bird(crappy_bird_t *bird) {
  move(bird->p.y, bird->p.x);
  printw(">");
}

bool destroy_bird(crappy_bird_t *bird) { return true; }
