#include "obj.h"
#include "config.h"
#include "util.h"
#include <curses.h>

void objShow(Obj *self);
void objShift(Obj *self);

const char *RAIN_CHARS;
const short *RAIN_COLS;
extern WeatherTypes weatherType;

void initExternCfg() {
  RAIN_CHARS = rainChars();
  RAIN_COLS = rainCols();
}

Obj newObj() {
  Obj out = {
      .x = randRange(0, getmaxx(stdscr) - 1),
      .y = 0,
      .origX = 0,
      .origY = 0,
      .forceX = 0, // No x force
      .forceY = 1, // Default falling down
      .repr = 'a',
      .show = objShow,
      .shift = objShift,
  };
  return out;
}

void objShow(Obj *self) { mvaddch(self->y, self->x, self->repr); }

void objShift(Obj *self) {
  self->x += self->forceX;
  self->y += self->forceY;
  // Bottom & top
  if (self->y >= getmaxy(stdscr) || self->y <= -1) {
    self->y = self->origY;
  }
  // Right & left
  if (self->x >= getmaxx(stdscr) || self->x <= -1) {
    self->y = self->origY;
  }
}
