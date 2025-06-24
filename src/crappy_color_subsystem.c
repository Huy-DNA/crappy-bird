#include <curses.h>
#include <crappy_color_subsystem.h>

void init_color_subsystem() {
  start_color();
  init_pair(GREEN_FG_IDX, COLOR_GREEN, COLOR_BLACK);
  init_pair(YELLOW_FG_IDX, COLOR_YELLOW, COLOR_BLACK);
}
