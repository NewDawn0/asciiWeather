#include "snow.h"
#include "obj.h"
#include "util.h"
#include "weather.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

void snowContainerInit(WeatherContainer *self);
void snowContainerExit(WeatherContainer *self);
void snowContainerShow(WeatherContainer *self, DrawContainer *drawfns);
void snowContainerRun(WeatherContainer *self);
void drawTree(size_t xPos, DrawContainer *drawfns);

SnowContainer *newSnowContainer() {
  SnowContainer *out = malloc(sizeof(SnowContainer));
  out->flakes = NULL;
  out->base.init = snowContainerInit;
  out->base.exit = snowContainerExit;
  out->base.show = snowContainerShow;
  out->base.run = snowContainerRun;
  return out;
}

void snowContainerInit(WeatherContainer *self) {
  SnowContainer *cself = (SnowContainer *)self;
  cself->size = (size_t)getmaxx(stdscr) * 1.5;
  cself->flakes = malloc(cself->size * sizeof(Obj));
  if (cself->flakes == NULL) {
    fprintf(stderr, "Failed to allocate memory for objects\n");
    exit(EXIT_FAILURE);
  }
  unsigned char randType, speed;
  char ch;
  short col;
  short snowCols[] = COL_SNOW_SNOW;
  char types[] = {'*', '.', '+', 'o', '-', '~', '^', '"'};
  for (unsigned int i = 0; i < cself->size; i++) {
    randType = randRange(0, 10);
    speed = (randType < 2) ? randRange(1, 2) : randRange(1, 3);
    if (randType <= 1) {
      ch = types[0];
    } else if (randType <= 1 || randType <= 2) {
      ch = types[1];
    } else {
      ch = types[randType - 2];
    }
    col = randRange(0, len(snowCols));
    cself->flakes[i] = newObj(ch, snowCols[col], speed, 0);
  }
}

void snowContainerExit(WeatherContainer *self) {
  SnowContainer *cself = (SnowContainer *)self;
  free(cself->flakes);
  cself->flakes = NULL;
  cself->size = 0;
}

void snowContainerShow(WeatherContainer *self, DrawContainer *drawfns) {
  int screenX = getmaxx(stdscr);
  for (int i = 0; i < screenX / 10; i++) {
    drawTree(randRange(0, screenX - 1), drawfns);
  }
}

void snowContainerRun(WeatherContainer *self) {
  SnowContainer *cself = (SnowContainer *)self;
  for (size_t i = 0; i < cself->size; i++) {
    cself->flakes[i].show(&cself->flakes[i]);
    cself->flakes[i].shift(&cself->flakes[i], true);
  }
}

void drawTree(size_t xPos, DrawContainer *drawfns) {
  struct Tree {
    unsigned char height;
    char leaves[5];
  };
  struct Trunk {
    unsigned char height;
    char ch;
  };
  struct Tree tree = {
      .height = randRange(6, 10),
      .leaves =
          {
              '^', // Start & end char
              '%', // General
              '%', // General
              '<', // Left
              '>', // Right
          },
  };
  struct Trunk trunk = {
      .height = 1,
      .ch = 'H',
  };
  const int maxY = getmaxy(stdscr);
  int x = 1;
  unsigned char startX, maxLayer, randOffset, randCol;
  char leaveCh;
  short treeLeavesCols[] = COL_SNOW_LEAVES;
  short treeTrunkCols[] = COL_SNOW_TRUNK;
  for (int y = 1; y <= tree.height; y++) {
    if (y >= (tree.height - trunk.height)) {
      randCol = treeTrunkCols[randRange(0, len(treeTrunkCols) - 1)];
      drawfns->add(drawfns, randCol, xPos, maxY - (tree.height - y), trunk.ch);
    } else {
      randOffset = randRange(-1, 1);
      maxLayer = (2 * y - 1) + randOffset;
      if (maxLayer < 1 || (y == 1 && maxLayer > 1))
        maxLayer = 1;
      startX = xPos - maxLayer / 2;
      for (x = 1; x <= maxLayer; x++) {
        if (y == 1) {
          leaveCh = tree.leaves[0]; // Check for top
        } else {
          if (x == 1) {
            int sel[] = {0, 3};
            leaveCh =
                tree.leaves[randSel(sel, len(sel))[0]]; // Check left most side
          } else if (x == maxLayer) {
            int sel[] = {0, 4};
            leaveCh =
                tree.leaves[randSel(sel, len(sel))[0]]; // Check right most side
          } else if (x < maxLayer / 2) {
            int sel[] = {1, 2, 3};
            leaveCh = tree.leaves[randSel(sel, len(sel))[0]]; // Check left side
          } else if (x > maxLayer / 2) {
            int sel[] = {1, 2, 4};
            leaveCh =
                tree.leaves[randSel(sel, len(sel))[0]]; // Check right side
          } else {
            leaveCh = tree.leaves[randRange(1, 4)]; // Check middle
          }
        }
        randCol = treeLeavesCols[randRange(0, len(treeLeavesCols) - 1)];
        drawfns->add(drawfns, randCol, startX + x, maxY - (tree.height - y),
                     leaveCh);
      }
    }
  }
}
