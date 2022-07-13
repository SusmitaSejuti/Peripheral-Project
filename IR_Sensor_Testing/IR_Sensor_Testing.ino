void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(3,INPUT);

  pinMode(12,OUTPUT);
  pinMode(2,INPUT);

  Serial.begin(9600);

}

void loop() 
  // put your main code here, to run repeatedly:
{
  if (digitalRead(3) == LOW)
  {
    digitalWrite(13,HIGH);

    delay(10);
  }

  else
  {
    digitalWrite(13,LOW);
    delay(10);
  }

  if (digitalRead(2) == LOW)
  {
    digitalWrite(12,HIGH);

    delay(10);
  }

  else
  {
    digitalWrite(12,LOW);
    delay(10);
  }
}
