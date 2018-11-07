#include <Arduino-Renard.h>
#include <FastLED.h>

#define DATA_PIN 12
#define NUM_LEDS 50
#define CHANNELS NUM_LEDS*3 // 3 per pixel

CRGB leds[NUM_LEDS];

Renard renard;

void setup() {

  // Uncomment/edit one of the following lines for your leds arrangement.
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); // I changed RGB to GRB as that is how my pixels are configured
  // FastLED.addLeds<NEOPIXEL, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS); 

  //Serial.begin(57600);
  // Start Renard library
  // begin(address of buffer, size of that buffer, serial port, baud)
  renard.begin((uint8_t*)&leds, CHANNELS, &Serial, 57600);
}

void loop() {
  // Check to see if we got a new set of values from the Renard library         
  if(renard.receive()) {
    FastLED.show();
  }
}
