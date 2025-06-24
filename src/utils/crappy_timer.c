#include <utils/crappy_timer.h>
#include <stdbool.h>
#include <time.h>

bool init_timer(crappy_timer_t *timer) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  timer->prev_ticked_us = ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;
  return true;
}

long long delta_time(crappy_timer_t *timer) {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  long long current_us = ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;
  return current_us - timer->prev_ticked_us;
}

void tick_timer(crappy_timer_t *timer, int fps) {
  while (delta_time(timer) < 1000000 / fps) {
    // do nothing
  }
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  timer->prev_ticked_us = ts.tv_sec * 1000000ULL + ts.tv_nsec / 1000;
}

bool destroy_timer(crappy_timer_t *timer) { return true; }
