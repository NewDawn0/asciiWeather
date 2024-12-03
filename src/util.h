#ifndef UTIL_H
#define UTIL_H

#include "config.h"

#define len(array) (sizeof(array) / sizeof(array[0]))

int randRange(int min, int max);

void parseArgs(WeatherTypes *weather, int argc, char **argv);

#endif // !UTIL_H
