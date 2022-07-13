//final
#include <Servo.h> //includes the servo library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;

#define ir_enter 2
#define ir_back  6


int flag1 = 0, flag2 = 0;
int slot = 5;

void setup() {

  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  Serial.begin(9600);


  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  myservo.attach(3);
  myservo.write(0);

}

void loop() {
  lcd.setCursor (0, 0);
  lcd.print(" Total Slot: 5");
  lcd.setCursor (0, 1);
  lcd.print("  Empty Slot: ");
  lcd.print(slot);
  lcd.print("    ");

  if (digitalRead (ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) {
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(90);
        slot = slot - 1;
      }
    } else {
      lcd.setCursor (0, 1);
      lcd.print("Sorry Slot Full ");
      delay(1500);
    }
  }

  if (digitalRead (ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      if (slot < 5) {
        myservo.write(90);
        slot = slot + 1;
      }
      else{
        lcd.setCursor(0,1);
        lcd.print("NO Car inside");
      }
    }
  }

  if (flag1 == 1 && flag2 == 1) {
    delay (1000);
    myservo.write(0);
    flag1 = 0, flag2 = 0;
  }

}
/*
  // Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
  // Arduino 16x2 LCD I2C Scanner
  /*
  Analog Pin 4 - SDA
  Analog pin 5 - SCL
  5V  - Vcc
  GND - GND
*/
/*
  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>

  LiquidCrystal_I2C lcd(0x27,16,2);
  void setup()
  {
  lcd.init();
  Serial.begin(9600);
  lcd.backlight();
  }
  void loop()
  {
  lcd.clear();
  lcd.print("Robojax");
  lcd.setCursor(0,1);

  lcd.print("Hello");
  delay(5000);

  }
*/
