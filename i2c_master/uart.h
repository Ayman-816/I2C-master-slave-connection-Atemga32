/*
 * uart.h
 *
 *  Created on: Jul 26, 2025
 *      Author: strea
 */

#ifndef UART_H_
#define UART_H_


#define BAUD 9600

void UART_Init(unsigned int ubrr) {
    UBRRH = (ubrr >> 8);
    UBRRL = (unsigned char)ubrr;
    UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

char UART_Receive(void) {
    while (!(UCSRA & (1 << RXC)));
    return UDR;
}

#endif /* UART_H_ */
