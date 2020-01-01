#include "light.h"

#include "driver/gpio.h"

#define LED_PIN 4

bool is_light_on = false;

void init_light() {
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
}

void toggle_light() {
    is_light_on = !is_light_on;
    gpio_set_level(LED_PIN, is_light_on);
}
