namespace terminal {
    extern void init();
    extern void set_color(int color);
    extern void putentryat(char c, int color, int x, int y);
    extern void putchar(char c);
    extern void write_data(string data, int size);
    extern void write(string data);
}
