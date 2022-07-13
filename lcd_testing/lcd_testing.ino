// Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
// Arduino 16x2 LCD I2C Scanner
/*
Analog Pin 4 - SDA
Analog pin 5 - SCL
5V  - Vcc
GND - GND
*/

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
