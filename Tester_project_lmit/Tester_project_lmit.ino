
int ir =8;
int motorA1 = 11;
int motorA2 = 10;
int motorB1 = 9;
int motorB2 = 6;
/// esc = 13 ;
int limtA1 =12;
int limtA2 =2;
////
int f =0;
int f1 =0;
////
int ur = HIGH;
int f2 =0;
int a=1;
///////
char cmnd;


void setup() {

  pinMode(12,INPUT);
  pinMode(8,INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);


  Serial.begin(9600);

  digitalWrite(12, HIGH);

  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);


  

  // put your setup code here, to run once:

}

void loop() {

  if ((digitalRead(12)== LOW)&& (f==0))
  {
    Serial.println("OPPEN");


    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
f = 1 ;
delay(10) ;   
  }
    if ((digitalRead(12)== HIGH ) && (f==1))
  {
    
    Serial.println("oppen");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

  f = 0 ;
  delay(10) ; 
  }  

  if ( f == 1 )

      {
  
    digitalWrite(12, HIGH);
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
 
      }



  ///////////////////
  //////////////////


  if ((digitalRead(2)== LOW)&& (f1==0)){
    Serial.println("OPPEN");


    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, HIGH);
f1 = 1 ;
delay(10) ;   
  }
    if ((digitalRead(2)== HIGH ) && (f1==1))
  {
    
    Serial.println("oppen");
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2, LOW);

  f1 = 0 ;
  delay(10) ; 
  }  

  if ( f1 == 1 )

      {
  
    digitalWrite(2, HIGH);
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
 
      }  

   /////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////
  
  int ur = digitalRead(ir);

  if ((ur == HIGH)&&(f2==1))
    {
      Serial.println("ttt");
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
      
f2==1;
delay(10); 
    }
  
  if ((ur == LOW)&&(f2==0))
    {

      Serial.println("obs");

      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
  f2==0; 
  delay(10);
       
    }

  if ( f2 == 1 )

      {
  
    digitalWrite(8, LOW);
    digitalWrite(motorA1, HIGH);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);
    digitalWrite(motorB2, LOW);
 
      }  
delay(100);      

//////////////

//   if (((digitalRead(2)== HIGH) || (digitalRead(12)== HIGH) ||(ur == LOW)) && ((f==0))) //||(f1==0)
//   {
//     Serial.println("OPPEN");


//     digitalWrite(motorA1, HIGH);
//     digitalWrite(motorA2, LOW);
//     digitalWrite(motorB1, LOW);
//     digitalWrite(motorB2, HIGH);
// f = 1 ;    
// //f1 = 1 ;
// delay(10) ;   
//   }
//     if (((digitalRead(2)== LOW )|| (digitalRead(12)== LOW) || (ur == HIGH)) && ((f==1) )) ///|| (f1==1)
//   {
    
//     Serial.println("oppen");
//     digitalWrite(motorA1, LOW);
//     digitalWrite(motorA2, HIGH);
//     digitalWrite(motorB1, HIGH);
//     digitalWrite(motorB2, LOW);

//   f = 0 ; 
//  // f1 = 0 ;
//   delay(100) ; 
//   }  

//   if (  ( f == 1 )) ///( f1 == 1 ) ||

//       {

//     digitalWrite(8, LOW);
//     digitalWrite(2, HIGH);
//     digitalWrite(12, HIGH);
//     digitalWrite(motorA1, HIGH);
//     digitalWrite(motorA2, LOW);
//     digitalWrite(motorB1, LOW);
//     digitalWrite(motorB2, LOW);
 
//       }  




  /////////
  ////////////////////////////////////////////




  while(Serial.available() > 0)

 {
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
  cmnd = Serial.read();
  Serial.println(cmnd);

  
if( cmnd == 'F') // Forward
    {
      digitalWrite(9, HIGH);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);  
    }
  else if(cmnd == 'B') // Backward
    {
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH); 
    }
  
    else if(cmnd == 'R') //Right
    {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    }
    else if(cmnd == 'L') //Left
    {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH); 
    }
    else if(cmnd == 'I') //Forward Right
    {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
  else if(cmnd == 'J') //Backward Right
    {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    }
   else if(cmnd == 'G') //Forward Left
    {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);  
    digitalWrite(12, LOW);
    }
  else if(cmnd == 'H') //Backward Left
    {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH); 
    }}









  // put your main code here, to run repeatedly:

}
