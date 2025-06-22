#include <crappy_pipe_rng.h>
#include <crappy_pipe.h>
#include <crappy_camera.h>
#include <crappy_bird.h>
#include <crappy_timer.h>
#include <curses.h>
#include <stdlib.h>

void init() {
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
  timeout(10);
}

void finalize() {
  endwin();
  exit(0);
}

void game_loop() {
  crappy_timer_t timer;
  crappy_bird_t bird;
  crappy_camera_t camera;
  init_timer(&timer);
  init_bird(&bird);
  init_camera(&camera);
  init_pipe_rng();
  while (true) {
    // handle input
    int c = getch();
    if (c == 'q')
      break;

    if (c == ' ') {
      flap_bird(&bird);
    }
    // state update
    update_camera(&camera, delta_time(&timer));
    update_bird(&bird, delta_time(&timer));

    // draw
    erase();
    draw_bird(&bird, &camera);
    refresh();

    // epilogue
    tick_timer(&timer, 30);
  }
  destroy_pipe_rng();
  destroy_camera(&camera);
  destroy_bird(&bird);
  destroy_timer(&timer);
}

int main() {
  init();
  game_loop();
  finalize();
}
