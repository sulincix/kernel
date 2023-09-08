namespace kernel {
    int i=0;
    void main(){
        vga.init();
        terminal.init();
        terminal.write("Hello World\n");
        terminal.write("Sulincix Was Here\n");
        while(true);
    }
}

