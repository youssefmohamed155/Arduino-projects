const int trigPin1 = 2;  // Trigger pin for sensor 1
const int echoPin1 = 3;  // Echo pin for sensor 1
const int trigPin2 = 4;  // Trigger pin for sensor 2
const int echoPin2 = 5;  // Echo pin for sensor 2
const int trigPin3 = 6;  // Trigger pin for sensor 3
const int echoPin3 = 7;  // Echo pin for sensor 3

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  // Read distance from sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  float distance1 = pulseIn(echoPin1, HIGH) / 58.0;

  // Read distance from sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  float distance2 = pulseIn(echoPin2, HIGH) / 58.0;

  // Read distance from sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  float distance3 = pulseIn(echoPin3, HIGH) / 58.0;

  // Print distance readings to Serial Monitor
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distance 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Distance 3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  delay(500);  // Wait for 500 milliseconds before reading again
}