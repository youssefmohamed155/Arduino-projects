#include <Servo.h> ///servo 
Servo esc; 

void setup() {
  // put your setup code here, to run once:
  
  esc.attach(9,1000,2000);
  pinMode(A0, INPUT); 


}

void loop() {
  int val= analogRead(A0); 
  val= map(val, 0, 1023,0,180);
  esc.write(val);





  // put your main code here, to run repeatedly:

}
