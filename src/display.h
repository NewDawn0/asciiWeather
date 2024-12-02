#ifndef DISPLAY_H
#define DISPLAY_H

typedef struct display_t {
  void (*init)();
  void (*exit)();
} Display;

Display newDisplay();

#endif // !DISPLAY_H
