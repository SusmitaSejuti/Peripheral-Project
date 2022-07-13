#include<Servo.h>
Servo motor;

int p=0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(4,OUTPUT);
  pinMode(4,INPUT);

  //pinMode(2,OUTPUT);
  pinMode(2,INPUT);


  motor.attach(3);
  motor.write(180);

  
  Serial.begin(9600);

}

void loop() 
  // put your main code here, to run repeatedly:
{
  if (digitalRead(3) == LOW)
  {
    //digitalWrite(13,HIGH);
for(p=0; p<90; p++){
    motor.write(p);
    delay(30);
  }
  for(p=90; p>=1; p--){
    motor.write(p);
    delay(30);
  }
  }

  else
  {
    
    //digitalWrite(13,LOW);
    delay(10);
  }


  if (digitalRead(2) == LOW)
  {
    //digitalWrite(12,HIGH);
    for(p=0; p<90; p++){
    motor.write(p);
    delay(30);
  }
  for(p=90; p>=1; p--){
    motor.write(p);
    delay(30);
  }
  }

  else
  {
    //digitalWrite(12,LOW);
    delay(10);
  }
}
