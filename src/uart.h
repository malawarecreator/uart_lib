#pragma once


#include <stdint.h>
#define UART_BASE 0x3FF40000
#define UART_FIFO_REG (UART_BASE + 0x00)
#define UART_STATUS_REG (UART_BASE + 0x1C)
#define UART_CLKDIV_REG (UART_BASE + 0x14)

#define UART_TX_FULL (1 << 24)


void uart_init(uint32_t baud);
void uart_send_byte(uint8_t data);
uint8_t uart_recieve_byte(void);
void uart_send_string(const char* str);
