
#include "oled.h"

/**
 * Draw character from font to display
 */
void drawChar(uint8_t x, uint8_t y, uint8_t* font, uint8_t char_width, uint8_t char_height)
{
    // vertical lines
    for (uint8_t ix=0; ix<char_width; ix++)
    {
        // font is organized as one vertical line of pixels per byte(?)
        uint8_t* c = font+ix;

        // iterate over all pixels of current vertical line
        for (uint8_t iy=0, mask=1; iy<char_height; iy++, mask <<= 1)
        {
            // 1 => draw white pixel
            if ((*c) & mask)
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

void oled_println(char* s, uint8_t liney, uint8_t* font)
{
    uint8_t index = 0;
    const uint8_t max_length = 22;
    const uint8_t char_width = 5;
    const uint8_t char_height = 7;

    while (*(s+index) != 0 && index < max_length)
    {
        uint8_t c = *(s+index);
        uint8_t* char_bitmask = font + (c*5);
        drawChar(index*(char_width+1), liney*(char_height+1), char_bitmask, char_width, char_height);
        index++;
    }
}

