#include <vga.h>
#include <string.h>
#include <stddef.h>
size_t terminal_row = 0;
size_t terminal_column = 0;

void terminal_putchar(char c) {
	if (c == '\n' || c == '\0') {
	    terminal_row++;
	    terminal_column = 0;
	    return;
	}
  vga_buffer[terminal_row * VGA_WIDTH + terminal_column].character = c;
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

void terminal_write_data(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_write(const char* data) {
	terminal_write_data(data, strlen(data));
}
