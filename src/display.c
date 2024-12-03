#include "display.h"
#include "obj.h"
#include <curses.h>
#include <stdlib.h>
#include <time.h>

void displayInit();
void displayExit();
void displayLoop();

Display newDisplay() {
  Display out = {
      .init = displayInit,
      .exit = displayExit,
      .loop = displayLoop,
  };
  return out;
}

void displayInit() {
  srand(time(NULL));
  initExternCfg();
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  timeout(100); // 100ms for non blocking getch
  keypad(stdscr, TRUE);
  // Initialize colours
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
}

void displayExit() {
  curs_set(1);
  clear();
  refresh();
  resetty();
  endwin();
  printf("Exiting...\n");
}

void displayLoop() {
  int ch;
  int a = getmaxx(stdscr) * 1.2;
  Obj objs[a];
  for (size_t i = 0; i < (size_t)a; i++) {
    objs[i] = newObj();
  }
  for (;;) {
    clear();
    for (size_t i = 0; i < (size_t)a; i++) {
      objs[i].show(&objs[i]);
      objs[i].shift(&objs[i], true);
    }
    refresh();
    ch = getch();
    switch (ch) {
    case 'q':
    case 27:
      return;
    }
  }
}
