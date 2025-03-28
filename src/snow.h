#ifndef SNOW_H
#define SNOW_H

#include "obj.h"
#include "weather.h"
#include <stddef.h>

typedef struct snow_container_t {
  WeatherContainer base;
  Obj *flakes;
  unsigned int size;
} SnowContainer;

SnowContainer *newSnowContainer();

#endif // !SNOW_H
