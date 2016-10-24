
#include <stdbool.h>

#include "nrf_delay.h"

#include "pin_config.h"
#include "ssd1306.h"

// ASCII 5x7 font
#include "gfx/glcdfont.c"

//extern const unsigned char font[];

void main()
{
    init_ssd1306(
            PIN_OLED_DISPLAY_RESET,
            PIN_OLED_DISPLAY_SS,
            PIN_OLED_DATA_CMD_SEL,
            PIN_OLED_SPI_SCK,
            PIN_OLED_SPI_MOSI
            );
    begin(SSD1306_SWITCHCAPVCC, 0, true);

    // clear the buffer.
    clearDisplay();

    uint32_t selector = 0;
    while (1)
    {
        // print a character to screen
        drawChar(20, 0, &font[selector], 5, 7);
        selector = (selector + 5) % (5*256);
        display();

        // wait a little before continuing
        delay(10);
    }
}
