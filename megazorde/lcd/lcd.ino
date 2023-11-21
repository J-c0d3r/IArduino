#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;


void setup() {

  lcd.begin(16, 2);
  lcd.setRGB(0,255,255);

  lcd.setCursor(0,0);
  lcd.print("12345678901010");
  lcd.setCursor(0,1);
  lcd.print("teste");
  delay(1000);

}

void loop() {

  //lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);
  //delay(100);

}
