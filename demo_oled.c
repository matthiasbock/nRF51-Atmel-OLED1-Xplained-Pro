
#include <stdbool.h>

#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "pin_config.h"
#include "ssd1306.h"

void init_oled_pins()
{
    nrf_gpio_cfg_output(PIN_OLED_DISPLAY_RESET);
    nrf_gpio_cfg_output(PIN_OLED_DISPLAY_SS);
    nrf_gpio_cfg_output(PIN_OLED_DATA_CMD_SEL);
    nrf_gpio_cfg_output(PIN_OLED_SPI_SCK);
    nrf_gpio_cfg_output(PIN_OLED_SPI_MOSI);
}

void main()
{
    init_oled_pins();

    init_ssd1306(
            PIN_OLED_DISPLAY_RESET,
            PIN_OLED_DISPLAY_SS,
            PIN_OLED_DATA_CMD_SEL,
            PIN_OLED_SPI_SCK,
            PIN_OLED_SPI_MOSI
            );
    begin(SSD1306_SWITCHCAPVCC, 0, true);
    display();
    delay(2000);

    // Clear the buffer.
    clearDisplay();
    display();

    // draw a single pixel
    drawPixel(10, 10, WHITE);
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
