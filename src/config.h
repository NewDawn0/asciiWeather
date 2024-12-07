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

// Colours
// Rain
#define COL_RAIN_RAIN                                                          \
  { 4, 6, 12, 14, 32, 33, 38, 39, 68, 69, 81 }

// Snow
#define COL_SNOW_SNOW                                                          \
  { 0, 7, 15, 194, 195, 230, 231, 251, 252, 253, 254, 255 }
#define COL_SNOW_LEAVES                                                        \
  { 22, 23, 28, 29, 58, 59, 64, 65, 70, 71, 100, 101 }
#define COL_SNOW_TRUNK                                                         \
  { 94, 94, 130 }

// Autumn tree
#define COL_TREE_LEAVES                                                        \
  {                                                                            \
    1, 9, 197, 198, 202, 2023, 208, 209, 3, 11, 142, 221                       \
  } // 4x Red colour, 4x Orange colour, 4x Yellow colour

#define COL_LOG                                                                \
  { 94, 95, 96, 101, 130, 131, 172 }

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
