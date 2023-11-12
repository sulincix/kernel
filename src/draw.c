#include <vga.h>
// Function to draw a dot on the screen
void draw_dot(int x, int y, enum vga_color color) {
    // Check if the coordinates are within the screen bounds
    if (x < 0 || x >= VGA_WIDTH || y < 0 || y >= VGA_HEIGHT) {
        return;  // Coordinates are out of bounds
    }

    // Set the character and color at the specified position
    vga_buffer[y * VGA_WIDTH + x].character = ' ';
    vga_buffer[y * VGA_WIDTH + x].color = vga_entry_color(color, color);
}

void draw_circle(int centerX, int centerY, int radius, enum vga_color color) {
    int x = radius;
    int y = 0;
    int radiusError = 1 - x;

    while (x >= y) {
        draw_dot(centerX + x, centerY - y, color);
        draw_dot(centerX - x, centerY - y, color);
        draw_dot(centerX - x, centerY + y, color);
        draw_dot(centerX + x, centerY + y, color);
        draw_dot(centerX + y, centerY - x, color);
        draw_dot(centerX - y, centerY - x, color);
        draw_dot(centerX - y, centerY + x, color);
        draw_dot(centerX + y, centerY + x, color);

        y++;

        if (radiusError < 0) {
            radiusError += 2 * y + 1;
        } else {
            x--;
            radiusError += 2 * (y - x + 1);
        }
    }
}

void draw_box(int x1, int y1, int x2, int y2, enum vga_color color) {
    // Draw the four sides of the box
    for (int i = x1; i <= x2; i++) {
        draw_dot(i, y1, color);   // Top side
        draw_dot(i, y2, color);   // Bottom side
    }

    for (int j = y1 + 1; j < y2; j++) {
        draw_dot(x1, j, color);   // Left side
        draw_dot(x2, j, color);   // Right side
    }
}
