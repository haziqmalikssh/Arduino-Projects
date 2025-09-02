/*
   AD8232 ECG Heart Rate Monitor with Arduino
   GND     -> GND
   3.3V    -> 3.3V
   OUTPUT  -> A0
   LO+     -> 11
   LO-     -> 10
*/

int ecgPin = A0;   // ECG analog output
int loPlus = 11;   // Leads-off detection LO+
int loMinus = 10;  // Leads-off detection LO-

void setup() {
  Serial.begin(9600);

  pinMode(loPlus, INPUT);
  pinMode(loMinus, INPUT);

  Serial.println("AD8232 ECG Module Initialized...");
  delay(2000);
}

void loop() {
  // Check for leads off
  if ((digitalRead(loPlus) == 1) || (digitalRead(loMinus) == 1)) {
    Serial.println("Leads off! Check electrode connection.");
  } else {
    // Read analog ECG value
    int ecgValue = analogRead(ecgPin);
    Serial.println(ecgValue); // Open Tools > Serial Plotter to see waveform
  }

  delay(1); // Adjust sampling rate (lower for smoother plot)
}
