int limt = 10 ;
int limt2 = 7 ;
int led = 2 ;


int foge =0;
int foge2 =0;
int foge1 =0;



void setup() {
  pinMode(10,INPUT);
  pinMode(7,INPUT);
  pinMode(2,OUTPUT);


  digitalWrite(2, LOW);
  Serial.begin(9600);


  // put your setup code here, to run once:


}

void loop() 
{


//////================================
  if ((digitalRead(7)== LOW ) && (foge==0))
  {
    
    Serial.println("closed");
    digitalWrite(2, LOW);
  
  foge2 = 1 ;
  // delay(10) ; 
  }
    if ((digitalRead(7)== HIGH ) && (foge2==1))
  {
    
    Serial.println("oppen");
    digitalWrite(2, HIGH);

  foge2 = 0 ;
  // delay(10) ; 
  }
    if ( foge2 == 1 )

      {
  
    digitalWrite(7, HIGH);
    digitalWrite(2, LOW); 
 
      }



//////================================
  if ((digitalRead(10)== LOW ) && (foge==0))
  {
    
    Serial.println("closed");
    digitalWrite(2, LOW);
  
  foge1 = 1 ;
  // delay(10) ; 
  }
    if ((digitalRead(7)== HIGH ) && (foge1==1))
  {
    
    Serial.println("oppen");
    digitalWrite(2, HIGH);

  foge1 = 0 ;
  // delay(10) ; 
  }
    if ( foge1 == 1 )

      {
  
    digitalWrite(10, HIGH);
    digitalWrite(2, LOW); 
 
      }      







  
  // put your main code here, to run repeatedly:}
}
