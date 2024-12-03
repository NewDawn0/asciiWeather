#include "obj.h"
#include "config.h"
#include "util.h"
#include <curses.h>
#include <stdbool.h>

void objShow(Obj *self);
void objShift(Obj *self, bool rand);

const char *RAIN_CHARS;
const short *RAIN_COLS;
const char *SNOW_CHARS;
extern WeatherTypes weather;

void initExternCfg() {
  RAIN_CHARS = rainChars();
  RAIN_COLS = rainCols();
  SNOW_CHARS = snowChars();
}

Obj newObj(char repr, short col, int forceX, int forceY) {
  int typeRepr = randRange(1, 3); // Set type representation
  Obj out = {
      .x = randRange(0, getmaxx(stdscr) - 1),
      .y = randRange(0, getmaxy(stdscr) - 1),
      .origY = 0,
      // @FIX: I don't know why but forceX and forceY need to be switched
      .forceX = forceY,
      .forceY = forceX,
      .col = col,
      .repr = repr,
      .show = objShow,
      .shift = objShift,
  };
  out.origX = out.x;
  return out;
}

void objShow(Obj *self) {
  attron(COLOR_PAIR(self->col));
  mvaddch(self->y, self->x, self->repr);
}

void objShift(Obj *self, bool rand) {
  self->x += self->forceX;
  self->y += self->forceY;
  // Bottom & top
  if (self->y >= getmaxy(stdscr) || self->y <= -1) {
    self->y = self->origY;
    if (rand)
      self->x = randRange(0, getmaxx(stdscr) - 1);
    if (!rand)
      self->x = self->origX;
  }
  // Right & left
  if (self->x >= getmaxx(stdscr) || self->x <= -1) {
    self->y = self->origY;
    if (rand)
      self->x = randRange(0, getmaxx(stdscr) - 1);
    if (!rand)
      self->x = self->origX;
  }
}
