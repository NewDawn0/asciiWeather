#ifndef RAIN_H
#define RAIN_H

#include "obj.h"
#include "weather.h"

typedef struct rain_container_t {
  WeatherContainer base;
  Obj *drops;
  unsigned int size;
} RainContainer;

RainContainer *newRainContainer();

#endif // !RAIN_H
