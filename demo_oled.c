
#include <stdint.h>
#include <stdbool.h>

#include "nrf_delay.h"

#include "pcb/pinout.h"
#include "ssd1306.h"
#include "oled.h"

void main()
{
    ssd1306_init(
            ATOLED1_XPRO_PIN_OLED_DISPLAY_RESET,
            ATOLED1_XPRO_PIN_OLED_DISPLAY_SS,
            ATOLED1_XPRO_PIN_OLED_DATA_CMD_SEL,
            ATOLED1_XPRO_PIN_OLED_SPI_SCK,
            ATOLED1_XPRO_PIN_OLED_SPI_MOSI
            );
    ssd1306_begin(SSD1306_SWITCHCAPVCC, 0, true);

    // clear the display buffer
    ssd1306_clear();

    while (1)
    {
        // print some text to screen
        printsy(0, "Od'et amo.");
        printsy(1, "Quar'id faciam,");
        printsy(2, "fortasse requiris...");
        printsy(3, "nRFduino FTW!!");
        ssd1306_display();

        asm("wfi");
    }
}
