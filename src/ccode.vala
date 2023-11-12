namespace terminal {
    public extern void write(string data);
    public extern void write_data(string data, int size);
    public extern void putchar(char c);
}

namespace vga {
    public extern void init();
    public extern void clean();
    namespace color {
        int BLACK = 0;
        int BLUE = 1;
        int GREEN = 2;
        int CYAN = 3;
        int RED = 4;
        int MAGENTA = 5;
        int BROWN = 6;
        int LIGHT_GREY = 7;
        int DARK_GREY = 8;
        int LIGHT_BLUE = 9;
        int LIGHT_GREEN = 10;
        int LIGHT_CYAN = 11;
        int LIGHT_RED = 12;
        int LIGHT_MAGENTA = 13;
        int LIGHT_BROWN = 14;
        int WHITE = 15;
    }
}

namespace draw {
    public extern void dot(int x, int y, int color);
    public extern void circle(int centerX, int centerY, int radius, int color);
    public extern void box(int x1, int y1, int x2, int y2, int color);
}
