/**
 * Short demo program to demonstrate the button function
 * on the Atmel OLED1 Xplained Pro board
 *
 * Should, if wired up correctly, light up the LED, when the button is pressed.
 */

#include "nrf_gpio.h"
#include "nrf_delay.h"

#include "pcb/pinout.h"

// LED on macro
#define led_on(pin)             nrf_gpio_pin_clear(pin);
// LED off macro
#define led_off(pin)            nrf_gpio_pin_set(pin);
// button pressed macro
#define button_pressed(pin)     (!nrf_gpio_pin_read(pin))

void init_leds()
{
    nrf_gpio_cfg_output(PIN_LED1);
    led_off(PIN_LED1);
    nrf_gpio_cfg_output(PIN_LED2);
    led_off(PIN_LED2);
    nrf_gpio_cfg_output(PIN_LED3);
    led_off(PIN_LED3);
}

void init_buttons()
{
    nrf_gpio_cfg_input(PIN_BUTTON1, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(PIN_BUTTON2, NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(PIN_BUTTON3, NRF_GPIO_PIN_PULLUP);
}

void main()
{
    init_leds();
    init_buttons();

    while (1)
    {
        if (button_pressed(PIN_BUTTON1))
            led_on(PIN_LED1)
        else
            led_off(PIN_LED1);

        if (button_pressed(PIN_BUTTON2))
            led_on(PIN_LED2)
        else
            led_off(PIN_LED2);

        if (button_pressed(PIN_BUTTON3))
            led_on(PIN_LED3)
        else
            led_off(PIN_LED3);

        nrf_delay_us(10000);
    }
}
