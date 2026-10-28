#include <eff.h>
#include <stdio.h>
#include "board.h"

int main()
{
    int i = 0;
    int set = 0;

    board_led_pinmux();
    eff_gpio_dir_set(LED_BANK, LED_PINS, EFF_GPIO_OUT);
    eff_gpio_pull_set(LED_BANK, LED_PINS, EFF_GPIO_PULL_NONE);

    while (1)
    {
        printf("Energy is everything! %i\r\n", i++);
        if (set)
        {
            eff_gpio_clear(LED_BANK, LED_PINS);
            set = 0;
        }
        else
        {
            eff_gpio_set(LED_BANK, LED_PINS);
            set = 1;
        }
        sleep(1);
    }
}
