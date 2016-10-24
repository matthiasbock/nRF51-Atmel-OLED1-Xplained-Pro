
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

    while (1)
    {
        // print some text to screen
        oled_println("Od'et amo.", 0, &font);
        oled_println("Quar'id faciam,", 1, &font);
        oled_println("fortasse requiris...", 2, &font);
        oled_println("nRFduino FTW!!", 3, &font);
        display();

        asm("wfi");
    }
}
