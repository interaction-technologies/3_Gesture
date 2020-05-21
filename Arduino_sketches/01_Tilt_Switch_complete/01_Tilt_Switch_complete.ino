#include <FastLED.h>

// FastLED setup
#define DATA_PIN 9
#define NUM_LEDS 1

// Pin to connect tilt switch to
#define TILT_PIN 5

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
   // Setup Neopixel strip (of 1)
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
   FastLED.clear();

   // Declare tilt switch pin like a normal button
   pinMode(TILT_PIN, INPUT_PULLUP);
}

void loop() {
   // Tilt-switch turns "off" when it is upside down
   if(digitalRead(TILT_PIN) == HIGH){
      leds[0] = CRGB::Blue;
   }else{
      leds[0] = CRGB::Yellow;
   }
   FastLED.show();
}
