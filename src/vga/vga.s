.global vga_init

.text

vga_init:
    mov $00, %ah
    mov $13, %al
    int $10
    ret
