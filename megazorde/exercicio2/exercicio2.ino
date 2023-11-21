#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

int POT = A0;

void setup() {

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.setRGB(0, 0, 0);

}

void loop() {

  float pot = analogRead(POT);
  pot = pot * 5 / 1023;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(pot);
  if (pot < 3) {
    lcd.setRGB(48, 213, 200); //turquesa
  } else {
    lcd.setRGB(0, 255, 255); //ciano
  }
  delay(10);

}
