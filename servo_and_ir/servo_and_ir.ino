#include<Servo.h>
Servo motor;
int IR1 = 4; //entering sensor
int IR2 = 2; //exit sensor
int entered = 0;
int exited=0;
int Slot = 5;

void setup() {
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);


  motor.attach(3);
  motor.write(0);


  Serial.begin(9600);

}

void loop()
// put your main code here, to run repeatedly:
{
  //this portion is for entering into garage with slots
  if (digitalRead (IR1) == LOW && exited!=1) {
    if(Slot>0){
      motor.write(90);
      entered = 1;
      digitalWrite(10, LOW);
    }
    else{
      digitalWrite(10,HIGH);
    }
  }
  if (digitalRead (IR2) == LOW && entered == 1) {
    digitalWrite(10, LOW);
    motor.write(0);
    Slot = Slot - 1;
    entered=0;
  }
  //entered into garage

  
  /*
  if (digitalRead (IR2) == LOW  && entered!=1) { //exiting from garage
    motor.write(90);
    exited = 1;
    digitalWrite(10,LOW);
  }

  if (digitalRead (IR1) == LOW && exited ==1) {
    motor.write(0);
    Slot = Slot + 1;
    exited=0;
  }
  */
}
