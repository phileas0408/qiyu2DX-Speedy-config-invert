#ifndef CONTROLLER_CONFIG_H
#define CONTROLLER_CONFIG_H

#define SW_GPIO_SIZE 11               // Number of switches
#define LED_GPIO_SIZE 11              // Number of switch LEDs
#define ENC_GPIO_SIZE 1              // Number of encoders
#define ENC_PPR 72                   // Encoder PPR
#define MOUSE_SENS 1                 // Mouse sensitivity multiplier
#define ENC_DEBOUNCE true            // Encoder Debouncing
#define SW_DEBOUNCE_TIME_US 4000     // Switch debounce delay in us
#define ENC_PULSE (ENC_PPR * 4)      // 4 pulses per PPR
#define REACTIVE_TIMEOUT_MAX 1000000 // HID to reactive timeout in us
#define WS2812B_LED_SIZE 45           // Number of WS2812B LEDs
#define WS2812B_LED_ZONES 1          // Number of WS2812B LED Zones
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
                              HID_KEY_5, HID_KEY_6, HID_KEY_7, 
                              HID_KEY_Z, HID_KEY_A, HID_KEY_B, HID_KEY_C};

// UPDATE YOUR MAPPINGS HERE
#if (CONTROLLER_SIDE == 1)
// P1
const uint8_t SW_GPIO[] = {
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    27, // Button 8 (INFINITAS), do not modify!!
    16,
    17,
    18,
};
const uint8_t LED_GPIO[] = {
    6,  // LED1
    5,  // LED2
    4,  // LED3
    3,  // LED4
    2,  // LED5
    1,  // LED6
    0,  // LED7
    25, // Button 8 (INFINITAS), do not modify!!
    20,
    21,
    22,
};
#else
// P2
const uint8_t SW_GPIO[] = {
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    27, // Button 8 (INFINITAS), do not modify!!
    16,
    17,
    18,
};
const uint8_t LED_GPIO[] = {
    6,  // LED1
    5,  // LED2
    4,  // LED3
    3,  // LED4
    2,  // LED5
    1,  // LED6
    0,  // LED7
    25, // Button 8 (INFINITAS), do not modify!!
    20,
    21,
    22,
};
#endif
const uint8_t ENC_GPIO[] = {14}; // L_ENC(0, 1); R_ENC(2, 3)
const bool ENC_REV[] = {false};  // Reverse Encoders
const uint8_t WS2812B_GPIO = 28;

#endif

extern bool joy_mode_check;

#endif
