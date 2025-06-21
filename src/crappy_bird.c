#include <crappy_bird.h>
#include <curses.h>

bool init_bird(crappy_bird_t *bird) {
  bird->p.x = 0;
  bird->p.y = 0;

  bird->v.x = 0;
  bird->v.y = 0;

  bird->a.x = 0;
  bird->a.y = 0;

  return true;
}

void update_bird(crappy_bird_t *bird, int delta_us) {
  bird->p.x += bird->v.x * delta_us;
  bird->p.y += bird->v.y * delta_us;

  bird->v.x += bird->a.x * delta_us;
  bird->v.y += bird->a.y * delta_us;
}

void draw_bird(crappy_bird_t *bird) {
  move(bird->p.y, bird->p.x);
  printw(">");
}

bool destroy_bird(crappy_bird_t *bird) { return true; }
