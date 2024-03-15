#include <SoftwareSerial.h> ///Hc  // Include the SoftwareSerial library for serial communication
// SoftwareSerial Myserial(9,10)  // Create a SoftwareSerial object named Myserial with pins 9 and 10
#include <Servo.h> ///servo  // Include the Servo library for controlling servo motors
Servo esc;  // Create a Servo object named esc

//---------------------
int trigPin1 = 2;  // Define the trigger pin for ultrasonic sensor 1
int echoPin1 = 3;  // Define the echo pin for ultrasonic sensor 1

int trigPin2 = 4;  // Define the trigger pin for ultrasonic sensor 2
int echoPin2 = 5;  // Define the echo pin for ultrasonic sensor 2

int trigPin3 = 7;  // Define the trigger pin for ultrasonic sensor 3
int echoPin3 = 6;  // Define the echo pin for ultrasonic sensor 3

//---------
long duration1;  // Variable to store the duration for ultrasonic sensor 1
long duration2;  // Variable to store the duration for ultrasonic sensor 2
long duration3;  // Variable to store the duration for ultrasonic sensor 3
int distanceleft;  // Variable to store the distance measured by ultrasonic sensor 1
int distancefront;  // Variable to store the distance measured by ultrasonic sensor 2
int distanceright;  // Variable to store the distance measured by ultrasonic sensor 3

//----------------------------
int irpin = 8;  // Define the pin for the infrared sensor
int s = HIGH ; /////  // Initialize a variable s with the value HIGH

//---------------------------------
int motorA1 = 12;  // Define the pin for motor A1
int motorA2 = 11;  // Define the pin for motor A2
int motorB1 = 10;  // Define the pin for motor B1
int motorB2 = 9;  // Define the pin for motor B2

//-----------------------------------

int a = 0;  // Initialize a variable a with the value 0
char cmnd;  // Declare a character variable named cmnd

void setup() {
  pinMode(trigPin1, OUTPUT);  // Set trigPin1 as an output
  pinMode(trigPin2, OUTPUT);  // Set trigPin2 as an output
  pinMode(trigPin3, OUTPUT);  // Set trigPin3 as an output
  pinMode(echoPin1, INPUT);  // Set echoPin1 as an input
  pinMode(echoPin2, INPUT);  // Set echoPin2 as an input
  pinMode(echoPin3, INPUT);  // Set echoPin3 as an input
  ///////////////
  pinMode(irpin, INPUT);  // Set irpin as an input
  //////////////
  pinMode(motorA1, OUTPUT);  // Set motorA1 as an output
  pinMode(motorA2, OUTPUT);  // Set motorA2 as an output
  pinMode(motorB1, OUTPUT);  // Set motorB1 as an output
  pinMode(motorB2, OUTPUT);  // Set motorB2 as an output
  //////////
  pinMode(A0, INPUT);  // Set pin A0 as an input
/////////////
  Serial.begin(9600);  // Initialize serial communication at 9600 baud rate
  esc.attach(13, 1000, 2000);  ////  // Attach the esc servo to pin 13 with pulse width limits of 1000 and 2000
  ///esc.writeMicroseconds(1000);  // Write a pulse width of 1000 microseconds to the esc
  delay(2000);  // Delay for 2000 milliseconds
}


void loop() {


/////////
int motor = analogRead(A0);  /// Read the analog input from pin A0 and store it in the variable motor
motor = map(motor, 0, 1023, 0, 180);/// Map the motor value from the range 0-1023 to the range 0-180
esc.writeMicroseconds(motor);/// Write the mapped motor value as microseconds to the esc servo

////////////
digitalWrite(trigPin1, LOW);  // Set the trigger pin for ultrasonic sensor 1 to low
delayMicroseconds(2);  // Delay for 2 microseconds
digitalWrite(trigPin1, HIGH);  // Set the trigger pin for ultrasonic sensor 1 to high
delayMicroseconds(4);  // Delay for 4 microseconds
digitalWrite(trigPin1, LOW);  // Set the trigger pin for ultrasonic sensor 1 to low
duration1 = pulseIn(echoPin1, HIGH);  // Measure the duration of the pulse from the echo pin of ultrasonic sensor 1
distanceleft = duration1 / 58;  // Calculate the distance measured by ultrasonic sensor 1
Serial.print("Distance1: ");  // Print the label "Distance1: " to the serial monitor
Serial.println(distanceleft);  // Print the distance measured by ultrasonic sensor 1 to the serial monitor
delay(200);  // Delay for 200 milliseconds
//-------

// Similar operations for ultrasonic sensor 2 and 3

int s = digitalRead(irpin);  // Read the digital input from the infrared sensor and store it in the variable s
//-----------

int val; 
val = analogRead(A0);  // Read the analog input from pin A0 and store it in the variable val
val = map(val, 0, 1023, 1000, 2000);  // Map the val value from the range 0-1023 to the range 1000-2000
esc.writeMicroseconds(val);  // Write the mapped val value as microseconds to the esc servo
//-----------------------

// Conditional statements for controlling the motor based on sensor readings and input values

while (Serial.available() > 0)  // Check if there are any available serial data
{
  digitalWrite(motorA1, LOW);  // Set motorA1 pin to low
  digitalWrite(motorA2, LOW);  // Set motorA2 pin to low
  digitalWrite(motorB1, LOW);  // Set motorB1 pin to low
  digitalWrite(motorB2, LOW);  // Set motorB2 pin to low
  
  cmnd = Serial.read();  // Read the serial data and store it in the variable cmnd
  Serial.println(cmnd);  // Print the serial data to the serial monitor
}

  
if( cmnd == 'F') // Forward
    {
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);  
    }
  else if(cmnd == 'B') // Backward
    {
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH); 
    }
  
    else if(cmnd == 'R') //Right
    {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);
    }
    else if(cmnd == 'L') //Left
    {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH); 
    }
    else if(cmnd == 'I') //Forward Right
    {
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    }
  else if(cmnd == 'J') //Backward Right
    {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
    }
   else if(cmnd == 'G') //Forward Left
    {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);  
    digitalWrite(motorB2, LOW);
    }
  else if(cmnd == 'H') //Backward Left
    {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH); 
    }}}
   
