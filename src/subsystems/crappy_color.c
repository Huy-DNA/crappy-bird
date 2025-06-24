#include <curses.h>
#include <subsystems/crappy_color.h>

void init_color_subsystem() {
  start_color();
  init_pair(GREEN_FG_IDX, COLOR_GREEN, COLOR_BLACK);
  init_pair(YELLOW_FG_IDX, COLOR_YELLOW, COLOR_BLACK);
}
