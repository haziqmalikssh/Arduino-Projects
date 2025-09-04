#include <Servo.h>

Servo myServo;   // Create servo object

int servoPin = 28;  // Pin where the servo is connected

void setup() {
  myServo.attach(servoPin);  // Attach servo to pin
}

void loop() {
  // Sweep from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);     // Set servo position
    delay(15);              // Wait for servo to move
  }

  // Sweep back from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  }
}
