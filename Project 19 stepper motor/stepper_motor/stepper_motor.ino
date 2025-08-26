#include <Stepper.h>

// Define number of steps per revolution for 28BYJ-48
#define STEPS_PER_REV 2048  

// Pin sequence based on your wiring (IN1 → IN4)
#define IN1 8   // Red
#define IN2 9   // Orange
#define IN3 10  // Yellow
#define IN4 11  // Pink

// Initialize stepper library
Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
  // Set stepper speed (RPM)
  stepper.setSpeed(10);  
}

void loop() {
  // Rotate one full revolution clockwise
  stepper.step(STEPS_PER_REV);
  delay(1000);

  // Rotate one full revolution counterclockwise
  stepper.step(-STEPS_PER_REV);
  delay(1000);
}
