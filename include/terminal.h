#ifndef _TERMINAL_H
#define _TERMINAL_H
#include <stddef.h>
void terminal_write(const char* data);
void terminal_write_data(const char* data, size_t size);
#endif
