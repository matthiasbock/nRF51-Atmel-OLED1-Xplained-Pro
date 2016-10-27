
#include "oled.h"

/**
 * Draw character to specified pixel coordinates
 */
void printcxy(uint8_t x, uint8_t y, uint8_t c)
{
    // vertical lines
    for (uint8_t ix=0; ix<CHAR_WIDTH; ix++)
    {
        // font is organized as one vertical line of pixels per byte
        uint8_t b = font[c++];

        // iterate over all pixels of current vertical line
        for (uint8_t iy=0, mask=1; iy<CHAR_HEIGHT; iy++, mask <<= 1)
        {
            // 1 => draw white pixel
            if (b & mask)
            {
                drawPixel(x+ix, y+iy, WHITE);
            }
            // 0 => clear current pixel
            else
            {
                drawPixel(x+ix, y+iy, BLACK);
            }
        }
    }
}

/**
 * Print a string to line number (0+)
 */
void printsy(uint8_t liney, char* s)
{
    uint8_t index = 0;

    while (s[index] != 0 && index < MAX_LENGTH)
    {
        printcxy(index*(CHAR_WIDTH+1), liney*(CHAR_HEIGHT+1), s[index]);
        index++;
    }
}

