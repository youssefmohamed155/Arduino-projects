int motorA1 = 11;
int motorA2 = 10;
int motorB1 = 9;
int motorB2 = 6;




void setup() {
  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);

  digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);
/////////////////////////////////
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);
  
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);


  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(motorA1,HIGH);
  digitalWrite(motorA2,LOW);
  /////////
  digitalWrite(motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  delay(3000);
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,HIGH);
  /////////////////////////////
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  delay(3000);











  // put your main code here, to run repeatedly:

}
