// Include NewPing library by Tim Eckel
#include <NewPing.h>
#include <FastLED.h>

// FastLED setup
#define DATA_PIN 9
#define NUM_LEDS 24

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
   FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
   FastLED.setBrightness(100);
   FastLED.clear();
}

void loop() {
  EVERY_N_MILLIS(50){
    // Get distance from sensor
    uint16_t distance = my_ultrasonic.ping_cm();
    
    // Discard garbage 0 numbers, which are not real readings
    if(distance > 0){
    
      // Constrain the number between 10 and 100
      distance = constrain(distance,10,100);
      
      // Map the distance to the blue value
      uint8_t blue = map(distance,10,100,0,255); 

      // Fill with a transition from blue to green
      fill_solid(leds, NUM_LEDS, CRGB(0,255-blue,blue));
      FastLED.show();
    } 
  }
}
