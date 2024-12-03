#include "config.h"
#include "display.h"
#include "obj.h"
#include "util.h"
#include <curses.h>
#include <stddef.h>
#include <unistd.h>

WeatherTypes weather = Rain;

int main(void) {
  Display main = newDisplay();
  main.init();
  main.loop();
  main.exit();
}
