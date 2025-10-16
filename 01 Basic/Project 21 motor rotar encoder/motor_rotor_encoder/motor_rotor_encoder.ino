#include <AccelStepper.h>

// Stepper Motor Pins (connected to IN1–IN4 of driver)
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Rotary Encoder Pins
#define CLK 2
#define DT 3
#define SW 4

// Stepper setup: 4 pins 
AccelStepper stepper(AccelStepper::FULL4WIRE, IN1, IN3, IN2, IN4);

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

int lastCLK = HIGH;
bool motorEnabled = true;

void setup() {
  // Encoder pins
  pinMode(CLK, INPUT_PULLUP);
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(CLK), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DT), updateEncoder, CHANGE);

  // Stepper configuration
  stepper.setMaxSpeed(800.0);
  stepper.setAcceleration(400.0);

  Serial.begin(9600);
  Serial.println("Stepper + Encoder Ready");
}

void loop() {
  // If button is pressed, toggle motor enable
  if (digitalRead(SW) == LOW) {
    motorEnabled = !motorEnabled;
    delay(300); // debounce
  }

  if (motorEnabled) {
    stepper.moveTo(encoderValue); //Move stepper based on encoder
    stepper.run();
  }
}

// Interrupt routine to read encoder
void updateEncoder() {
  int MSB = digitalRead(CLK); // Most Significant Bit
  int LSB = digitalRead(DT);  // Least Significant Bit

  int encoded = (MSB << 1) | LSB; //Converting the 2 pin value to a single number
  int sum = (lastEncoded << 2) | encoded;

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    encoderValue++;
  if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
    encoderValue--;

  lastEncoded = encoded;
}
