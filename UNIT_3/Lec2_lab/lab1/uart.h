#ifndef UART_H
#define UART_H
#define UARTODR (*(volatile unsigned int*)((unsigned int*)0x101F1000))

void send_string(char* name);

#endif //UART_H