
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
 * Print a string to row/column coordinate
 */
void printsxy(uint8_t column, uint8_t row, char* s)
{
    uint8_t index = 0;

    while (s[index] != 0 && index < MAX_LENGTH)
    {
        printcxy((column+index)*(CHAR_WIDTH+1), row*(CHAR_HEIGHT+1), s[index]);
        index++;
    }
}

/**
 * Print a string to line number (0+)
 */
void printsy(uint8_t liney, char* s)
{
    printsxy(0, liney, s);
}

/**
 * Print an integer to row/column coordinates
 */
void printixy(uint8_t column, uint8_t row, uint32_t i, bool leading_zeroes)
{
    bcd_t bcd;
    inttobcd(i, &bcd);

    bool print_zeroes = leading_zeroes;

    for (uint8_t index=0; i<BCD_LENGTH; i++)
    {
        if (bcd.digit[index] != 0 || (bcd.digit[index] == 0 && print_zeroes) || index == BCD_LENGTH-1)
        {
            printcxy((column+index)*(CHAR_WIDTH+1), row*(CHAR_HEIGHT+1), '0'+bcd.digit[index]);
        }

        // print zeroes after non-zero in any case
        if (bcd.digit[index] != 0)
        {
            print_zeroes = true;
        }
    }
}
