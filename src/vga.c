#include <stdint.h>
#include <vga.h>

// VGA buffer
struct vga_entry* vga_buffer = (struct vga_entry*)VGA_ADDRESS;

// Function to set the color attribute for a VGA entry
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | (bg << 4);
}

// Function to create a VGA entry with a specific character and color
uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t)uc | ((uint16_t)color << 8);
}

// Function to initialize the VGA text mode
void vga_init() {
    for (int y = 0; y < VGA_HEIGHT; ++y) {
        for (int x = 0; x < VGA_WIDTH; ++x) {
            vga_buffer[y * VGA_WIDTH + x].character = ' ';
            vga_buffer[y * VGA_WIDTH + x].color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
        }
    }
}

void vga_clear() {
    for (int i = 0; i < 80 * 25; i++) {
        vga_buffer[i * 2].character = ' ';
        vga_buffer[i * 2 + 1].color = 0x0F;  // White color
    }
}
