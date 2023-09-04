void mmio_write(int addr, int value){
    int *buf = (int*) addr;
    *buf = value;
}
