#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdbool.h>

typedef struct {
  long long prev_ticked_us;
} crappy_timer_t;

bool init_timer(crappy_timer_t *);
long long delta_time(crappy_timer_t *);
void tick_timer(crappy_timer_t *, int fps);
bool destroy_timer(crappy_timer_t *);

#endif // _TIMER_H_
