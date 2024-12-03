#include "util.h"
#include <stdlib.h>

int randRange(int min, int max) {
  if (min > max) {
    int tmp = min;
    min = max;
    max = tmp;
  }
  return min + rand() % (max - min);
}
