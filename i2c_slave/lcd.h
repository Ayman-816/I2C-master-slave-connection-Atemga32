/*
 * lcd.h
 *
 *  Created on: Jul 26, 2025
 *      Author: strea
 */

#ifndef LCD_H_
#define LCD_H_
// LCD Pin Definitions
#define LCD_D4 PD2
#define LCD_D5 PD3
#define LCD_D6 PD4
#define LCD_D7 PD5
#define LCD_RS PD0
#define LCD_EN PD1

#define LCD_DATA_PORT PORTD
#define LCD_CONTROL_PORT PORTD
#define LCD_DATA_DDR DDRD
#define LCD_CONTROL_DDR DDRD

volatile char buffer[32];
volatile uint8_t idx = 0;



void lcd_send_nibble(unsigned char nibble) {
    LCD_DATA_PORT &= ~((1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7));
    if (nibble & 0x01) LCD_DATA_PORT |= (1 << LCD_D4);
    if (nibble & 0x02) LCD_DATA_PORT |= (1 << LCD_D5);
    if (nibble & 0x04) LCD_DATA_PORT |= (1 << LCD_D6);
    if (nibble & 0x08) LCD_DATA_PORT |= (1 << LCD_D7);

    LCD_CONTROL_PORT |= (1 << LCD_EN);
    _delay_us(1);
    LCD_CONTROL_PORT &= ~(1 << LCD_EN);
    _delay_us(100);
}

void lcd_command(unsigned char cmd) {
    LCD_CONTROL_PORT &= ~(1 << LCD_RS);
    lcd_send_nibble(cmd >> 4);
    lcd_send_nibble(cmd & 0x0F);
}

void lcd_data(unsigned char data) {
    LCD_CONTROL_PORT |= (1 << LCD_RS);
    lcd_send_nibble(data >> 4);
    lcd_send_nibble(data & 0x0F);
}

void lcd_init(void) {
    LCD_DATA_DDR |= (1 << LCD_D4) | (1 << LCD_D5) | (1 << LCD_D6) | (1 << LCD_D7);
    LCD_CONTROL_DDR |= (1 << LCD_RS) | (1 << LCD_EN);

    _delay_ms(20);

    LCD_CONTROL_PORT &= ~(1 << LCD_RS);
    LCD_CONTROL_PORT &= ~(1 << LCD_EN);

    lcd_send_nibble(0x03);
    _delay_ms(5);

    lcd_send_nibble(0x03);
    _delay_us(150);

    lcd_send_nibble(0x03);
    _delay_us(150);

    lcd_send_nibble(0x02);
    _delay_us(150);

    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x01);
    _delay_ms(2);
    lcd_command(0x06);
}

void lcd_set_cursor(unsigned char row, unsigned char col) {
    unsigned char address;
    address = (row == 0) ? col : (0x40 + col);
    lcd_command(0x80 | address);
}

void lcd_print_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        lcd_data(str[i]);
    }
}


#endif /* LCD_H_ */
