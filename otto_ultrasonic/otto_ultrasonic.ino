#include <FastLED.h>

// LED configuration
#define LED_PIN     13    // Pin where the RGB LED is connected
#define NUM_LEDS    6     // Number of LEDs (change this if you have more LEDs)
#define BRIGHTNESS  255   // Brightness level (0-255)

CRGB leds[NUM_LEDS];      // Define an array to store LED data

void setup() {
  // Initialize FastLED with the specified configuration
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  // Set the LED to Red, Green, and Blue sequentially
  leds[0] = CRGB::Red;   // Set the LED to Red
  leds[1] = CRGB::Red;   // Set the LED to Red
  leds[2] = CRGB::Red;   // Set the LED to Red

  leds[3] = CRGB::Red;   // Set the LED to Red
  leds[4] = CRGB::Red;   // Set the LED to Red
  leds[5] = CRGB::Red;   // Set the LED to Red
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

  leds[0] = CRGB::Green; // Set the LED to Green
  leds[1] = CRGB::Green; // Set the LED to Green
  leds[2] = CRGB::Green; // Set the LED to Green

  leds[3] = CRGB::Green; // Set the LED to Green
  leds[4] = CRGB::Green; // Set the LED to Green
  leds[5] = CRGB::Green; // Set the LED to Green
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

  leds[0] = CRGB::Blue;  // Set the LED to Blue
  leds[1] = CRGB::Blue;  // Set the LED to Blue
  leds[2] = CRGB::Blue;  // Set the LED to Blue

  leds[3] = CRGB::Blue;  // Set the LED to Blue
  leds[4] = CRGB::Blue;  // Set the LED to Blue
  leds[5] = CRGB::Blue;  // Set the LED to Blue
  FastLED.show();        // Update the LED to display the color
  delay(1000);           // Wait for 1 second

  // You can also set custom colors using RGB values
  // leds[0] = CRGB(128, 0, 128); // Purple (custom RGB)
  // FastLED.show();              // Update the LED to display the color
  // delay(1000);                 // Wait for 1 second
}
