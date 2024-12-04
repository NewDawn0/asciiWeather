#include "rain.h"
#include "obj.h"
#include "weather.h"
#include <curses.h>
#include <stddef.h>
#include <stdlib.h>

void rainContainerInit(WeatherContainer *self);
void rainContainerExit(WeatherContainer *self);
void rainContainerShow(WeatherContainer *self);
void rainContainerRun(WeatherContainer *self);

RainContainer *newRainContainer() {
  RainContainer *out = malloc(sizeof(RainContainer));
  out->base.init = rainContainerInit;
  out->base.exit = rainContainerExit;
  out->base.show = rainContainerShow;
  out->base.run = rainContainerRun;
  out->drops = NULL;
  return out;
}

void rainContainerInit(WeatherContainer *self) {
  RainContainer *cself = (RainContainer *)self; // Casted-self
  cself->size = (size_t)getmaxx(stdscr) * 1.2;
  cself->drops = malloc(cself->size * sizeof(Obj));
  if (cself->drops == NULL) {
    fprintf(stderr, "Failed to allocate memoray for objects\n");
    exit(EXIT_FAILURE);
  }
  for (size_t i = 0; i < cself->size; i++) {
    cself->drops[i] = newObj(':', 2, 1, 0);
  }
}

void rainContainerExit(WeatherContainer *self) {
  RainContainer *cself = (RainContainer *)self;
  free(cself->drops);
  cself->drops = NULL;
  cself->size = 0;
  free(self);
}

// Empty since rain doesn't need to print something on first run
void rainContainerShow(WeatherContainer *self) {}

void rainContainerRun(WeatherContainer *self) {
  RainContainer *cself = (RainContainer *)self;
  for (size_t i = 0; i < cself->size; i++) {
    cself->drops[i].show(&cself->drops[i]);
    cself->drops[i].shift(&cself->drops[i], true);
  }
}
