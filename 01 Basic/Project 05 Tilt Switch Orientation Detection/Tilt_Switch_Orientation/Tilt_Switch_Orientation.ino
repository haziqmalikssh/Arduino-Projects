// Pin assignment
const int tiltPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT_PULLUP); 
}

void loop() {
  int tiltState = digitalRead(tiltPin);

  if (tiltState == LOW) {
    // swith is in the closwer posistion
    Serial.println("Tilt switch is closed (tilted)");
  } else {
    // Switch in upright position
    Serial.println("Tilt switch is open (upright)");
  }

  delay(200); 
}
