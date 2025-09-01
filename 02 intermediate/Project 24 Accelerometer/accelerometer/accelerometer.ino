#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing MPU6050...");

  mpu.initialize();

  // Check connection
  if (mpu.testConnection()) {
    Serial.println("MPU6050 connection successful!");
  } else {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  // Read accelerometer and gyroscope values
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("Accel (X/Y/Z): ");
  Serial.print(ax); Serial.print(" / ");
  Serial.print(ay); Serial.print(" / ");
  Serial.print(az);
  
  Serial.print(" | Gyro (X/Y/Z): ");
  Serial.print(gx); Serial.print(" / ");
  Serial.print(gy); Serial.print(" / ");
  Serial.println(gz);

  delay(500);
}
