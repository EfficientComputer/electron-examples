// Board-specific pins for the quickstart example.
//
// The processor's GPIO banks differ between the Electron E1x and the Electron E1, and the two
// evaluation kits wire their user LEDs to different pins. Everything board-specific lives here so
// main.c stays the same for both.
#pragma once

#include <eff.h>

#if defined(EFF_ARCH_E1)
// Electron E1 EVK: user LEDs on DIGIO68 and DIGIO69 (GPIO bank 3, pins 4 and 5). Set SW15 on.
#define LED_BANK GPIO_3
#define LED_PINS (GPIO_PIN_4 | GPIO_PIN_5)
static inline void board_led_pinmux(void) {
    eff_pinmux_set(PINMUX_68, PINMUX_GPIO);
    eff_pinmux_set(PINMUX_69, PINMUX_GPIO);
}
#else
// Electron E1x EVK: user LEDs on GPIO bank 11, pins 2 and 3
#define LED_BANK GPIO_11
#define LED_PINS (GPIO_PIN_2 | GPIO_PIN_3)
static inline void board_led_pinmux(void) { eff_pinmux_set(PINMUX_11, PINMUX_GPIO); }
#endif
