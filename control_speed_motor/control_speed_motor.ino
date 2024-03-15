// int motorPin = 9;
// int speed = 0;

// void setup() {
//   pinMode(motorPin, OUTPUT);
// }

// void loop() {
//   // Increase speed gradually from 0 to 255
//   for (speed = 0; speed <= 255; speed++) {
//     analogWrite(motorPin, speed);
//     delay(10);
//   }



//---------------------------

int motorPinB1 = 9;   // PWM  speed control
int motorPinB2 = 10;  // Direction
int motorPinA1 = 11;  // PWM  speed control
int motorPinA2 = 12;  // Direction control 


void setup() {
  pinMode(motorPinA1, OUTPUT);
  pinMode(motorPinA2, OUTPUT);
//------
  pinMode(motorPinB1, OUTPUT);
  pinMode(motorPinB2, OUTPUT);  
}

void loop() {

 
    analogWrite(motorPinA1,90);   // Set PWM duty cycle
    digitalWrite(motorPinA2, LOW);    // Set direction (LOW = one direction)
    //---
    analogWrite(motorPinB1,90);   // Set PWM duty cycle
    digitalWrite(motorPinB2, LOW);    // Set direction (LOW = one direction)
    delay(2000);
//__________

    analogWrite(motorPinB1, 90);   // Set PWM duty cycle
    digitalWrite(motorPinB2, HIGH);   
    //--
    analogWrite(motorPinA1, 90);   // Set PWM duty cycle
    digitalWrite(motorPinA2, HIGH);  
    delay(2000);  
 
}