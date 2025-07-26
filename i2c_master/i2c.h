/*
 * i2c.h
 *
 *  Created on: Jul 26, 2025
 *      Author: strea
 */

#ifndef I2C_H_
#define I2C_H_

#define SLAVE_ADDR 0x20



void I2C_Init(void) {
    TWBR = 72;
    TWSR = 0x00;
}

void I2C_Start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void I2C_Write(char data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}


#endif /* I2C_H_ */
