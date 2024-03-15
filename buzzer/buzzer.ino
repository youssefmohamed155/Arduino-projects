const int buzzerPin = 32;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn on the buzzer
  digitalWrite(buzzerPin, HIGH);
  delay(1000);  // Wait for 1 second
  
  // Turn off the buzzer
  digitalWrite(buzzerPin, LOW);
  delay(2000);  // Wait for 2 seconds
}
