#include "obj.h"
#include "config.h"
#include "util.h"
#include <curses.h>
#include <stdbool.h>

void objShow(Obj *self);
void objShift(Obj *self, bool rand);

const char *RAIN_CHARS;
const short *RAIN_COLS;
extern WeatherTypes weatherType;

void initExternCfg() {
  RAIN_CHARS = rainChars();
  RAIN_COLS = rainCols();
}

Obj newObj() {
  int typeRepr = randRange(1, 3); // Set type representation
  Obj out = {
      .x = randRange(0, getmaxx(stdscr) - 1),
      .y = randRange(0, getmaxy(stdscr) - 1),
      .forceX = 0, // No x force
      .show = objShow,
      .shift = objShift,
  };
  switch (weatherType) {
  case Rain:
    out.repr = (typeRepr < 2) ? RAIN_CHARS[0] : RAIN_CHARS[1];
    out.col = (randRange(1, 4) < 2) ? 1 : 2;
    // Different speeds for different drops
    if (typeRepr < 2) {
      out.forceY = 1;
    } else {
      out.forceY = randRange(1, 3);
    }
    break;
  }
  out.origX = out.x;
  out.origY = 0;
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
