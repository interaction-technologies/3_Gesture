// Include NewPing library by Tim Eckel
#include <NewPing.h>

// Ultrasonic setup
#define TRIGGER_PIN  10  
#define ECHO_PIN     11  
#define MAX_DISTANCE 200

// Create a new ultrasonic sensor object
NewPing my_ultrasonic(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() { 
	Serial.begin(9600);
}

void loop() {
	// Get the distance from the sensor with ping_cm()
	uint16_t distance = my_ultrasonic.ping_cm();
	Serial.println(distance);
	delay(200);
}
