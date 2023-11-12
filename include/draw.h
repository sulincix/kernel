#include  <vga.h>
#ifndef _DRAW_H
#define _DRAW_H
// Function to draw a horizontal line on the screen
void draw_dot(int x, int y, enum vga_color color);
// Function to draw a circle on the screen
void draw_circle(int centerX, int centerY, int radius, enum vga_color color);
// Function to draw a box on the screen
void draw_box(int x1, int y1, int x2, int y2, enum vga_color color);
#endif
