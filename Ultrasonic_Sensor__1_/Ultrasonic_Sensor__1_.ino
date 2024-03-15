#include <Servo.h>

const int Buzzer = 17;
const int trigPin = 18;
const int echoPin = 18;

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  myServo.attach(13); // Change the pin number to the appropriate pin for your ESP32 board

  pinMode(Buzzer, OUTPUT);
}

void loop() {

  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    distance = calculateDistance();

    if (distance < 40) {
      digitalWrite(Buzzer, HIGH);
    } else {
      digitalWrite(Buzzer, LOW);
    }

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    delay(50);
  }

  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    distance = calculateDistance();

    if (distance < 40) {

      digitalWrite(Buzzer, HIGH);
    } else {
      digitalWrite(Buzzer, LOW);
    }

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");

    delay(50);
  }
}

int calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}