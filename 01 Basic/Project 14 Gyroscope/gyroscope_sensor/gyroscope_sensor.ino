#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  //set rate and serial monitor
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  // Check if connected to module
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful!");
  } else {
    Serial.println("MPU6050 connection failed.");
    while (1);
  }
}

void loop() {
  // Variables to store raw data
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read accelerometer and gyroscope values
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Print results
  Serial.print("Accel (X,Y,Z): ");
  Serial.print(ax); Serial.print(" , ");
  Serial.print(ay); Serial.print(" , ");
  Serial.println(az);

  Serial.print("Gyro (X,Y,Z): ");
  Serial.print(gx); Serial.print(" , ");
  Serial.print(gy); Serial.print(" , ");
  Serial.println(gz);

  Serial.println("------------------------");
  delay(500);
}
