#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// GPS module TX -> Arduino pin 4
// GPS module RX -> Arduino pin 3
// Remember: Cross TX/RX
static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// Create GPS and serial objects
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);       // Serial Monitor
  gpsSerial.begin(GPSBaud);   // GPS module
  Serial.println(F("GPS Module Test - GY-NEO6MV2"));
}

void loop()
{
  // Check for GPS data
  while (gpsSerial.available() > 0)
  {
    gps.encode(gpsSerial.read());

    // If a valid location is found
    if (gps.location.isUpdated())
    {
      Serial.print(F("Latitude: "));
      Serial.println(gps.location.lat(), 6);

      Serial.print(F("Longitude: "));
      Serial.println(gps.location.lng(), 6);

      Serial.print(F("Satellites: "));
      Serial.println(gps.satellites.value());

      Serial.print(F("HDOP: "));
      Serial.println(gps.hdop.hdop());

      Serial.print(F("Altitude (meters): "));
      Serial.println(gps.altitude.meters());

      Serial.println(F("-------------------------"));
    }
  }
}
