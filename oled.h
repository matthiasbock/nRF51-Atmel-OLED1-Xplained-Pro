#ifndef OLED_H
#define OLED_H

#include "ssd1306.h"

void drawChar(uint8_t x, uint8_t y, uint8_t* font, uint8_t char_width, uint8_t char_height);
void oled_println(char* s, uint8_t liney, uint8_t* font);

#endif // #ifdef OLED_H
