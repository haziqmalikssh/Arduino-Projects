// Pin definitions
const int pinX = A0;   // Joystick X-axis (HORZ)
const int pinY = A1;   // Joystick Y-axis (VERT)
const int pinSW = 2;   // Joystick button (SEL)

void setup() {
  //start serial monitor
  Serial.begin(9600);

  // Configure joystick button pin
  pinMode(pinSW, INPUT_PULLUP); // Joystick button usually active LOW
}

void loop() {
  // Read X and Y values (range: 0–1023)
  int xValue = analogRead(pinX);
  int yValue = analogRead(pinY);

  // Read button state
  int swState = digitalRead(pinSW); // LOW = pressed, HIGH = not pressed

  // Print values to Serial Monitor
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.print(yValue);
  Serial.print(" | Button: ");
  if (swState == LOW) {
    Serial.println("Pressed");
  } else {
    Serial.println("Released");
  }

  delay(200); // Small delay for readability
}
