#ifndef UTIL_H
#define UTIL_H

#include "config.h"
#include <stdbool.h>
#include <stddef.h>

#define len(array) (sizeof(array) / sizeof((array)[0]))

int randRange(int min, int max);

void parseArgs(WeatherTypes *weather, int argc, char **argv);

int in(char *x, const char *xs[], size_t xsSize);

#endif // !UTIL_H
