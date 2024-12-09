#ifndef WEATHER_H
#define WEATHER_H

#include "util.h"

// Common weather interface
typedef struct weather_container_t {
  void (*init)(struct weather_container_t *); // Constructor
  void (*exit)(struct weather_container_t *); // Destructor
  void (*show)(struct weather_container_t *,
               DrawContainer *);             // Runs on first init
  void (*run)(struct weather_container_t *); // Runs every frame
} WeatherContainer;

#endif // !WEATHER_H
