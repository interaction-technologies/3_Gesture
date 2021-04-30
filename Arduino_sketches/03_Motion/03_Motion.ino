#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create new sensor object
Adafruit_MPU6050 mpu;

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

  // Print out all the values
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");

  Serial.println("");
  delay(200);
}
