#include "./include/canvas.h"

canvas * init_canvas(int height, int width) {
  canvas * the_canvas = calloc(1, sizeof(struct CANVAS_T));
  the_canvas->width = width;
  the_canvas->height = height;
  the_canvas->the_pixels = calloc(height, sizeof(struct PIXEL_T *));
  for(int i = 0; i < height; i++)
    for(int j = 0; j < width; j++)
      the_canvas->the_pixels[i * width + j]
        = init_pixel(COLOR_MAX, COLOR_MAX, COLOR_MAX);
  return the_canvas;
}

void debug_canvas(canvas * the_canvas) {
  printf("[CANVAS]\n");
  printf("(%d, %d)\n", the_canvas->height, the_canvas->width);
  for(int i = 0; i < the_canvas->height; i++)
    for(int j = 0; j < the_canvas->width; j++)
      debug_pixel(the_canvas->the_pixels[i * the_canvas->width + j]);
}

void free_canvas(canvas * the_canvas) {
  if(the_canvas) {
    if(the_canvas->the_pixels) {
      for(int i = 0; i < the_canvas->height; i++)
        for(int j = 0; j < the_canvas->width; j++)
          if(the_canvas->the_pixels[i * the_canvas->width + j])
            free_pixel(the_canvas->the_pixels[i * the_canvas->width + j]);
      free(the_canvas->the_pixels);
    }
    free(the_canvas);
  }
}

