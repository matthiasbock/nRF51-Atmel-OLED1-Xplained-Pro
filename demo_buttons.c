
#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "pin_config.h"

void main()
{
    nrf_gpio_cfg_input(PIN_BUTTON1, NRF_GPIO_PIN_PULLUP);

    nrf_gpio_cfg_output(PIN_LED1);

    while (1)
    {
        nrf_gpio_pin_set(PIN_LED1);
        nrf_delay_us(500000);
        nrf_gpio_pin_clear(PIN_LED1);
        nrf_delay_us(500000);
    }
}
