#ifndef OLED_H
#define OLED_H

#include "ssd1306.h"

// maximum characters per line
#define MAX_LENGTH 22

// ASCII 5x7 font
#include "gfx/glcdfont.c"

#define CHAR_WIDTH 5
#define CHAR_HEIGHT 7

void printcxy(uint8_t x, uint8_t y, uint8_t c);
void printsy(uint8_t liney, char* s);

#endif // #ifdef OLED_H
