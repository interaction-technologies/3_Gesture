#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create new sensor object
Adafruit_MPU6050 mpu;

float shake_limit = 13;   // Limit above which we consider acceleration to be abuse by user
float gravity = 10.51;    // Gravity, according to the sensor at least

void setup(void) {
	Serial.begin(9600);

	// Initialise the sensor and check if connected
	if (!mpu.begin()) {
		while(1){
			Serial.println("Failed to find MPU6050 chip");
			delay(500);
		}
	}
	mpu.setAccelerometerRange(MPU6050_RANGE_8_G); // Set accelerometer range to +/-8G
	mpu.setGyroRange(MPU6050_RANGE_500_DEG);      // Set gyroscope range to +/- 500 deg/s
	mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);   // Set filter bandwidth to 21Hz
	delay(100);
}

void loop() {

	// Get new sensor events with the readings
	sensors_event_t a, g, temp;
	mpu.getEvent(&a, &g, &temp);

	// Calculate overall magnitude of acceleration as square root of sum of squares
	float total_acceleration = sqrt( a.acceleration.x*a.acceleration.x + a.acceleration.y*a.acceleration.y + a.acceleration.z*a.acceleration.z);

	// Subtract reference and ignore sign (+/-)
	float shake_acceleration = abs(total_acceleration - gravity);

	Serial.print("Acceleration:");
	Serial.print(shake_acceleration);

	// Check if over threshold
	if(shake_acceleration > shake_limit){
		Serial.print(" ** ABUSE **");
	}

	Serial.println();

	delay(30);
}
