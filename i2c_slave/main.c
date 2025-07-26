#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#define SLAVE_ADDR 0x20

#include "lcd.h"
#include "i2c.h"


ISR(TWI_vect) {
    switch (TWSR & 0xF8) {
        case 0x60:
            break;

        case 0x80:
            {
                char ch = TWDR;

                if (ch == '\n' || ch == '\r') {
                    buffer[idx] = '\0';
                    lcd_command(0x01);
                    _delay_ms(2);
                    lcd_set_cursor(0, 0);
                    lcd_print_string((char*)buffer);
                    idx = 0;
                } else {
                    if (idx < 32 - 1) {
                        buffer[idx++] = ch;
                    }
                }
            }
            break;
    }

    TWCR |= (1 << TWINT) | (1 << TWEA);
}



int main(void) {
    lcd_init();
    lcd_set_cursor(0,0);
    lcd_print_string("Wazzup bro");

    I2C_Slave_Init(SLAVE_ADDR);
    sei();

    while (1) {
    }
}
