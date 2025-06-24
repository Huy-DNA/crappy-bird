#include <utils/crappy_screen.h>
#include <curses.h>

crappy_screen_t get_screen_size() {
  crappy_screen_t screen;
  getmaxyx(stdscr, screen.h, screen.w);
  return screen;
}
