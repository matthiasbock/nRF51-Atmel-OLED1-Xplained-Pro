
#include <stdint.h>
#include <stdbool.h>

#include "nrf_delay.h"

#include "pcb/pinout.h"
#include "ssd1306.h"

// ASCII 5x7 font
#include "gfx/glcdfont.c"

#include "oled.h"

void main()
{
    init_ssd1306(
            ATOLED1_XPRO_PIN_OLED_DISPLAY_RESET,
            ATOLED1_XPRO_PIN_OLED_DISPLAY_SS,
            ATOLED1_XPRO_PIN_OLED_DATA_CMD_SEL,
            ATOLED1_XPRO_PIN_OLED_SPI_SCK,
            ATOLED1_XPRO_PIN_OLED_SPI_MOSI
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
