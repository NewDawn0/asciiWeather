#ifndef OBJ_H
#define OBJ_H

typedef struct obj_t {
  int x, y, origX, origY, forceX, forceY;
  char repr;
  void (*show)(struct obj_t *);
  void (*shift)(struct obj_t *);
} Obj;

Obj newObj();

#endif // !OBJ_H
