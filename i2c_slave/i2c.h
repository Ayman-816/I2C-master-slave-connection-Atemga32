/*
 * i2c.h
 *
 *  Created on: Jul 26, 2025
 *      Author: strea
 */

#ifndef I2C_H_
#define I2C_H_

void I2C_Slave_Init(char address) {
    TWAR = address << 1;
    TWCR = (1 << TWEA) | (1 << TWEN) | (1 << TWIE);
}

#endif /* I2C_H_ */
