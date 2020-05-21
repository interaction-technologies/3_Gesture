#include <NewPing.h>
#include <FastLED.h>

// FastLED setup
#define DATA_PIN 9
#define NUM_LEDS 1

// Ultrasonic setup
#define TRIGGER_PIN  10  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200

// Array of led data
CRGB leds[NUM_LEDS];

// Create a new ultrasonic sensor object
NewPing my_ultrasonic(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() { 
   // Setup Neopixel strip (of 1)
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
   FastLED.clear();
}

// Save hue value
uint8_t hue = 0;

void loop() {
   // Get distance from sensor
   uint16_t distance = my_ultrasonic.ping_cm();
   
   // Discard zero values and check if we are close to sensor
   if((distance <= 30) && (distance>0)){
      hue = map(distance,0,30,0,255);
   }

   // Set colour of LED from rainbow using hue value
   leds[0] = CHSV(hue,255,255);
   FastLED.show();
   delay(50);
}
