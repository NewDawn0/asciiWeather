#include "util.h"
#include "config.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *RED = "\x1b[1;31m";
const char *CYAN = "\x1b[1;36m";
const char *BLUE = "\x1b[1;34m";
const char *NC = "\x1b[0m";

void help();

int randRange(int min, int max) {
  if (min > max) {
    int tmp = min;
    min = max;
    max = tmp;
  }
  return min + rand() % (max - min);
}

void parseArgs(WeatherTypes *weather, int argc, char **argv) {
  if (argc == 1) {
    *weather = Rain; // Default to rain
  } else if (argc == 2) {
    const char *xs[] = {"-h", "--help"};
    int idx;
    if (in(argv[1], xs, len(xs)) != -1) {
      help();
      exit(EXIT_SUCCESS);
    } else if ((idx = in(argv[1], MENU_CHOICES, len(MENU_CHOICES))) != -1) {
      *weather = idx;
    } else {
      printf("%sError:%s Unrecognized argument: %s\n", RED, NC, argv[1]);
      help();
      exit(EXIT_FAILURE);
    }
  } else {
    printf("%sError:%s Only one arg was expected\n", RED, NC);
    help();
    exit(EXIT_FAILURE);
  }
}

int in(char *x, const char **xs, size_t xsSize) {
  for (int i = 0; i < xsSize; i++) {
    if (strcmp(x, xs[i]) == 0)
      return i;
  }
  return -1;
}

void help() {
  printf(
      "%sascii-weather%s\n" // BLUE, NC
      "   Copyright NewDawn0 2024\n"
      "   Project: https://github.com/NewDawn0/asciiWeather\n"
      "\n%sUSAGE:%s\n" // BLUE, NC
      "   ascii-weather <weather>\n"
      "   ascii-weather <options>\n"
      "\n%sOptions:%s\n"                              // BLUE, NC
      "   <weather> -> Any of: %sRain%s | %sSnow%s\n" // CYAN, NC, CYAN, NC
      "   <options> -> %s-h%s | %s--help%s (Shows the help menu)\n" // CYAN, NC,
                                                                    // CYAN, NC
      ,
      BLUE, NC, BLUE, NC, BLUE, NC, CYAN, NC, CYAN, NC, CYAN, NC, CYAN, NC);
}
