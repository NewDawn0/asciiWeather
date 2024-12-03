#include "util.h"
#include "config.h"
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
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-h")) {
      help();
      exit(EXIT_SUCCESS);
    }
  } else {
    printf("%sError:%s Only one arg was expected\n", RED, NC);
    help();
    exit(EXIT_SUCCESS);
  }
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
