/**
 * Pinout to the Atmel OLED1 Xplained Pro Kit
 * using the nRFduino-ATOLED1-XPRO-Adapter
 *
 * nRFduino:
 *  https://github.com/interoberlin/nRF51-Boards/tree/master/nRFduino.PCB
 *
 * Adapter:
 *  https://github.com/matthiasbock/nRFduino-ATOLED1-XPRO-Adapter.PCB
 */

#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

#include "sdk/nrfduino.h"

// Board identification IC
#define PIN_ID      NRFDUINO_PIN_A5

// Buttons pins are active low, internal pull-up required
#define PIN_BUTTON1 NRFDUINO_PIN_A1
#define PIN_BUTTON2 NRFDUINO_PIN_A4
#define PIN_BUTTON3 NRFDUINO_PIN_IO4

// LED pins are active low
#define PIN_LED1    NRFDUINO_PIN_A2
#define PIN_LED2    NRFDUINO_PIN_IO6
#define PIN_LED3    NRFDUINO_PIN_IO5

/*
 * OLED display / SSD1306 pins
 * as seen from the display
 */
// RES#: chip reset input, active low
#define PIN_OLED_DISPLAY_RESET  NRFDUINO_PIN_IO7

// CS#: chip select input, active low
#define PIN_OLED_DISPLAY_SS     NRFDUINO_PIN_A0

// D/C#: mode selection input, high -> data, low -> command
#define PIN_OLED_DATA_CMD_SEL   NRFDUINO_PIN_A3

// D0 = SCLK: data clock input, rising edge trigger
#define PIN_OLED_SPI_SCK        NRFDUINO_PIN_IO9

// D1 = SDIN: data input, 8 bit, order: D7 downto 0
#define PIN_OLED_SPI_MOSI       NRFDUINO_PIN_IO8

#endif // PIN_CONFIG_H
