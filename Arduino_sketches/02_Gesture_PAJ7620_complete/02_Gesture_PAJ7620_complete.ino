// Include DFRobot_PAJ7620U2 library by DFRobot
#include <DFRobot_PAJ7620U2.h>

// Include the Keyboard library
#include <Keyboard.h>

// Sensor object
DFRobot_PAJ7620U2 paj;

void setup(){

	// ⚠ Safety stop!
	// Program will not begin unless pin 12 connected to GND
	pinMode(12, INPUT_PULLUP);
	while(digitalRead(12)==HIGH){
		// do nothing!
		delay(500);
	}

	// Initialise sensor and check it is corrected
	while(paj.begin() != 0){
		delay(500);
	}

	// This mode detects 9 gestures: left, right, up, down, forward, backward, clockwise, anti-clockwise, wave
	paj.setGestureHighRate(true);

	// Start keyboard
	Keyboard.begin();
}

void loop(){   

	// Fetch latest gesture code
	DFRobot_PAJ7620U2::eGesture_t gesture_code = paj.getGesture();  

	// If we have a valid gesture
	if(gesture_code != paj.eGestureNone ){   

		if(gesture_code == 1){
			// Right
			Keyboard.write(KEY_RIGHT_ARROW);
		}else if(gesture_code == 2){
			// Left
			Keyboard.write(KEY_LEFT_ARROW);
		}
	}
}
