// Pin to connect tilt switch to
#define TILT_PIN 5

void setup() { 
	Serial.begin(9600);

	// Declare tilt switch pin like a normal button
	pinMode(TILT_PIN, INPUT_PULLUP);
}

void loop() {
	// Tilt-switch turns "off" when it is upside down
	if(digitalRead(TILT_PIN) == HIGH){
		Serial.println("UPSIDE DOWN");
	}else{
		Serial.println("NORMAL");
	}
	delay(200);
}
