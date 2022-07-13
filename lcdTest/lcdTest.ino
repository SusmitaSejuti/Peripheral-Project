
#include<LiquidCrystal.h>
int i=12;

LiquidCrystal lcd(5,6,7,8,9,10);

void setup() {
  lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(3,0);
}
