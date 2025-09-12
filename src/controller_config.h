#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

#define SW_GPIO_SIZE 8               // Number of switches
#define LED_GPIO_SIZE 8              // Number of switch LEDs
#define ENC_GPIO_SIZE 1              // Number of encoders
#define ENC_PPR 72                   // Encoder PPR
#define MOUSE_SENS 1                 // Mouse sensitivity multiplier
#define ENC_DEBOUNCE true            // Encoder Debouncing
#define SW_DEBOUNCE_TIME_US 4000     // Switch debounce delay in us
#define ENC_PULSE (ENC_PPR * 4)      // 4 pulses per PPR
#define REACTIVE_TIMEOUT_MAX 1000000 // HID to reactive timeout in us
#define WS2812B_LED_SIZE 0           // Number of WS2812B LEDs
#define WS2812B_LED_ZONES 2          // Number of WS2812B LED Zones
#define WS2812B_LEDS_PER_ZONE \
  WS2812B_LED_SIZE / WS2812B_LED_ZONES // Number of LEDs per zone

// Tina added configuration options:
// You can also -DCONTROLLER_SIDE=VALUE in the cmake CLI instead, see
// build.sh for an example
#ifndef CONTROLLER_SIDE
#define CONTROLLER_SIDE 1
#endif

#define SPOOF_KONAMI_CONTROLLER true // change to true or false
#define CUSTOM_VID 0xCafe // ignored if SPOOF_KONAMI_CONTROLLER is true

#ifdef PICO_GAME_CONTROLLER_C

// MODIFY KEYBINDS HERE, MAKE SURE LENGTHS MATCH SW_GPIO_SIZE
const uint8_t SW_KEYCODE[] = {HID_KEY_1, HID_KEY_2, HID_KEY_3, HID_KEY_4,
                              HID_KEY_5, HID_KEY_6, HID_KEY_7};

/* Notes of my GPIO mapping on my pi picos
Do not change here, this is only a comment, scroll to the section below

P1_SW1 = "GPIO8"
P1_SW2 = "GPIO7"
P1_SW3 = "GPIO12"
P1_SW4 = "GPIO9"
P1_SW5 = "GPIO11"
P1_SW6 = "GPIO13"
P1_SW7 = "GPIO10"

P2_SW1 = "GPIO13"
P2_SW2 = "GPIO10"
P2_SW3 = "GPIO9"
P2_SW4 = "GPIO8"
P2_SW5 = "GPIO7"
P2_SW6 = "GPIO12"
P2_SW7 = "GPIO11"
*/

// UPDATE YOUR MAPPINGS HERE
#if (CONTROLLER_SIDE == 1)
// P1
const uint8_t SW_GPIO[] = {
    8,
    7,
    12,
    9,
    11,
    13,
    10,
    27, // Button 8 (INFINITAS), do not modify!!
};
const uint8_t LED_GPIO[] = {
    3,  // LED1
    6,  // LED2
    4,  // LED3
    2,  // LED4
    5,  // LED5
    0,  // LED6
    1,  // LED7
    25, // Button 8 (INFINITAS), do not modify!!
};
#else
// P2
const uint8_t SW_GPIO[] = {
    13, // SW1
    10, // SW2
    9,  // SW3
    8,  // SW4
    7,  // SW5
    12, // SW6
    11, // SW7
    27, // Button 8 (INFINITAS), do not modify!!
};
const uint8_t LED_GPIO[] = {
    6, // LED1
    3, // LED2
    2, // LED3
    1, // LED4
    0, // LED5
    5, // LED6
    4, // LED7
    25, // Button 8 (INFINITAS), do not modify!!
};
#endif
const uint8_t ENC_GPIO[] = {14}; // L_ENC(0, 1); R_ENC(2, 3)
const bool ENC_REV[] = {false};  // Reverse Encoders
const uint8_t WS2812B_GPIO = 28;

#endif

extern bool joy_mode_check;

#endif
