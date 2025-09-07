#include <SPI.h>
#include <MFRC522.h>

// Pin definitions
#define SS_PIN 53   // SDA -> Pin 53 on Mega
#define RST_PIN 5   // RST -> Pin 5

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void setup() {
  Serial.begin(9600); // Initialize serial communication
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card reader
  Serial.println("Place your RFID card/tag near the reader...");
}

void loop() {
  // Look for new RFID cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the RFID cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Print UID of the card
  Serial.print("Card UID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Print card type
  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
  Serial.print("Card type: ");
  Serial.println(mfrc522.PICC_GetTypeName(piccType));

  delay(1000); // Wait a bit before next read
}
