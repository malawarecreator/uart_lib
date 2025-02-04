#include "uart.h"
#include <stdint.h>


void uart_init(uint32_t baud) {
    uint32_t clk_div = 80000000 / baud;
    *(volatile uint32_t*)UART_CLKDIV_REG = clk_div;

}

void uart_send_byte(uint8_t data) {
    while (*(volatile uint32_t*)UART_STATUS_REG & UART_TX_FULL);
    *(volatile uint32_t*)UART_FIFO_REG = data;

}

uint8_t uart_recieve_byte(void ) {
    while (!(*(volatile uint32_t *)UART_STATUS_REG & (1 << 0)));
    return (uint8_t)(*(volatile uint32_t*)UART_FIFO_REG);


}
void uart_send_string(const char *str) {
    while (*str) {
        uart_send_byte(*str++);
    }
}
