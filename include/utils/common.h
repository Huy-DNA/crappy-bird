#ifndef _COMMON_H_
#define _COMMON_H_

#include <utils/crappy_vector.h>

#define GRAVITY_PULL 5e-11
#define JUMP_FORCE -1.5e-5

#define BIRD_X_SPEED 1.5e-5

#define PIPE_X_SIZE 6
#define PIPE_Y_GAP 7
#define PIPE_X_GAP 18

void draw(const char *, crappy_vector_t pos);

#endif // _COMMON_H_
