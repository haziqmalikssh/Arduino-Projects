#include "DHT.h"

// ----- Constants -----
#define DHTPIN 2        // Digital pin connected to DHT11 DATA
#define DHTTYPE DHT11   // Define sensor type

// ----- Objects -----
DHT dht(DHTPIN, DHTTYPE);

// ----- Setup -----
void setup() {
  Serial.begin(9600);
  Serial.println("Initializing DHT11 Sensor...");
  
  dht.begin();
  delay(2000);  // Give sensor time to stabilize
}

// ----- Main Loop -----
void loop() {
  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius
  float temperatureF = dht.readTemperature(true); // Fahrenheit

  // Check if reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Failed to read from DHT11 sensor!");
    delay(2000);
    return;
  }

  // Print results
  printSensorData(humidity, temperature, temperatureF);

  delay(2000); // Read every 2 seconds
}

void printSensorData(float humidity, float tempC, float tempF) {
  Serial.println("------ DHT11 Sensor Data ------");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" °C");

  Serial.print("Temperature: ");
  Serial.print(tempF);
  Serial.println(" °F");

  Serial.println("--------------------------------");
}
