#ifndef OLED_H
#define OLED_H

#include "ssd1306.h"
#include "bcd.h"

// maximum characters per line
#define MAX_LENGTH 22

// ASCII 5x7 font
#include "gfx/glcdfont.c"

#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

void printcxy(uint8_t x, uint8_t y, uint8_t c);
void printsxy(uint8_t column, uint8_t row, char* s);
void printsy(uint8_t liney, char* s);
void printixy(uint8_t column, uint8_t row, uint32_t i, bool leading_zeroes);

#endif // #ifdef OLED_H
