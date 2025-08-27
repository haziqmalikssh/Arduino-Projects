#include <IRremote.h>
#include <Stepper.h>

// Pin definitions
#define IR_RECEIVER_PIN 5   // IR receiver VOUT connected to D5
#define IN1 8               // L298N IN1
#define IN2 9               // L298N IN2
#define IN3 10              // L298N IN3
#define IN4 11              // L298N IN4

// Stepper motor setup
const int stepsPerRevolution = 2048;  // Adjust according to your stepper
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

// IR setup
IRrecv irrecv(IR_RECEIVER_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start IR receiver
  myStepper.setSpeed(10); // RPM speed of the stepper motor
  Serial.println("IR Remote Stepper Control Ready");
}

void loop() {
  if (irrecv.decode(&results)) {
    long key = results.value;  // Store button value
    Serial.print("Key pressed: ");
    Serial.println(key, HEX);

    // Example button actions (replace HEX values with your remote’s codes)
    if (key == 0xFFA25D) {   // Forward button
      Serial.println("Moving Forward");
      myStepper.step(stepsPerRevolution / 4); // Move 1/4 revolution forward
    }
    else if (key == 0xFF629D) { // Backward button
      Serial.println("Moving Backward");
      myStepper.step(-stepsPerRevolution / 4); // Move 1/4 revolution backward
    }
    else if (key == 0xFFE21D) { // Stop button
      Serial.println("Stop");
      // Just don’t send steps -> stepper holds
    }

    irrecv.resume(); // Receive next value
  }
}
