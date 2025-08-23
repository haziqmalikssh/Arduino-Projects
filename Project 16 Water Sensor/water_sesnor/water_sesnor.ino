// Water Level Sensor with Arduino Mega 2560
// Connected to analog pin A0

const int waterSensorPin = A0;  // Sensor OUT → A0
int waterLevelValue = 0;        // Variable to store sensor reading

void setup() {
  Serial.begin(9600);           // Start serial communication
  pinMode(waterSensorPin, INPUT);
  Serial.println("Water Level Sensor Initialized...");
}

void loop() {
  // Read analog value from sensor (0 - 1023)
  waterLevelValue = analogRead(waterSensorPin);

  // Print value to Serial Monitor
  Serial.print("Water Level Value: ");
  Serial.println(waterLevelValue);

  // Optional: categorize water level
  if (waterLevelValue < 200) {
    Serial.println("Status: Empty / Dry");
  } else if (waterLevelValue < 500) {
    Serial.println("Status: Low Water");
  } else if (waterLevelValue < 800) {
    Serial.println("Status: Medium Water");
  } else {
    Serial.println("Status: High Water");
  }

  delay(1000);  // Delay 1 second before next reading
}
