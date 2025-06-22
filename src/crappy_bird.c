#include <crappy_camera.h>
#include <crappy_screen.h>
#include <common.h>
#include <crappy_bird.h>
#include <crappy_vector.h>
#include <curses.h>

bool init_bird(crappy_bird_t *bird) {
  crappy_screen_t screen = get_screen_size();

  bird->p.x = screen.w / 5.0;
  bird->p.y = screen.h / 2.0;

  bird->v.x = BIRD_X_SPEED;
  bird->v.y = 0;

  bird->a.x = 0;
  bird->a.y = GRAVITY_PULL;

  return true;
}

void flap_bird(crappy_bird_t *bird) {
  if (bird->v.y > 0) {
    bird->v.y = JUMP_FORCE;
  }
}

void update_bird(crappy_bird_t *bird, int delta_us) {
  bird->p = add_vector(bird->p, mul_vector(bird->v, delta_us));
  bird->v = add_vector(bird->v, mul_vector(bird->a, delta_us));
}

void draw_bird(crappy_bird_t *bird, crappy_camera_t *camera) {
  move(bird->p.y - camera->p.y, bird->p.x - camera->p.x);
  printw(">");
}

bool destroy_bird(crappy_bird_t *bird) { return true; }
