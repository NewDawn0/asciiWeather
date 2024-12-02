#ifndef DISPLAY_H
#define DISPLAY_H

struct display_t {
  void (*init)();
  void (*exit)();
};

typedef struct display_t Display;

Display newDisplay();

#endif // !DISPLAY_H
