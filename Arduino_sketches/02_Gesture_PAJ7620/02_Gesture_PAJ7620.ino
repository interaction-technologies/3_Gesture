// Include DFRobot_PAJ7620U2 library by DFRobot
#include <DFRobot_PAJ7620U2.h>

// Sensor object
DFRobot_PAJ7620U2 paj;

void setup(){
	Serial.begin(9600);
	// Initialise sensor and check it is corrected
	while(paj.begin() != 0){
		Serial.println("PAJ7620U2 sensor not found!");
		delay(500);
	}

	// This mode detects 9 gestures: left, right, up, down, forward, backward, clockwise, anti-clockwise, wave
	paj.setGestureHighRate(true);
}

void loop(){   

	// Fetch latest gesture code
	DFRobot_PAJ7620U2::eGesture_t gesture_code = paj.getGesture();  

	// If we have a valid gesture
	if(gesture_code != paj.eGestureNone ){   

		//Convert gesture number into name
		String gesture_name  = paj.gestureDescription(gesture_code);  

		// Debug current gesture
		Serial.print("Gesture = [");
		Serial.print(gesture_code);
		Serial.print("] ");
		Serial.println(gesture_name);
	}
}
