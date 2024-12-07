#ifndef OBJ_H
#define OBJ_H

#include <stdbool.h>

typedef struct obj_t {
  int x, y, origX, origY, forceX, forceY;
  short col;
  char repr;
  void (*show)(struct obj_t *);
  void (*shift)(struct obj_t *, bool);
} Obj;

Obj newObj(char repr, short col, int forceX, int forceY);

#endif // !OBJ_H
