
#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "pin_config.h"

void main()
{
    nrf_gpio_cfg_input(PIN_BUTTON1, NRF_GPIO_PIN_PULLUP);

    nrf_gpio_cfg_output(PIN_LED1);

    while (1)
    {
        // button pressed = 0
        if (!nrf_gpio_pin_read(PIN_BUTTON1))
        {
            // LED on
            nrf_gpio_pin_clear(PIN_LED1);
        }
        else
        {
            // LED off
            nrf_gpio_pin_set(PIN_LED1);
        }
        nrf_delay_us(10000);
    }
}
