#ifndef PIX_H
#define PIX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct PIXEL_T {
  int r;
  int g;
  int b;
} pixel;

pixel * init_pixel(int r, int g, int b);
void debug_pixel(pixel * the_pixel);
void free_pixel(pixel * the_pixel);

#endif
