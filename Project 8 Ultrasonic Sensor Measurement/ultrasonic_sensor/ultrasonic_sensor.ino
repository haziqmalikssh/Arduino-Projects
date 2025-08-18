/*
  Ultrasonic Sensor Module Project (HC-SR04 + Arduino)
*/

const int TRIG_PIN = 9;   // Arduino pin connected to HC-SR04 TRIG
const int ECHO_PIN = 10;  // Arduino pin connected to HC-SR04 ECHO

const unsigned int MAX_DISTANCE_CM = 400;  // sensor limit
const unsigned long TIMEOUT = MAX_DISTANCE_CM * 58; // convert to microseconds
// Function: measureDistance
// Returns: distance in cm, or -1 if out of range
long measureDistance() {
  // set triger to low
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send 10µs high pulse to trigger ultrasonic burst
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the length of time echo pin stays high
  unsigned long duration = pulseIn(ECHO_PIN, HIGH, TIMEOUT);

  // If no echo received, return -1
  if (duration == 0) {
    return -1;
  }

  // Calculate distance in cm
  long distanceCm = duration * 0.0343 / 2;
  return distanceCm;
}

//set up the the pin and serieal monitor
void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.println("Ultrasonic Sensor Module Initialized...");
  Serial.println("Measuring distance in cm:\n");
}
//loops through the measuring method and conditions
void loop() {
  long distance = measureDistance();

  if (distance == -1) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500); // half a second delay between readings
}
