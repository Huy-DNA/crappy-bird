#include "crappy_timer.h"
#include <curses.h>
#include <stdlib.h>

void init() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
}

void finalize() {
  endwin();
  exit(0);
}

void game_loop() {
  crappy_timer_t timer;
  init_timer(&timer);
  while (true) {
    tick_timer(&timer, 30);
  }
  destroy_timer(&timer);
}

int main() {
  init();
  game_loop();
  finalize();
}
