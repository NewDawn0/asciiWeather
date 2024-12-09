#include "display.h"
#include "config.h"
#include "fall.h"
#include "obj.h"
#include "rain.h"
#include "snow.h"
#include "util.h"
#include "weather.h"
#include <curses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayInit();
void displayExit();
void displayLoop();
void menu();
void makeContainer(WeatherContainer **container);

extern WeatherTypes weather;
bool weatherChanged = false;
WeatherContainer *container = NULL;

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
  initscr();
  noecho();
  cbreak();
  curs_set(0);
  start_color();
  keypad(stdscr, TRUE);
  timeout(100);
  // Initialize colours
  for (int i = 0; i < COLORS; i++) {
    init_pair(i, i, COLOR_BLACK);
  }
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
  DrawContainer *drawfns = newDrawContainer();
  makeContainer(&container);
  container->init(container);
  container->show(container, drawfns);
  refresh();
  for (;;) {
    if (weatherChanged) {
      drawfns->clean(drawfns);
      makeContainer(&container);
      container->init(container);
      container->show(container, drawfns);
      refresh();
      weatherChanged = false;
    }
    clear();
    container->run(container);
    drawfns->show(drawfns);
    refresh();
    ch = getch();
    switch (ch) {
    case MENU_OPEN:
      menu();
      break;
    case QUIT_KEY:
    case QUIT_ESC:
      goto loopExit;
    }
  }
loopExit:
  container->exit(container);
  drawfns->exit(drawfns);
  return;
}

void menu() {
  int ch;
  int choice = 0;
  const int numChoices = len(MENU_CHOICES);
  const int height = numChoices + 2; // +2 for borders
  const int startX = (getmaxx(stdscr) - MENU_WIDTH) / 2;
  const int startY = (getmaxy(stdscr) - height) / 2;
  // Menu setup
  WINDOW *menuWin = newwin(height, MENU_WIDTH, startY, startX);
  keypad(menuWin, TRUE);
  wattron(menuWin, COLOR_PAIR(2));
  box(menuWin, MENU_CHARS[0], MENU_CHARS[1]);
  wattroff(menuWin, COLOR_PAIR(2));
  mvwprintw(menuWin, 0, (MENU_WIDTH - strlen(MENU_TITLE)) / 2, "%s",
            MENU_TITLE);

  // Check keys
  for (;;) {
    for (int i = 0; i < numChoices; i++) {
      int spaces = MENU_WIDTH - strlen(MENU_CHOICES[i]) - 5;
      if (i == choice) {
        wattron(menuWin, A_REVERSE);
        mvwprintw(menuWin, i + 1, 1, " * %s%*s", MENU_CHOICES[i], spaces, "");
      } else {
        wattroff(menuWin, A_REVERSE);
        mvwprintw(menuWin, i + 1, 1, "   %s%*s", MENU_CHOICES[i], spaces, "");
      }
    }
    wrefresh(menuWin);
    switch (getch()) {
    case KEY_UP:
    case MENU_UP:
      // Flip to last choice if at top
      if (choice == 0) {
        choice = numChoices - 1;
      } else {
        choice -= 1;
      }
      break;
    case KEY_DOWN:
    case MENU_DOWN:
      // Flip to last choice if at bottom
      if (choice == numChoices - 1) {
        choice = 0;
      } else {
        choice += 1;
      }
      break;
    case '\n': // Confirm with enter
      goto loopExit;
    case QUIT_KEY:
    case QUIT_ESC:
      goto loopExit;
    }
  }
loopExit:
  weatherChanged = true;
  delwin(menuWin);
  weather = choice;
}

void makeContainer(WeatherContainer **container) {
  switch (weather) {
  case Rain:
    *container = (WeatherContainer *)newRainContainer();
    break;
  case Snow:
    *container = (WeatherContainer *)newSnowContainer();
    break;
  }
}
