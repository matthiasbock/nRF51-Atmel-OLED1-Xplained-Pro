#ifndef BCD_H
#define BCD_H

#include <stdint.h>

#define BCD_LENGTH 5

// one byte per decimal digit
typedef struct
{
    uint8_t digit[BCD_LENGTH];
} bcd_t;

void inttobcd(uint32_t value, bcd_t* bcd);

#endif // BCD_H
