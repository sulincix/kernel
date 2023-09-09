void vga_put(int pos_x, int pos_y, unsigned char VGA_COLOR)
{
    unsigned char* location = (unsigned char*)0xB8000 + 320 * pos_y + pos_x;
    *location = VGA_COLOR;
}