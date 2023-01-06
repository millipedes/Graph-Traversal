#ifndef CAN_H
#define CAN_H

#include "pixel.h"
#include "../../main/include/constants_macros.h"

typedef struct CANVAS_T {
  pixel ** the_pixels;
  int width;
  int height;
} canvas;

canvas * init_canvas(int height, int width);
void debug_canvas(canvas * the_canvas);
void free_canvas(canvas * the_canvas);

#endif
