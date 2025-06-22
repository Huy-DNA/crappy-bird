#include <common.h>
#include <crappy_screen.h>
#include <curses.h>

void draw(char c, crappy_vector_t pos) {
  crappy_screen_t screen = get_screen_size();

  if (pos.x < 0 || pos.x >= screen.w) {
    return;
  }

  if (pos.y < 0 || pos.y >= screen.h) {
    return;
  }

  move(pos.y, pos.x);
  printw("%c", c);
}
