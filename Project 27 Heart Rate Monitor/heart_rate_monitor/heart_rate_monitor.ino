const int SENSOR_PIN = A0;  // Analog input for ECG signal
const int LO_POS_PIN = 10;  // Leads-off detect +
const int LO_NEG_PIN = 11;  // Leads-off detect -

void setup() {
  Serial.begin(9600);       // Initialize serial communication at 9600 baud
  pinMode(LO_POS_PIN, INPUT);
  pinMode(LO_NEG_PIN, INPUT);
}

void loop() {
  if ((digitalRead(LO_POS_PIN) == 1) || (digitalRead(LO_NEG_PIN) == 1)) {
    Serial.println('!');    // Leads are off
  } else {
    Serial.println(analogRead(SENSOR_PIN));  // Send raw ECG value
  }
  delay(1);                 // Delay for ~1000 Hz sampling
}