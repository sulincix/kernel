namespace kernel {
    void main(){
        vga.init();
        terminal.write("Hello World\n");
        terminal.write("Sulincix Was Here\n");
        draw.circle(40, 10, 5, vga.color.BLUE);
        draw.box(3, 3, 15, 15, vga.color.GREEN);
        draw.dot(12, 12, vga.color.RED);
        timer.init();
        while(true);
    }
}

void timer_interrupt_handler(){
        terminal.write("Hello World\n");
    draw.dot(1, 1, vga.color.RED);
}