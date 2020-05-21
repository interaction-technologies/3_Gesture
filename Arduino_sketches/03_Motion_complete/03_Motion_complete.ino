#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create new sensor object
Adafruit_MPU6050 mpu;

void setup(void) {
   mpu.begin();                                  // Initialise the sensor
   mpu.setAccelerometerRange(MPU6050_RANGE_8_G); // Set accelerometer range to +/-8G
   mpu.setGyroRange(MPU6050_RANGE_500_DEG);      // Set gyroscope range to +/- 500 deg/s
   mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);   // Set filter bandwidth to 21Hz
   delay(100);
}

// Threshold for detecting when fully flipped
// g = approx 9.8
double threshold = 7;

void loop() {

   // Get new sensor events with the readings
   sensors_event_t a, g, temp;
   mpu.getEvent(&a, &g, &temp);

   // Check which acceleration is beyond the threshold to calculate the side
   if(a.acceleration.z > threshold){
      Serial.println("Top");
   }else if(a.acceleration.z < -threshold){
      Serial.println("Bottom");
   }else if(a.acceleration.x > threshold){
      Serial.println("Left side");
   }else if(a.acceleration.x < -threshold){
      Serial.println("Right side");
   }else if(a.acceleration.y > threshold){
      Serial.println("Front side");
   }else if(a.acceleration.y < -threshold){
      Serial.println("Back side");
   }
   delay(200);
}
