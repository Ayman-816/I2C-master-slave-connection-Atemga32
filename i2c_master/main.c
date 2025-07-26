#include <avr/io.h>
#include <util/delay.h>

#include "uart.h"
#include "i2c.h"

#define F_CPU 8000000UL

int main(void) {
    UART_Init(((F_CPU/16/BAUD)-1));
    I2C_Init();

    while (1) {
        char ch = UART_Receive();

        I2C_Start();
        I2C_Write((SLAVE_ADDR << 1));
        I2C_Write(ch);
        I2C_Stop();

        if (ch == '\n') {
            _delay_ms(500);
        } else {
            _delay_ms(50);
        }
    }
}
