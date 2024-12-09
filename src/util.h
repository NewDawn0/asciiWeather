#ifndef UTIL_H
#define UTIL_H

#include "config.h"
#include <stdbool.h>
#include <stddef.h>

#define len(array) (sizeof(array) / sizeof((array)[0]))

struct draw_obj_t {
  short col;
  int x, y;
  char repr;
};
typedef struct draw_container_t {
  size_t idx;
  struct draw_obj_t objs[4096];
  void (*show)(struct draw_container_t *);
  void (*exit)(struct draw_container_t *);
  void (*add)(struct draw_container_t *, short col, int x, int y, char repr);
  void (*clean)(struct draw_container_t *);
} DrawContainer;

DrawContainer *newDrawContainer(); // initial size

int randRange(int min, int max);
int *randSel(int *arr, size_t size);

void parseArgs(WeatherTypes *weather, int argc, char **argv);

int in(char *x, const char *xs[], size_t xsSize);

#endif // !UTIL_H
