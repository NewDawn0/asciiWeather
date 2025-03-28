#include "util.h"
#include "config.h"
#include <curses.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *RED = "\x1b[1;31m";
const char *CYAN = "\x1b[1;36m";
const char *BLUE = "\x1b[1;34m";
const char *NC = "\x1b[0m";

void help();
void drawContainerExit(DrawContainer *self);
void drawContainerShow(DrawContainer *self);
void drawContainerAdd(DrawContainer *self, short col, int x, int y, char repr);
void drawContainerClean(DrawContainer *self);

int randRange(int min, int max) {
  if (min > max) {
    int tmp = min;
    min = max;
    max = tmp;
  }
  return min + rand() % (max - min);
}

int *randSel(int *arr, size_t size) {
  if (arr == NULL || size < 2) {
    return arr;
  }
  for (size_t i = size - 1; i > 0; i--) {
    size_t j = rand() % (i + 1);
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
  return arr;
}

void parseArgs(WeatherTypes *weather, int argc, char **argv) {
  int menuLen;
  MENU_CHOICES(&menuLen);
  if (argc == 1) {
    *weather = Rain; // Default to rain
  } else if (argc == 2) {
    const char *xs[] = {"-h", "--help"};
    int idx;
    if (in(argv[1], xs, len(xs)) != -1) {
      help();
      exit(EXIT_SUCCESS);
    } else if ((idx = in(argv[1], MENU_CHOICES(NULL), menuLen)) != -1) {
      *weather = idx;
    } else {
      printf("%sError:%s Unrecognized argument: %s\n", RED, NC, argv[1]);
      help();
      exit(EXIT_FAILURE);
    }
  } else {
    printf("%sError:%s Only one arg was expected\n", RED, NC);
    help();
    exit(EXIT_FAILURE);
  }
}

int in(char *x, const char **xs, size_t xsSize) {
  for (size_t i = 0; i < xsSize; i++) {
    if (strcmp(x, xs[i]) == 0)
      return i;
  }
  return -1;
}

void help() {
  printf(
      "%sascii-weather%s\n" // BLUE, NC
      "   Copyright NewDawn0 2024\n"
      "   Project: https://github.com/NewDawn0/asciiWeather\n"
      "\n%sUSAGE:%s\n" // BLUE, NC
      "   ascii-weather <weather>\n"
      "   ascii-weather <options>\n"
      "\n%sOptions:%s\n"                               // BLUE, NC
      "   <weather> -> Any of: %sRain%s | %sSnow%s \n" // CYAN, NC, CYAN, NC
      "   <options> -> %s-h%s | %s--help%s (Shows the help menu)\n" // CYAN, NC,
                                                                    // CYAN, NC
      ,
      BLUE, NC, BLUE, NC, BLUE, NC, CYAN, NC, CYAN, NC, CYAN, NC, CYAN, NC);
}

DrawContainer *newDrawContainer() {
  DrawContainer *out = malloc(sizeof(DrawContainer));
  out->exit = drawContainerExit;
  out->show = drawContainerShow;
  out->add = drawContainerAdd;
  out->clean = drawContainerClean;
  out->idx = 0;
  return out;
}

void drawContainerExit(DrawContainer *self) {
  free(self);
  self = NULL;
}

void drawContainerShow(DrawContainer *self) {
  for (size_t i = 0; i < self->idx; i++) {
    attron(COLOR_PAIR(self->objs[i].col));
    mvprintw(self->objs[i].y, self->objs[i].x, "%c", self->objs[i].repr);
    attroff(COLOR_PAIR(self->objs[i].col));
  }
}

void drawContainerAdd(DrawContainer *self, short col, int x, int y, char repr) {
  struct draw_obj_t obj = {
      .col = col,
      .x = x,
      .y = y,
      .repr = repr,
  };
  self->objs[self->idx] = obj;
  self->idx++;
}

void drawContainerClean(DrawContainer *self) { self->idx = 0; }
