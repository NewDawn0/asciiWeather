#include "display.h"
#include <curses.h>
#include <stdlib.h>

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
  timeout(100); // 100ms for non blocking getch
  keypad(stdscr, TRUE);
}

void displayExit() {
  curs_set(1);
  clear();
  refresh();
  resetty();
  endwin();
}
