// Pin assignment
const int tiltPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT_PULLUP); // Use internal pull-up resistor
}

void loop() {
  int tiltState = digitalRead(tiltPin);

  if (tiltState == LOW) {
    // Switch closed (tilted position)
    Serial.println("Tilt switch is closed (tilted)");
  } else {
    // Switch open (upright position)
    Serial.println("Tilt switch is open (upright)");
  }

  delay(200); // Small delay for stability
}
