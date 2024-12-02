#include "util.h"
#include <stdlib.h>

int randRange(int min, int max) { return min + rand() % (max - min + 1); }
