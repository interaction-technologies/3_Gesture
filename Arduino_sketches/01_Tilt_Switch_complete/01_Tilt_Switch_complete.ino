#include <FastLED.h>
#include <Bounce2.h>

// FastLED setup
#define DATA_PIN 9
#define NUM_LEDS 24

// Pin to connect tilt switch to
#define TILT_PIN 5

// Array of led data
CRGB leds[NUM_LEDS];

// Variable to save if upside down or not
bool is_upside_down = false;

void setup() { 
	// Setup Neopixel strip
	FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(100);
	FastLED.clear();

	// Declare tilt switch pin like a normal button
	pinMode(TILT_PIN, INPUT_PULLUP);
}

void loop() {
	// Checking every 50ms is a cheap way of "debouncing" the tilt switch
	EVERY_N_MILLIS(50){
		// Tilt-switch turns "off" when it is upside down
		if(digitalRead(TILT_PIN) == HIGH){
			is_upside_down = true;
		}else{
			is_upside_down = false;
		}
	}

	EVERY_N_MILLIS(10){
		if(is_upside_down){
			// beatsin8() is clever function that returns a number that varies
			// like a sin wave, x times per second (x=60 below)
			// We add a minimum=50 and max=255 to get a nice wave effect
			fill_solid(leds, NUM_LEDS, CRGB(beatsin8(60,50,255),0,0));  
		}else{
			fill_solid(leds, NUM_LEDS, CRGB::White);
		}
		FastLED.show();
	}
}