#include "config.h"
#include "display.h"
#include "obj.h"
#include "util.h"
#include <curses.h>
#include <stddef.h>
#include <unistd.h>

WeatherTypes weather;

int main(int argc, char **argv) {
  parseArgs(&weather, argc, argv);
  Display main = newDisplay();
  main.init();
  main.loop();
  main.exit();
  printf("Exiting...\n");
}
