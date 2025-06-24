#include <common.h>
#include <crappy_screen.h>
#include <curses.h>

// FIXME: Not handle newlines just yet!
void draw(const char *s, crappy_vector_t pos) {
  crappy_screen_t screen = get_screen_size();

  if (pos.y < 0 || pos.y >= screen.h) {
    return;
  }

  for (int i = 0; s[i] != '\0'; ++i) {
    if (pos.x + i < 0 || pos.x + i >= screen.w) {
      continue;
    }
    move(pos.y, pos.x + i);
    printw("%c", s[i]);
  }
}
