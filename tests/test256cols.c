#include <curses.h>
int main() {
  initscr();
  start_color();
  use_default_colors();
  int j = 0;
  int x = 0;
  for (int i = 0; i < COLORS; i++) {
    x += 4;
    init_pair(i, i, COLOR_BLACK);
    attron(COLOR_PAIR(i));
    mvprintw(j, x, "%d", i);
    if (i % 10 == 0) {
      j++;
      x = 0;
    }
    attroff(COLOR_PAIR(i));
  }
  getch();
  endwin();
}
