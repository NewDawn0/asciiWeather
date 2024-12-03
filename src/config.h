#ifndef CONFIG_H
#define CONFIG_H

typedef enum { Rain } WeatherTypes;

static inline const char *rainChars() {
  static const char out[2] = {'|', ':'};
  return out;
}
static inline const short *rainCols() {
  static const short out[2] = {1, 2};
  return out;
}

#endif // !CONFIG_H
