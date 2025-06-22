#include <common.h>
#include <crappy_camera.h>

bool init_camera(crappy_camera_t *camera) {
  camera->p.x = 0;
  camera->p.y = 0;

  camera->v.x = BIRD_X_SPEED;
  camera->v.y = 0;

  camera->a.x = 0;
  camera->a.y = 0;

  return true;
}

void update_camera(crappy_camera_t *camera, int delta_us) {
  camera->p = add_vector(camera->p, mul_vector(camera->v, delta_us));
}

bool destroy_camera(crappy_camera_t *camera) { return true; }
