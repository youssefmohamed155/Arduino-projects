#include <MFRC522.h>

#define RST_PIN         22          // Reset pin
#define SS_PIN          5          // Slave select pin
#define LED_PIN         2           // LED pin
#define BUZZER_PIN      4           // Buzzer pin

MFRC522 mfrc522(SS_PIN, RST_PIN);    // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  SPI.begin();                      // Initialize SPI bus
  mfrc522.PCD_Init();               // Initialize MFRC522
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String cardUID = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardUID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      cardUID += String(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println("Card UID: " + cardUID);

    // Check if card UID matches a student's UID in the database
    if (cardUID == "XXXXXXXXXX") {  // Replace XXXXXXXXXX with student's UID
      // Log attendance and indicate success
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1000);
      delay(100);
      noTone(BUZZER_PIN);
      digitalWrite(LED_PIN, LOW);
    } else {
      // Indicate failure
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 500);
      delay(500);
      noTone(BUZZER_PIN);
      digitalWrite(LED_PIN, LOW);
    }
  }
}