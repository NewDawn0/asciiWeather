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
  RainContainer container = newRainContainer();
  container.init(&container);
  container.show(&container);
  for (;;) {
    clear();
    container.run(&container);
    refresh();
    ch = getch();
    switch (ch) {
    case 'q':
    case 27:
      return;
    }
  }
}
