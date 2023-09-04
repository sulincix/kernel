void write_mem(int addr, int value){
    int *buf = (int*) addr;
    *buf = value;
}
int read_mem(int addr){
    int *buf = (int*) addr;
    return (int)buf;
}
