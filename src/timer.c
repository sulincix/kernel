#include <stdint.h>
#include <io.h>

#define PIT_FREQUENCY 1193182

#define PIT_COMMAND      0x43
#define PIT_CHANNEL_0    0x40

// Define a structure for IDT entry in protected mode
struct IDT_entry {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed));

struct IDT_entry idt_table[256];

// Function prototypes
void init_pit();
void init_idt();
extern void timer_interrupt_handler();

void (*timer_interrupt_handler_ptr)() = timer_interrupt_handler;

void timer_init() {
    init_pit();
    init_idt();
    asm volatile ("sti");
}

void load_idt(uint32_t* idt_ptr) {
    asm volatile ("lidt (%0)" : : "r"(idt_ptr));
}

void init_pit() {
    // Set the PIT to generate interrupts at a specified frequency

    // Calculate the divisor for the desired frequency
    uint16_t divisor = PIT_FREQUENCY / 100;  // For example, generating interrupts every 10 ms

    // Send the command byte to set the PIT to mode 3 (square wave generator)
    outb(PIT_COMMAND, 0x36);

    // Send the low byte of the divisor
    outb(PIT_CHANNEL_0, (uint8_t)(divisor & 0xFF));

    // Send the high byte of the divisor
    outb(PIT_CHANNEL_0, (uint8_t)((divisor >> 8) & 0xFF));
}

void init_idt() {
    // Set up IDT entry for timer interrupt
    unsigned short codeSegment = 0x08; // CODE_SEG
    unsigned short interruptFlag = 0x8E00; // P=1, DPL=00, Type=1110b
    unsigned int isrAddress = (unsigned int)timer_interrupt_handler_ptr;

    unsigned short *idt_ptr = (unsigned short *)0x80000; // Assuming IDT starts at address 0x80000
    idt_ptr[0] = 0xFFFF;
    idt_ptr[1] = codeSegment;
    idt_ptr[2] = (unsigned short)(isrAddress & 0xFFFF);
    idt_ptr[3] = interruptFlag;
    idt_ptr[4] = (unsigned short)((isrAddress >> 16) & 0xFFFF);

    // Load IDT
    load_idt((uint32_t*)idt_ptr);
}
