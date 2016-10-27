/*
 * Tiny Binary Coded Decimals (BCD) library
 */

#include "bcd.h"

/**
 * Convert 32-bit unsigned integer to BCD
 *
 * http://www.eng.utah.edu/~nmcdonal/Tutorials/BCDTutorial/BCDConversion.html
 */
void inttobcd(uint32_t value, bcd_t* bcd)
{
   // begin with least significant digit
   for (uint8_t i=BCD_LENGTH-1; i>=0; i--)
   {
       // digit is remainder during division by 10
       bcd->digit[i] = value % 10;

       // remaining value is result of integer division by 10 (waiving the remainder)
       value /= 10;
   }
}

