#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <stdbool.h>

typedef struct {
  int w;
  int h;
} crappy_screen_t;

crappy_screen_t get_screen_size();

#endif // _CAMERA_H_
