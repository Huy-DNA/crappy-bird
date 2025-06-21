#include <crappy_bird.h>
#include <crappy_timer.h>
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
  crappy_bird_t bird;
  init_bird(&bird);
  while (true) {
    // state update
    update_bird(&bird, delta_time(&timer));

    // draw
    erase();
    draw_bird(&bird);
    refresh();

    // epilogue
    tick_timer(&timer, 30);
  }
  destroy_bird(&bird);
  destroy_timer(&timer);
}

int main() {
  init();
  game_loop();
  finalize();
}
