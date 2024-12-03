#ifndef RAIN_H
#define RAIN_H

#include "obj.h"
#include <stddef.h>

typedef struct rain_container_t {
  Obj *drops;
  size_t size;
  void (*init)(struct rain_container_t *); // Constructor
  void (*exit)(struct rain_container_t *); // Destructor
  void (*show)(struct rain_container_t *); // Runst on first init
  void (*run)(struct rain_container_t *);  // Runs every frame
} RainContainer;

RainContainer newRainContainer();

#endif // !RAIN_H
