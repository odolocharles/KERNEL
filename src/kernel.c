void uart_putc(char c) {
    volatile unsigned int* UART0_DR = (unsigned int*)0x09000000;
    *UART0_DR = c;
}

void uart_puts(const char* str) {
    while (*str) {
        uart_putc(*str++);
    }
}

void kernel_main() {
    uart_puts("Sorabbyngo Kernel Booting...\n");
    while (1);
}
//“Add kernel.c” → Commit new file
