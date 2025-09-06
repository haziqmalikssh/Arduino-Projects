int ledPin = 13;  // LED on Pin 13 of Arduino
int pirPin = 7;   // Input for HC-S501 PIR sensor

int pirValue;     // Variable to store PIR reading

void setup() {
  pinMode(ledPin, OUTPUT);   // LED pin as output
  pinMode(pirPin, INPUT);    // PIR pin as input

  digitalWrite(ledPin, LOW); // Make sure LED is off at start

  Serial.begin(9600);        // Start Serial Monitor
  Serial.println("PIR Sensor Test Started");
}

void loop() {
  pirValue = digitalRead(pirPin);  // Read PIR sensor
  digitalWrite(ledPin, pirValue);  // Turn LED on/off based on PIR

  if (pirValue == HIGH) {
    Serial.println("Motion Detected!");
  } else {
    Serial.println("No Motion");
  }

  delay(500); // Wait half a second before reading again
}
