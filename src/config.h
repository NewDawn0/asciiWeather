#ifndef CONFIG_H
#define CONFIG_H

// General
static const int QUIT_KEY = 'q'; // QUit with q and ESC
static const int QUIT_ESC = 27;

// Weather types
typedef enum { Rain, Snow } WeatherTypes;

// Rain
static inline const char *rainChars() {
  static const char out[2] = {'|', ':'};
  return out;
}
static inline const short *rainCols() {
  static const short out[2] = {1, 2};
  return out;
}

// Snow
static inline const char *snowChars() {
  static const char out[2] = {'*', '.'};
  return out;
}
#define SNOW_COLS 3

// Menu
static const char MENU_OPEN = 'm';
static const char MENU_CHARS[2] = {'|', '-'};
static const char *MENU_CHOICES[2] = {"Rain", "Snow"};
static const char MENU_UP = 'k';
static const char MENU_DOWN = 'j';
#define MENU_WIDTH 30                // u short
#define MENU_TITLE "Select weather:" // char*

#endif // !CONFIG_H
