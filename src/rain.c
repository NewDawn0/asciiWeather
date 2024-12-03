#include "rain.h"
#include "obj.h"
#include <curses.h>
#include <stddef.h>
#include <stdlib.h>

void rainContainerInit(RainContainer *self);
void rainContainerExit(RainContainer *self);
void rainContainerShow(RainContainer *self);
void rainContainerRun(RainContainer *self);

RainContainer newRainContainer() {
  RainContainer out = {
      .drops = NULL,
      .init = rainContainerInit,
      .show = rainContainerShow,
      .run = rainContainerRun,
      .exit = rainContainerExit,
  };
  return out;
}

void rainContainerInit(RainContainer *self) {
  self->size = (size_t)getmaxx(stdscr) * 1.2;
  self->drops = malloc(self->size * sizeof(Obj));
  if (self->drops == NULL) {
    fprintf(stderr, "Failed to allocate memoray for objects\n");
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < self->size; i++) {
    self->drops[i] = newObj(':', 2, 1, 0);
  }
}

void rainContainerExit(RainContainer *self) {
  free(self->drops);
  self->drops = NULL;
  self->size = 0;
}

// Empty since rain doesn't need to print something on first run
void rainContainerShow(RainContainer *self) {}

void rainContainerRun(RainContainer *self) {
  for (size_t i = 0; i < self->size; i++) {
    self->drops[i].show(&self->drops[i]);
    self->drops[i].shift(&self->drops[i], true);
  }
}
