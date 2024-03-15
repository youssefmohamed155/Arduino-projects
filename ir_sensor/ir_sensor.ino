int ir = A0;

int ur = HIGH;

void setup() 
{
  pinMode(ir,INPUT);
  Serial.begin(9600);

  





  // put your setup code here, to run once:

  }

void loop() {
  ur = digitalRead(ir);
  if (ur == LOW)
    {

      Serial.println("obs");
    }
  else 
    {
      Serial.println("ttt");
    }
  delay(200);
  












  // put your main code here, to run repeatedly:

}
