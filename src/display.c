#include "display.h"
#include <curses.h>

void displayInit();
void displayExit();

Display newDisplay() {
  Display out = {
      .init = displayInit,
      .exit = displayExit,
  };
  return out;
}

void displayInit() {
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  keypad(stdscr, TRUE);
}

void displayExit() {
  curs_set(1);
  clear();
  refresh();
  resetty();
  endwin();
}
