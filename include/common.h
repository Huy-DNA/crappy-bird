#ifndef _COMMON_H_
#define _COMMON_H_

#include <crappy_vector.h>

#define GRAVITY_PULL 5e-11
#define JUMP_FORCE -1.5e-5

#define BIRD_X_SPEED 1.5e-5

#define PIPE_X_SIZE 3
#define PIPE_Y_GAP 4

void draw(char, crappy_vector_t pos);

#endif // _COMMON_H_
