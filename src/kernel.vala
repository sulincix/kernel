namespace kernel {
    void main(){
        vga.init();
        terminal.write("Hello World\n");
        terminal.write("Sulincix Was Here\n");
        draw.circle(40, 10, 5, vga.color.BLUE);
        draw.box(3, 3, 15, 15, vga.color.GREEN);
        draw.dot(12, 12, vga.color.RED);
        int i=0;
        int j=0;
        while(true){
            if(i % 700000 == 0){
                terminal.write("Sulincix Was Here\n");
                draw.dot(j % 80, j / 80,  j % 8);
                j++;
                if(j >= 80*24){
                    j = 0;
                }
                i = 0;
            }
            i++;
        }
    }
}

