// Relay pin connected to Arduino
int relayPin = 7; 

void setup() {
  pinMode(relayPin, OUTPUT); // Set relay pin as output
  Serial.begin(9600);
}

void loop() {
  // Turn relay ON (energize coil, motor driver powered)
  digitalWrite(relayPin, HIGH);
  Serial.println("Relay ON - Motor driver powered");
  delay(5000); // wait 5 seconds

  // Turn relay OFF (de-energize coil, motor driver disconnected)
  digitalWrite(relayPin, LOW);
  Serial.println("Relay OFF - Motor driver disconnected");
  delay(5000); // wait 5 seconds
}
