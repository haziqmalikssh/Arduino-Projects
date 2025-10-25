// Basic Heart Rate Monitor (Pulse Sensor) Example
// Connect: S -> A0, + -> 5V, - -> GND

int pulsePin = A0;      // Signal pin connected to A0
int signalValue = 0;    // Variable to store sensor reading

void setup() {
  Serial.begin(9600);   // Start the Serial Monitor
  pinMode(pulsePin, INPUT);
}

void loop() {
  signalValue = analogRead(pulsePin);  // Read analog value from sensor
  Serial.println(signalValue);         // Print to Serial Monitor
  delay(10);                           // Small delay for stability
}
