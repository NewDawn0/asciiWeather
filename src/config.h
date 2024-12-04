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

// COLS
#define COL_BLUE                                                               \
  { 4, 6, 12, 14, 32, 33, 38, 39, 68, 69, 81 }

#define COL_RED                                                                \
  { 1, 9, 160, 161, 196, 197 }

#define COL_YELLOW                                                             \
  { 3, 11, 184, 185, 186, 178, 179, 221, 222, 223, 226, 227, 228, 229 }

#define COL_ORANGE                                                             \
  { 166, 167, 202, 203, 208 }

#define COL_PINK                                                               \
  { 198, 199, 200, 201, 206, 207, 211, 212, 213, 219 }

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
