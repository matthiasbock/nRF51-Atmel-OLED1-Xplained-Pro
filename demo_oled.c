
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

    // Clear the buffer.
    clearDisplay();

    // draw a single pixel
    drawPixel(10, 10, WHITE);
    drawChar(20, 0, &font['A'], 5, 7);
    display();

    while (1)
    {
        asm("wfi");
        /*
        invertDisplay(0);
        delay(200);
        invertDisplay(1);
        delay(200);
        */
    }
}
